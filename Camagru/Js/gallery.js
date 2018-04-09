document.querySelector('#more_pictures').addEventListener('click', function(ev)
{
	var nb_pics = document.querySelectorAll('.pics').length,
	request = new XMLHttpRequest();

	nb_pics = encodeURIComponent(nb_pics);
	request.addEventListener('readystatechange', function()
	{
		if (request.readyState === XMLHttpRequest.DONE)
		{
			if (request.status === 200)
			{
				main = document.getElementsByTagName('MAIN');
				main[0].innerHTML += request.responseText;
				main[0].style.overflow = "auto";
			}
		}
	});
	request.open ('POST', 'load_pictures.php');
	request.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
	request.send('nb_pics=' + nb_pics);
});

function add_com(balise)
{
	var request = new XMLHttpRequest(),
	com = balise.parentNode.parentNode.querySelector('#comment'),
	input = balise.parentNode.querySelector('.input'),
	src = balise.parentNode.parentNode.querySelector('.pics').src,
	i = 0;
	if (input.value.length > 255 || input.value.length < 1)
	{
		if (input.value.length > 255)
			alert("Your message is too long");
		return ;
	}
	while (src[i] !== 'P')
		i++;
	value = encodeURIComponent(input.value);
	path = encodeURIComponent(src.substr(i));
	request.addEventListener('readystatechange', function()
	{
		if (request.readyState === XMLHttpRequest.DONE)
		{
			if (request.status === 200)
			{
				data = escape_char(request.responseText);
				com.innerHTML += '<P class="com">- ' + data + '</P></BR>';
				input.value = null;
			}
		}
	});
	request.open ('POST', 'add_comment.php');
	request.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
	request.send('com=' + value + '&path=' + path);
}


function escape_char(str)
{
	var i = 0;

	str = str.replace(/&/g, "&amp;");
	str = str.replace(/>/g, "&gt;");
	str = str.replace(/</g, "&lt;");
	str = str.replace(/"/g, "&quot;");
	str = str.replace(/'/g, "&#039;");
	return (str);
}

function delete_img(balise)
{
	var request = new XMLHttpRequest(),
	src = balise.parentNode.parentNode.querySelector('.pics').src,
	nb_pics = document.querySelectorAll('.pics').length,
	i = 0;
	while (src[i] !== 'P')
		i++;
	path = encodeURIComponent(src.substr(i));
	request.addEventListener('readystatechange', function()
	{
		if (request.readyState === XMLHttpRequest.DONE)
		{
			if (request.status === 200)
			{
				balise.parentNode.parentNode.remove();
				main = document.getElementsByTagName('MAIN');
				main[0].innerHTML += request.responseText;
			}
		}
	});
	request.open ('POST', 'delete_picture.php');
	request.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
	request.send('path=' + path + '&nb_pics=' + nb_pics);
}

function like_img(balise)
{
	var request = new XMLHttpRequest();
	src = balise.parentNode.parentNode.querySelector('.pics').src;
	i = 0;
	while (src[i] !== 'P')
		i++;
	path = encodeURIComponent(src.substr(i));
	request.addEventListener('readystatechange', function()
	{
		if (request.readyState === XMLHttpRequest.DONE)
		{
			if (request.status === 200)
				balise.parentNode.querySelector('.nb_likes').innerHTML = request.responseText;
		}
	});
	request.open ('POST', 'like_picture.php');
	request.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
	request.send('path=' + path);
}
