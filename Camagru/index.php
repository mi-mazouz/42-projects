<?php
    session_start();
	if (!$_SESSION['isLogged']) header('Location: /src/authentication/signin');
    else header('Location: /src/profile');
?>
