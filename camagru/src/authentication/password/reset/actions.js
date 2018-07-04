function resetPassword(token, username){
	const password = document.getElementById('password').value
  const submitButton = document.querySelector('#submitButton')
	
	if (!password || !checkPassword(password) || !submitButton) return
	
  submitButton.classList.add('is-loading')
	const request = new XMLHttpRequest()
	request.addEventListener('readystatechange', () => {
		if (request.readyState === XMLHttpRequest.DONE) {
      if (request.status === 200) document.location.href='/src/authentication/signin'
      else handleError(request.status, request.statusText)
      submitButton.classList.remove('is-loading')
		}
	})
	request.open('POST', './controller.php')
	request.setRequestHeader('Content-Type', 'application/x-www-form-urlencoded')
	request.send('password=' + password + '&token=' + token + '&username=' + username)
}