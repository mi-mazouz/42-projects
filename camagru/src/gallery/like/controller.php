<?php
    session_start();
    include($_SERVER['DOCUMENT_ROOT'] . '/services/like.php');

    if (empty($_POST) || empty($_POST['pictureId'])) header('HTTP/1.1 400 BAD REQUEST');
    $isLiked = getLikesByPictureIdAndUsername($_POST['pictureId'], $_SESSION['username']);
    
    if (!$isLiked) createLike($_POST['pictureId'], $_SESSION['username']);
    else deleteLike($_POST['pictureId'], $_SESSION['username']);
    header('HTTP/1.1 200 ' . countLikesByPictureId($_POST['pictureId']));
?>