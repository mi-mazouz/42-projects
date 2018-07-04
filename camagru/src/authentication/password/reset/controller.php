<?php
    session_start();
    include($_SERVER['DOCUMENT_ROOT'] . '/services/user.php');
    include($_SERVER['DOCUMENT_ROOT'] . '/services/email.php');

    if (empty($_POST)) header('HTTP/1.1 400 BAD REQUEST');
    else if ($_GET['resetPwdToken'] !== $_SESSION['resetPwdToken']) header('HTTP/1.1 400 BAD TOKEN');
    else {
        $user = getUserByUsernameOrEmail($_POST['username'], null);
    
        if (!$user) header('HTTP/1.1 400 WRONG USERNAME');
        else if ($_SESSION['mailSent']) {
            updateUserPasswordByEmail($user['email'], password_hash($_POST['password'], PASSWORD_BCRYPT));
            $_SESSION['mailSent'] = false;
            header('HTTP/1.1 200 OK');
        }
    }
?>