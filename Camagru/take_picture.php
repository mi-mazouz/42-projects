<?php
	session_start();
	include('Config/setup.php');
	include('class.php');

	$request = new Request;
	$dest = return_data_img($_POST['pics']);
	$path = 'Pics/webcam_' . microtime(TRUE) . '.png';
	$dest = imagecreatefromstring(base64_decode($dest));
	$src = imagecreatefrompng($_POST['src']);
	$dest = return_img_merge($dest, $src);
	$file = fopen($path, 'w+');
	fputs($file, $dest);
	fclose($file);
	$request->saving_picture($cnx, $_SESSION['usr'], $path);
	echo $path;

function return_img_merge($dest, $src)
{
	$w_dest = imagesx($dest);
	$h_dest = imagesy($dest);
	$w_src = imagesx($src);
	$h_src = imagesy($src);
	imagecopy($dest, $src, $w_dest / 3, $h_dest / 3, 0, 0, $w_src, $h_src);
	ob_start();
	imagejpeg($dest);
	imagedestroy($dest);
	imagedestroy($src);
	$dest = ob_get_clean();
	return ($dest);
}

function return_data_img($img)
{
	$i = 0;
	while ($img[$i] != ',')
		$i++;
	$str = substr($img, $i + 1);
	$str = str_replace(' ', '+', $str);
	return ($str);
}
?>
