<?php
	if ($_SERVER['DOCUMENT_ROOT']) {
		$config = require($_SERVER['DOCUMENT_ROOT'] . '/config.php');

		try {
			$cnx = new PDO($config['db_docker_dsn'], $config['db_user'], $config['db_passwd']);
			$cnx->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
			$cnx->query('USE camagru');
		} catch(PDOException $err) {
			echo 'Connection failled ' . $err->getMessage();
		}
	} else {
		$config = require('../config.php');
		
		try {
			$cnx = new PDO($config['db_dsn'], $config['db_user'], $config['db_passwd']);
			$cnx->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
		} catch(PDOException $err) {
			echo 'Connection failled ' . $err->getMessage();
		}
	}
?>
