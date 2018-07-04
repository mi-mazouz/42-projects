const notificationWrapper = document.querySelector('#notificationWrapper')

if (!notificationWrapper.classList.contains('is-display')) notificationWrapper.style.display = 'none'
notificationWrapper.children[0].addEventListener('click', () => notificationWrapper.style.display = 'none')

function handleError(status, notificationStatusText) {
	notificationWrapper.style.display = 'block'
	if (status === 400) notificationWrapper.classList.add('is-danger')
	else notificationWrapper.classList.add('is-success') 
	
	switch(notificationStatusText) {
		case 'PLEASE CONFIRM YOUR EMAIL':
			notificationWrapper.children[1].innerHTML = 'A confirmation email has been sent, please valid your account'
			break
		case 'EMAIL OR USERNAME ALREADY EXISTS':
			notificationWrapper.children[1].innerHTML = '<strong>Email or username already exists</strong>'
			break
		case 'WRONG USERNAME OR PASSWORD':
			notificationWrapper.children[1].innerHTML = '<strong>Username or password invalid</strong>'
			break
		case 'PLEASE CONFIRM YOUR EMAIL':
			notificationWrapper.children[1].innerHTML = '<strong>An email has been sent to confirm to confirm your account, please check it</strong>'
			break
		case 'EMAIL DOES NOT EXISTS':
			notificationWrapper.children[1].innerHTML = '<strong>Email invalid</strong>'
			break
		case 'RESET EMAIL SENT':
			notificationWrapper.children[1].innerHTML = '<strong>An email to reset your password has been sent</strong>'
			break
		case 'RESET EMAIL ALREADY SENT':
			notificationWrapper.children[1].innerHTML = '<strong>An email has already been sent</strong>'
			break
		case 'SETTINGS CHANGED':
			notificationWrapper.children[1].innerHTML = '<strong>Your settings have been changed</strong>'
			break
		case 'NO MORE PICTURES':
			notificationWrapper.children[1].innerHTML = '<strong>No more pictures available</strong>'
			break
		default:
			notificationWrapper.children[1].innerHTML = '<strong>An error occurred</strong>'
			break
	}

  notificationWrapper.children[0].addEventListener('click', () => notificationWrapper.style.display = 'none')
}

function checkEmail(email) {
	const regex = /^(([a-zA-Z0-9._-]{1,32})@([a-z]{2,16}).([a-z.0-9]{2,16}))$/

	return regex.test(email)
}

function checkUsername(username) {
	const regex = /^([a-zA-Z0-9-_]{4,16})$/

	return regex.test(username)
}

function checkPassword(password) {
	const regex = /^(?=.*\d)([a-zA-Z0-9-_\s]{4,32})$/

	return regex.test(password)
}

function escapeChar(str) {
	str = str.replace(/&/g, "&amp;");
	str = str.replace(/>/g, "&gt;");
	str = str.replace(/</g, "&lt;");
	str = str.replace(/"/g, "&quot;");
	str = str.replace(/'/g, "&#039;");
	return (str);
}