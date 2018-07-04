<?php
    session_start();
    include($_SERVER['DOCUMENT_ROOT'] . '/services/comment.php');
    include($_SERVER['DOCUMENT_ROOT'] . '/services/user.php');
    include($_SERVER['DOCUMENT_ROOT'] . '/services/email.php');

    if (empty($_POST) || empty($_POST['comment'])) header('HTTP/1.1 400 BAD REQUEST');
    else if (strlen($_POST['comment']) > 255 || empty($_POST['pictureId'])) header('HTTP/1.1 400 BAD REQUEST');
    
    $date = date("g:i a");
    addComment($_SESSION['username'], $date, $_POST['comment'], $_POST['pictureId']);
    $userOfThePicture = getUserByPictureId($_POST['pictureId']);
    if ($userOfThePicture['commentNotification'] === "1") {
        sendNewCommentEmail($userOfThePicture['email'], $userOfThePicture['username'], $_SESSION['username']);
    }
    echo $_POST['comment'];
?>