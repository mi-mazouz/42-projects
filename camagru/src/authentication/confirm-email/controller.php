<?php
    include($_SERVER['DOCUMENT_ROOT'] . '/services/user.php');
    
    if (empty($_GET)) header('HTTP/1.1 400 BAD REQUEST');
    $user = getUserByUsernameOrEmail($_GET['username'], null);
   
    if ($user['activationToken'] === $_GET['token']) {
        activeUserAccountByUsername($_GET['username']);
        echo 'Mail confirmed!';
    } else echo 'Bad token :(';
?>