<?php
    session_start();
    include($_SERVER['DOCUMENT_ROOT'] . '/services/picture.php');

    if (empty($_SESSION) || empty($_SESSION['username'])) header('HTTP/1.1 400 BAD REQUEST');
    else if (empty($_POST) || empty($_POST['pictureId'])) header('HTTP/1.1 400 BAD REQUEST');
    
    deletePictureById($_POST['pictureId'], $_SESSION['username']);
    header('HTTP/1.1 200');
?>