function update() {
    const submitButton = document.querySelector('#submitButton')
	const username = document.getElementById('username').value.trim()
	const email = document.getElementById('email').value.trim()
    const password = document.getElementById('password').value
    const commentNotificationInputs = document.getElementById('commentNotification').getElementsByTagName('input')

    if (commentNotificationInputs[0].checked && commentNotificationInputs[1].checked) return
    if (!commentNotificationInputs[0].checked && !commentNotificationInputs[1].checked) return
    if (username !== '' && !checkUsername(username)) return
    if (email !== '' && !checkEmail(email)) return
    if (password !== '' && !checkPassword(password)) return
    
    submitButton.classList.add('is-loading')
    const commentNotification = commentNotificationInputs[0].checked ? '0' : '1'
	const request = new XMLHttpRequest()
	request.addEventListener('readystatechange', () => {
		if (request.readyState === XMLHttpRequest.DONE) {
            handleError(request.status, request.statusText)
            submitButton.classList.remove('is-loading')
		}
	})
	request.open ('POST', './controller.php')
	request.setRequestHeader('Content-Type', 'application/x-www-form-urlencoded')
	request.send('username=' + username + '&email=' + email + '&password=' + password + '&commentNotification=' + commentNotification)
}