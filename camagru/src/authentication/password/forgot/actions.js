function forgotPassword() {
	const email = document.getElementById('email').value
  const submitButton = document.querySelector('#submitButton')
	
	if (!email || !checkEmail(email) || !submitButton) return
	
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
	request.send('email=' + email)
}