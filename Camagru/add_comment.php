<?php
	session_start();
	include('Config/setup.php');
	include('class.php');

	$date = date("g:i a");
	$comment =  $_SESSION['usr'] . ' at ' . $date . ' : ' . $_POST['com'];
	$request = new Request;
	$mail = new Mail;
	$request->add_comment($cnx, $_SESSION['usr'], $date, $_POST['com'], $_POST['path']);
	$result = $request->select_usr($cnx, $_POST['path']);
	$result = $request->select_email($cnx, $result['username']);
	$mail->send_mail_comments($result['email'], $_SESSION['usr']);
	echo $comment;
?>
