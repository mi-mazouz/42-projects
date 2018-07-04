<?php
  session_start();
  include($_SERVER['DOCUMENT_ROOT'] . '/services/picture.php');
  include($_SERVER['DOCUMENT_ROOT'] . '/tools/picture.php');

  if (empty($_POST)) header('HTTP/1.1 400 BAD REQUEST');
  else {
    $picture = imagecreatefromstring(base64_decode(str_replace(' ', '+', $_POST['picture'])));
    $stackableImage = imagecreatefromstring(base64_decode(str_replace(' ', '+', $_POST['stackableImage'])));
    $time = microtime(TRUE);
    $filePath = $time . '.jpeg';
    $mergedPicture = mergedPicture($picture, $stackableImage);
    writePicture($mergedPicture, $filePath);
    createPicture($_SESSION['username'], $filePath);
    header('HTTP/1.1 200 ' . $time);
  }
?>