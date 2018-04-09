<?php
	session_start();
	include('Config/setup.php');
	include('class.php');

	$request = new Request;
	$cmd = $cnx->prepare("SELECT * FROM pictures ORDER BY path DESC LIMIT :nb_pics, 1");
	$cmd->bindValue(':nb_pics', intval($_POST['nb_pics']), PDO::PARAM_INT);
	$cmd->execute();
	$request->delete_picture($cnx, $_POST['path']);
	unlink($_POST['path']);
	$request->load_pictures($cnx, $cmd, $_SESSION['usr']);
?>
