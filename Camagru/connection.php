<?php
	session_start();
	include('Config/setup.php');
	include('class.php');

	if (!empty($_POST))
	{
		$request = new Request;
		$result = $request->check_usr_valid($cnx, $_POST['usr']);

		if ($result === false)
			http_response_code(401);
		else if ($result['key_valid'] !== "OK")
			http_response_code(400);
		else if (password_verify($_POST['pwd'], $result['password']) === false)
			http_response_code(401);
		else
			$_SESSION['usr'] = $_POST['usr'];
	}
	else
	{
		header("Location: index.php");
		exit;
	}
?>
