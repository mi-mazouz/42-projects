<?php
	include('../../../tools/picture.php');
	include('../../../services/picture.php');

	if (empty($_POST) || !isset($_POST['pictureNumber']) || $_POST['pictureNumber'] < 0) header('HTTP/1.1 400 BAD REQUEST');

	$pictures = addCommentsAndLikesInPictures(loadPictures($_POST['pictureNumber'], 5));
	if (!$pictures) header('HTTP/1.1 400 NO MORE PICTURES');
	else displayPictures($pictures);
?>