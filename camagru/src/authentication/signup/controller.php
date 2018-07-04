<?php
    include($_SERVER['DOCUMENT_ROOT'] . '/services/user.php');
    include($_SERVER['DOCUMENT_ROOT'] . '/services/email.php');

    if (empty($_POST)) header('HTTP/1.1 400 BAD REQUEST');
    else if (empty($_POST['username']) || strlen($_POST['username']) > 16) header('HTTP/1.1 400 WRONG USERNAME');
    else if (empty($_POST['email']) || strlen($_POST['email']) > 32) header('HTTP/1.1 400 WRONG EMAIL');
    else if (empty($_POST['password']) || strlen($_POST['password']) > 32) header('HTTP/1.1 400 WRONG PASSWORD');
    else {
        $user = getUserByUsernameOrEmail($_POST['username'], $_POST['email']);
        
        if (!$user) {
            $encryptedPassword = password_hash($_POST['password'], PASSWORD_BCRYPT);
            $activationToken = 'activationToken_'.bin2hex(random_bytes(15));

            createUser(strtolower($_POST['username']), strtolower($_POST['email']), $encryptedPassword, $activationToken);
            sendAccountActivationEmail($_POST['email'], $_POST['username'], $activationToken);
            header('HTTP/1.1 200 PLEASE CONFIRM YOUR EMAIL');
        } else header('HTTP/1.1 400 EMAIL OR USERNAME ALREADY EXISTS');
    }
?>
