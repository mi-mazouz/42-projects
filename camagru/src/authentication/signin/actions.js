function signin() {
  const submitButton = document.querySelector('#submitButton')
	const username = document.getElementById('username').value.trim()
	const password = document.getElementById('password').value
	
	if (!username || !password) return
	if (!checkUsername(username) || !checkPassword(password)) return
  
  submitButton.classList.add('is-loading')
	const request = new XMLHttpRequest()
	request.addEventListener('readystatechange', () => {
		if (request.readyState === XMLHttpRequest.DONE) {
			if (request.status === 200) document.location.href='/index.php'
			else handleError(request.status, request.statusText)
      submitButton.classList.remove('is-loading')
		}
	})
	request.open ('POST', './controller.php')
	request.setRequestHeader('Content-Type', 'application/x-www-form-urlencoded')
	request.send('username=' + username + '&password=' + password)
}