<?php
	include('database.php');

	try
	{
		$cnx = new PDO($db_dns, $db_user, $db_password);
		$cnx->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
	}
	catch(PDOException $err)
	{
		echo 'Connection failled ' . $err->getMessage();
	}
	$cnx->query("CREATE DATABASE IF NOT EXISTS camagru CHARACTER SET UTF8");
	$cnx->query("USE camagru");
	$cnx->query("CREATE TABLE IF NOT EXISTS users
	(
		username VARCHAR(16) NOT NULL,
		password VARCHAR(255) NOT NULL,
		email VARCHAR(64) NOT NULL,
		key_valid VARCHAR(255) NOT NULL
	)");
	$cnx->query("CREATE TABLE IF NOT EXISTS comments
	(
		username VARCHAR(16) NOT NULL,
		date VARCHAR(8) NOT NULL,
		text TEXT NOT NULL,
		pics VARCHAR(64) NOT NULL
	)");
	$cnx->query("CREATE TABLE IF NOT EXISTS pictures
	(
		likes INT NOT NULL,
		username VARCHAR(16) NOT NULL,
		path VARCHAR(64) NOT NULL
	)");
	$cnx->query("CREATE TABLE IF NOT EXISTS likes
	(
		username VARCHAR(16) NOT NULL,
		path VARCHAR(64) NOT NULL
	)");
?>
