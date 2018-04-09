(function()
{
	streaming = false;
	var video = document.querySelector('#video'),
		canvas = document.querySelector('#canvas'),
		startbutton = document.querySelector('#startbutton'),
		pics_list = document.querySelector('#pics_list'),
		width = 480,
		height = 360;

	navigator.getMedia = (navigator.getUserMedia ||
							navigator.webkitGetUserMedia ||
							navigator.mozGetUserMedia ||
							navigator.msGetUserMedia);
	navigator.getMedia(
	{
		video: true,
		audio: false
	},
	function(stream)
	{
		if (navigator.mozGetUserMedia)
			video.mozSrcObject = stream;
		else
		{
			var vendorURL = window.URL || window.webkitURL;
			video.src = vendorURL.createObjectURL(stream);
		}
		video.play();
	},
	function(err)
	{
		console.log("An error occured! " + err);
	}
	);
	video.addEventListener('canplay', function(ev)
	{
		if (!streaming)
		{
			height = video.videoHeight / (video.videoWidth/width);
			video.setAttribute('width', width);
			video.setAttribute('height', height);
			canvas.setAttribute('width', width);
			canvas.setAttribute('height', height);
			streaming = true;
		}
	}, false);
	startbutton.addEventListener('click', function(ev)
	{
		if (!(document.querySelector('#superpose_img').src))
			return ;
		if (streaming !== false)
			takepicture();
		else
			treat_picture(document.querySelector('#upload_img').src);
		ev.preventDefault();
	}, false);
	function takepicture()
	{
		canvas.width = width;
		canvas.height = height;
		canvas.getContext('2d').drawImage(video, 0, 0, width, height);
		var img = canvas.toDataURL('image/png');
		treat_picture(img);
	}
	function treat_picture(pics)
	{
		var request = new XMLHttpRequest(),
		src = document.querySelector('#superpose_img').src,
		i = 0;
		while (src[i] !== 'P')
			i++;
		src = src.substr(i);
		pics = encodeURIComponent(pics);
		src = encodeURIComponent(src);
		request.addEventListener('readystatechange', function()
		{
			if (request.readyState === XMLHttpRequest.DONE)
			{
				if (request.status === 200)
				{
					var path = request.responseText;
					i = 0;
					if (no_pics = document.getElementById('no_pics'))
					{
						pics_list.removeChild(no_pics);
						pics_list.innerHTML = '<IMG class="pics" src="'+path+'"/>' + pics_list.innerHTML;
					}
					else
						pics_list.innerHTML = '<IMG class="pics" src="'+path+'"/>' + pics_list.innerHTML;
				}
			}
		});
		request.open ('POST', 'take_picture.php');
		request.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
		request.send('pics=' + pics + '&src=' + src);
	}
})();

document.querySelector('#file').addEventListener('change', function(ev)
{
	var name_file = this.files[0].name.split('.')
	length_file = name_file.length,
	upload_img = document.querySelector('#upload_img'),
	video = document.querySelector('#video');

	switch (name_file[length_file - 1])
	{
		case "jpeg":
			break ;
		case "png":
			break ;
		case "jpg":
			break;
		default:
			return ;
	}
	reader = new FileReader();
	reader.addEventListener('load', function(ev)
	{
		upload_img.src = this.result;
		upload_img.style.width = "480px";
		upload_img.style.height = "360px";
		upload_img.style.display = "block";
		video.style.display = "none";
		streaming = false;
	});
	reader.readAsDataURL(this.files[0]);
});

function filter(balise)
{
	var	request = new XMLHttpRequest(),
	src = balise.src,
	img = document.querySelector('#superpose_img'),
	button = document.querySelector('#startbutton'),
	i = 0;

	if (streaming === false && !(document.querySelector('#upload_img').src))
		return ;
	while (src[i] != 'P')
		i++;
	src = src.substr(i);
	img.src = src;
	img.style.display = "block";
	img.style.position = "absolute";
	img.style.bottom = "41%";
	img.style.right = "37%";
	img.style.width = "20%";
	img.style.height = "20%";
	button.style.backgroundColor = "#45AEFF";
}
