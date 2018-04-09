<?php
	include('Config/setup.php');
	include('class.php');
	session_start();

	$request = new Request;
	$cmd = $cnx->prepare("SELECT * FROM pictures ORDER BY path DESC LIMIT :nb_pics, 2");
	$cmd->bindValue(':nb_pics', intval($_POST['nb_pics']), PDO::PARAM_INT);
	$cmd->execute();
	$request->load_pictures($cnx, $cmd, $_SESSION['usr']);
?>
