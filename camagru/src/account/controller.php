<?php
    session_start();
    include($_SERVER['DOCUMENT_ROOT'] . '/services/user.php');

    if (empty($_POST)) header('HTTP/1.1 400 BAD REQUEST');
    else if (!isset($_POST['username']) || strlen($_POST['username']) > 16) header('HTTP/1.1 400 WRONG USERNAME');
    else if (!isset($_POST['email']) || strlen($_POST['email']) > 32) header('HTTP/1.1 400 WRONG EMAIL');
    else if (!isset($_POST['password']) || strlen($_POST['password']) > 32) header('HTTP/1.1 400 WRONG PASSWORD');
    else {
        $newUser = getUserByUsernameOrEmail($_POST['username'], $_POST['email']);
        if ($newUser) header('HTTP/1.1 400 USERNAME OR EMAIL ALREADY EXISTS');

        $user = getUserByUsernameOrEmail($_SESSION['username'], $_SESSION['email']);

        $username = $_POST['username'] === '' ? $user['username'] : strtolower($_POST['username']);
        $email = $_POST['email'] === '' ? $user['email'] : strtolower($_POST['email']);
        $password = $_POST['password'] === '' ? $user['password'] : password_hash($_POST['password'], PASSWORD_BCRYPT);
        $commentNotificaiton = $_POST['commentNotification'];

        updateUserByEmail($user['email'], $username, $email, $password, $commentNotificaiton);

        $_SESSION['username'] = $username;
        $_SESSION['email'] = $email;
        $_SESSION['commentNotification'] = $commentNotificaiton;

        header('HTTP/1.1 200 SETTINGS CHANGED');
    }
?>