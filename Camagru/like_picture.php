<?php
	session_start();
	include('Config/setup.php');
	include('class.php');

	if (empty($_SESSION['usr']))
	{
		header("Location: index.php");
		exit ;
	}

	$request = new Request;
	if ($request->check_usr_like($cnx, $_SESSION['usr'], $_POST['path']) === false)
	{
		$request->increment_likes($cnx, $_POST['path']);
		$request->create_usr_like($cnx, $_SESSION['usr'], $_POST['path']);
	}
	else
	{
		$request->decrement_likes($cnx, $_POST['path']);
		$request->delete_usr_like($cnx, $_SESSION['usr'], $_POST['path']);
	}
	$cmd = $cnx->prepare("SELECT likes FROM pictures WHERE path = :path");
	$cmd->bindValue(':path', $_POST['path'], PDO::PARAM_STR);
	$cmd->execute();
	$result = $cmd->fetch();
	echo $result['likes'];
?>
