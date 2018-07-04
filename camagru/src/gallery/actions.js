function loadMorePictures() {
	const submitButton = document.querySelector('#submitButton')
	const pictureNumber = document.getElementsByClassName('is-card-container').length
	const articleSection = document.getElementById('articleSection')
	
	if (!articleSection) return

	submitButton.classList.add('is-loading')
	request = new XMLHttpRequest()
	request.addEventListener('readystatechange', ()=>{
		if (request.readyState === XMLHttpRequest.DONE){
			if (request.status === 200) articleSection.innerHTML += request.responseText
			else handleError(request.status, request.statusText)
			submitButton.classList.remove('is-loading')
		}
	})
	request.open ('POST', './load-more-pictures/controller.php')
	request.setRequestHeader('Content-Type', 'application/x-www-form-urlencoded')
	request.send('pictureNumber=' + pictureNumber)
}

function postLike(pictureId) {
	const likes = document.querySelector(`#likes-${pictureId}`)
	const likeIcon = document.querySelector(`#likeIcon-${pictureId}`)
	if (!likes || !likeIcon) return

  const request = new XMLHttpRequest();
	request.addEventListener('readystatechange', () => {
		if (request.readyState === XMLHttpRequest.DONE) {
			if (request.status === 200) {
				likes.innerHTML = request.statusText
				
				if (likeIcon.classList.contains('has-text-link')) likeIcon.classList.remove('has-text-link')
				else likeIcon.classList.add('has-text-link')
			}
		}
	});
	request.open ('POST', './like/controller.php');
	request.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
	request.send('pictureId=' + pictureId);
}

function deletePicture(pictureId) {
	const picture = document.querySelector(`#picture-${pictureId}`)
  if (!picture) return

  const request = new XMLHttpRequest();
	request.addEventListener('readystatechange', () => {
		if (request.readyState === XMLHttpRequest.DONE) {
			if (request.status === 200) {
				picture.remove();
			}
		}
	});
	request.open ('POST', './delete/controller.php');
	request.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
	request.send('pictureId=' + pictureId);
}

function postComment(pictureId, username) {
	const comment = document.querySelector(`#comment-${pictureId}`)
	const commentContainer = document.querySelector(`#commentContainer-${pictureId}`)
  if (!comment || !commentContainer || comment.value.length === 0 || comment.value.length > 255) return
	
  const escapedComment = encodeURIComponent(escapeChar(comment.value))
  const request = new XMLHttpRequest()
	request.addEventListener('readystatechange', () => {
		if (request.readyState === XMLHttpRequest.DONE) {
			commentContainer.innerHTML += `<article class="media">
                                  		<div class="media-content">
																				<p>
																					<strong>${username}</strong>
																				</p>
																				<p>
																					${request.responseText}
																				</p>
                                  		</div>
																			<div class="media-right">
																				<button class="delete"></button>
																			</div>
																		</article>`
		}
		comment.value = null
	})
	request.open ('POST', './comment/controller.php')
	request.setRequestHeader('Content-Type', 'application/x-www-form-urlencoded');
  request.send('comment=' + escapedComment + '&pictureId=' + pictureId)
}
