function verif_change()
{
	var div = document.getElementById('form'),
	old_pwd = document.getElementById('old_pwd').value,
	new_pwd = document.getElementById('new_pwd').value,
	confirm_pwd = document.getElementById('confirm_pwd').value,
	msg_change = document.getElementById('msg_change');

	if (verif_pwd(confirm_pwd) === true && verif_pwd(new_pwd) === true && verif_pwd(old_pwd) === true)
	{
		var request = new XMLHttpRequest();
		confirm_pwd = encodeURIComponent(confirm_pwd);
		old_pwd = encodeURIComponent(old_pwd);
		new_pwd = encodeURIComponent(new_pwd);
		request.addEventListener('readystatechange', function()
		{
			if (request.readyState === XMLHttpRequest.DONE)
			{
				if (request.status === 200)
					msg_display_change(msg_change, "Change success");
				else if (request.status === 401)
					msg_display_change(msg_change, "Old password is invalid");
				else
					msg_display_change(msg_change, "New password and confirm password are not identical");
			}
		});
		request.open ('POST', 'change_password.php');
		request.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
		request.send('old_pwd=' + old_pwd + '&new_pwd=' + new_pwd + '&confirm_pwd=' + confirm_pwd);
	}
	else
		msg_display_change(msg_change, "One field is invalid");
}

function verif_reset()
{
	var div = document.getElementById('forms'),
	usr = document.getElementById('usr_reset').value.trim(),
	email = document.getElementById('email_reset').value.trim(),
	msg_reset = document.getElementById('msg_reset');

	if (verif_usr(usr) === true && verif_mail(email) === true)
	{
		var request = new XMLHttpRequest();
		usr = encodeURIComponent(usr);
		email = encodeURIComponent(email);
		request.addEventListener('readystatechange', function()
		{
			if (request.readyState === XMLHttpRequest.DONE)
			{
				if (request.status === 200)
					msg_display(msg_reset, null, "Password changed check your mail", div);
				else if (request.status === 401)
					msg_display(msg_reset, null, "Username or email is invalid", div);
				else if (request.status === 400)
					msg_display(msg_reset, null, "Error to sending email", div);
			}
		});
		request.open ('POST', 'reset_password.php');
		request.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
		request.send('usr=' + usr + '&email=' + email);
	}
	else
		msg_display(msg_reset, null, "One field is invalid", div);
}

function verif_register()
{
	var div = document.getElementById('forms'),
	usr = document.getElementById('usr_register').value.trim(),
	pwd = document.getElementById('pwd_register').value,
	email = document.getElementById('email_register').value.trim(),
	msg_signin = document.getElementById('msg_signin'),
	msg_register = document.getElementById('msg_register');

	if (verif_usr(usr) === true && verif_pwd(pwd) === true && verif_mail(email) === true)
	{
		var request = new XMLHttpRequest();
		usr = encodeURIComponent(usr);
		pwd = encodeURIComponent(pwd);
		email = encodeURIComponent(email);
		request.addEventListener('readystatechange', function()
		{
			if (request.readyState === XMLHttpRequest.DONE)
			{
				if (request.status === 200)
					msg_display(msg_register, msg_signin, "Check your mail for the validation", div);
				else if (request.status === 401)
					msg_display(msg_register, msg_signin, "Username or email exist", div);
				else
					msg_display(msg_register, msg_signin, "Error to sending email", div);
			}
		});
		request.open ('POST', 'registration.php');
		request.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
		request.send('usr=' + usr + '&pwd=' + pwd + '&email=' + email);
	}
	else
		msg_display(msg_register, msg_signin, "One field is invalid", div);
}

function verif_signin()
{
	var usr = document.getElementById('usr_signin').value.trim(),
	pwd = document.getElementById('pwd_signin').value,
	form = document.querySelector('.forms'),
	msg_signin = document.getElementById('msg_signin'),
	msg_register = document.getElementById('msg_register'),
	div = document.getElementById('forms');

	if (verif_usr(usr) === true && verif_pwd(pwd) === true)
	{
		var request = new XMLHttpRequest();
		usr = encodeURIComponent(usr);
		pwd = encodeURIComponent(pwd);
		request.addEventListener('readystatechange', function()
		{
			if (request.readyState === XMLHttpRequest.DONE)
			{
				if (request.status === 200)
					document.location.href="signin.php";
				else if (request.status === 401)
					msg_display(msg_signin, msg_register, "Username or password is invalid", div);
				else
					msg_display(msg_signin, msg_register, "Confirm your mail", div);
			}
		});
		request.open ('POST', 'connection.php');
		request.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
		request.send('usr=' + usr + '&pwd=' + pwd);
	}
	else
		 msg_display(msg_signin, msg_register, "One field is invalid", div);
}

function verif_mail(email)
{
	var regex = /^(([a-zA-Z0-9._-]{1,32})@([a-z]{2,16}).([a-z.0-9]{2,16}))$/

	if (regex.test(email) == true)
		return (true);
	return (false);
}

function verif_usr(usr)
{
	var regex = /^([a-zA-Z0-9-_]{4,16})$/;

	if (regex.test(usr) === true)
		return (true);
	return (false);
}

function verif_pwd(pwd)
{
	var regex = /^(?=.*\d)([a-zA-Z0-9-_\s]{4,32})$/,
	i = 0;

	if (regex.test(pwd) === true)
		return (true);
	return (false);
}
