const video = document.querySelector('video')
let stream = null

navigator.mediaDevices.getUserMedia({ video: { facingMode: 'user' }, audio: false})
.then((result) => {
	const loader = document.querySelector('loader')
	if (!video || !loader) return

	stream = result
	HTMLMediaElement.srcObject = stream
	video.srcObject = HTMLMediaElement.srcObject
	video.play()
	.then(() => loader.remove())
})
.catch(() => {
	const loader = document.querySelector('loader')
	const uploadedImg = document.querySelector('#uploadedImg')
	if (!uploadedImg || !loader) return

	video.remove()
	loader.remove()
	stream = null
	uploadedImg.style.display = 'block'
	uploadedImg.src = './assets/default.png'
})

function uploadFile () {
	const file = event.target.files[0]
	const type = event.target.files[0].type
	const image = document.querySelector('#uploadedImg')

	if (!type || !file) return
	if (type !== 'image/png' && type !== 'image/jpeg' && type !== 'image/jpg') return
	if (stream && video) {
		stream.getTracks()[0].stop()
		video.remove()
	}

	reader = new FileReader()
	reader.addEventListener('load', () => {
		image.src = event.currentTarget.result
	})
	reader.readAsDataURL(file)
}

function takePicture () {
	const canvas = document.createElement('canvas')
	const picturesList = document.querySelector('#picturesList')
	const selectedImg = document.querySelector('#selectedImg')
	const uploadedImg = document.querySelector('#uploadedImg')

	if (!canvas || !selectedImg || !picturesList || !uploadedImg) return

	canvas.setAttribute('width', video.offsetWidth || uploadedImg.offsetWidth)
	canvas.setAttribute('height', video.offsetHeight || uploadedImg.offsetHeight)
	
	if (uploadedImg.src) canvas.getContext('2d').drawImage(uploadedImg, 0, 0, uploadedImg.offsetWidth, uploadedImg.offsetHeight)
	else {
		const pictureContext = canvas.getContext('2d')

		pictureContext.scale(-1, 1)
		pictureContext.drawImage(video, video.offsetWidth * -1, 0, video.offsetWidth, video.offsetHeight)
	}
	const picture = canvas.toDataURL('image/png').split(',')[1]
	
	canvas.setAttribute('width', selectedImg.width)
	canvas.setAttribute('height', selectedImg.height)
	canvas.getContext('2d').drawImage(selectedImg, 0, 0, selectedImg.width, selectedImg.height)
	const stackableImage = canvas.toDataURL('image/png').split(',')[1]

	const request = new XMLHttpRequest()
	request.addEventListener('readystatechange', () => {
		if (request.readyState === XMLHttpRequest.DONE) {
			if (request.status === 200) {
				picturesList.innerHTML = `
				<div class="column is-12">
						<img src="/images/${request.statusText}.jpeg">
				</div>` + picturesList.innerHTML;
			}
		}
	})
	request.open ('POST', './controller.php')
	request.setRequestHeader('Content-Type', 'application/x-www-form-urlencoded');
	request.send('stackableImage=' + stackableImage + '&picture=' + picture)
}

function onClick (image) {
	const stackableImage = document.querySelector('#selectedImg')
	const takePicture = document.querySelector('#takePicture')

	if (!stackableImage || !takePicture) return
	stackableImage.src = image.src
	takePicture.disabled = false
}