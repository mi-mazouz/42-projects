<?php
    session_start();

    include($_SERVER['DOCUMENT_ROOT'] . '/services/user.php');
    include($_SERVER['DOCUMENT_ROOT'] . '/services/email.php');

    if (empty($_POST)) header('HTTP/1.1 400 BAD REQUEST');
    else if (empty($_POST['email']) || strlen($_POST['email']) > 32) header('HTTP/1.1 400 WRONG EMAIL');
    else {
        $user = getUserByUsernameOrEmail(null, $_POST['email']);
        
        if (!$user) header('HTTP/1.1 400 EMAIL DOES NOT EXISTS');        
        else if (!$_SESSION['resetPwdToken']) {
            $_SESSION['resetPwdToken'] = 'resetPwdToken_' . bin2hex(random_bytes(15));
            
            sendPasswordReset($user['email'], $user['username'], $_SESSION['resetPwdToken']);
            $_SESSION['mailSent'] = true;
            header('HTTP/1.1 200 RESET EMAIL SENT');      
        }
        else header('HTTP/1.1 400 RESET EMAIL ALREADY SENT'); 
    }
?>