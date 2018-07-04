<?php
    session_start();    
    include($_SERVER['DOCUMENT_ROOT'] . '/services/user.php');

    if (empty($_POST)) header('HTTP/1.1 400 BAD REQUEST');
    else if (empty($_POST['username']) || strlen($_POST['username']) > 16) header('HTTP/1.1 400 WRONG USERNAME');
    else if (empty($_POST['password']) || strlen($_POST['password']) > 32) header('HTTP/1.1 400 WRONG PASSWORD');
    else {
        $user = getUserByUsernameOrEmail($_POST['username'], null);

        if (!$user || !password_verify($_POST['password'], $user['password'])) header('HTTP/1.1 400 WRONG USERNAME OR PASSWORD');
        else if ($user['activationToken'] !== null) header('HTTP/1.1 400 PLEASE CONFIRM YOUR EMAIL');
        else {
            $_SESSION['isLogged'] = true;
            $_SESSION['email'] = $user['email'];
            $_SESSION['username'] = $user['username'];
            $_SESSION['commentNotification'] = $user['commentNotification'];
        
            header('HTTP/1.1 200 OK');
        }
    }
?>
