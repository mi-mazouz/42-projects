function reset_password()
{
	var div = document.querySelector('#forms'),
	reset = document.getElementById('reset'),
	form = document.querySelector('.forms'),
	msg_reset = document.querySelector('#msg_reset');

	form.style.display = "none";
	msg_reset.style.display = "none";
	reset.style.display = "table-caption";
	div.style.marginBottom = "160px";
}

function return_reset()
{
	var div = document.getElementById('forms'),
	reset = document.getElementById('reset'),
	form = document.querySelector('.forms'),
	msg_signin = document.getElementById('msg_signin'),
	msg_register = document.getElementById('msg_register');

	reset.style.display = "none";
	form.style.display = "table-caption";
	div.style.marginBottom = "25px";
	msg_hide(msg_signin, msg_register, div);
}

function change_pwd()
{
	var webcam = document.getElementById('webcam'),
	form = document.getElementById('form');

	webcam.style.display = "none";
	form.style.display = "block";
}

function return_change_pwd()
{
	var webcam = document.getElementById('webcam'),
	msg_change = document.getElementById('msg_change'),
	form = document.getElementById('form');

	webcam.style.display = "block";
	msg_change.style.display = "none";
	form.style.display = "none";
}
