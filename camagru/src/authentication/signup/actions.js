function signup() {
  const submitButton = document.querySelector('#submitButton')
	const username = document.getElementById('username').value.trim()
	const email = document.getElementById('email').value.trim()
  const password = document.getElementById('password').value

	if (!username || !email || !password) return
	if (!checkUsername(username) || !checkEmail(email) || !checkPassword(password)) return

  submitButton.classList.add('is-loading')
	const request = new XMLHttpRequest()
	request.addEventListener('readystatechange', () => {
		if (request.readyState === XMLHttpRequest.DONE) {
			handleError(request.status, request.statusText)
      submitButton.classList.remove('is-loading')
		}
	})
	request.open('POST', './controller.php')
	request.setRequestHeader('Content-Type', 'application/x-www-form-urlencoded')
	request.send('username=' + username + '&email=' + email + '&password=' + password)
}

