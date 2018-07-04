<?php
	include('./connect.php');

	$cnx->query('CREATE DATABASE IF NOT EXISTS camagru CHARACTER SET UTF8');
	$cnx->query('USE camagru');
	$cnx->query('CREATE TABLE IF NOT EXISTS users
	(
		id INT NOT NULL AUTO_INCREMENT,
		username VARCHAR(16) NOT NULL UNIQUE,
		email VARCHAR(32) NOT NULL UNIQUE,
		password VARCHAR(72) NOT NULL,
		activationToken VARCHAR(72),
		commentNotification ENUM("0", "1") NOT NULL DEFAULT "1",
		PRIMARY KEY (id)
	)');

	$cnx->query('CREATE TABLE IF NOT EXISTS pictures
	(
		id INT NOT NULL AUTO_INCREMENT,
		path VARCHAR(32) NOT NULL UNIQUE,
		username VARCHAR(16) NOT NULL,
		PRIMARY KEY (id),
		FOREIGN KEY (username) REFERENCES users(username) ON DELETE CASCADE
	)');
	$cnx->query('CREATE TABLE IF NOT EXISTS comments
	(
		id INT NOT NULL AUTO_INCREMENT,
		username VARCHAR(16) NOT NULL,
		date VARCHAR(8) NOT NULL,
		text TEXT NOT NULL,
		pictureId INT NOT NULL,
		PRIMARY KEY (id),
		FOREIGN KEY (pictureId) REFERENCES pictures(id) ON DELETE CASCADE,
		FOREIGN KEY (username) REFERENCES users(username) ON DELETE CASCADE
	)');
	$cnx->query("CREATE TABLE IF NOT EXISTS likes
	(
		id INT NOT NULL AUTO_INCREMENT,
		username VARCHAR(16) NOT NULL,
		pictureId INT NOT NULL,
		PRIMARY KEY (id),
		FOREIGN KEY (pictureId) REFERENCES pictures(id) ON DELETE CASCADE,
		FOREIGN KEY (username) REFERENCES users(username) ON DELETE CASCADE
	)");
?>
