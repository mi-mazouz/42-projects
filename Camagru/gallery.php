<?php
	session_start();

	function display_img()
	{
		include('Config/setup.php');
		include('class.php');

		$request = new Request;
		$cmd = $cnx->prepare("SELECT * FROM pictures ORDER BY path DESC LIMIT 2");
		$cmd->execute();
		$request->load_pictures($cnx, $cmd, $_SESSION['usr']);
	}
?>

<!DOCTYPE HTML>
<HTML>
	<HEAD>
		<META charset="utf-8"/>
		<META name="viewport" content="width=device-width, initial-scale=1"/>
		<LINK rel="icon" type="image/ico" href="Pics/Icone.ico" />
		<LINK rel="stylesheet" href="Css/gallery.css"/>
		<TITLE>Camagru</TITLE>
	</HEAD>
	<BODY>
		<HEADER>
<?php
			if (!empty($_SESSION['usr']))
				echo '<A class="onglets" href="signin.php">Home</A>
					  <A class="onglets" href="logout.php">Logout</A>';
			else
				echo '<A class="onglets_logout" href="signin.php">Home</A>';
?>
		</HEADER>
		<MAIN>
		<STYLE>
			@font-face
			{
				font-family: Comment;
				src: url(Police/Playfair.ttf);
			}
			</STYLE>
<?php
			display_img();
?>
		</MAIN>
		<FOOTER>
			<INPUT id="more_pictures" type="button" value="More pictures"/>
			<STYLE>
				@font-face
				{
					font-family: Minecraft;
					src: url(Police/Minecraft.ttf);
				}
			</STYLE>
			<DIV id="copyright">
				<I>&copy Camagru 2017</I>
			</DIV>
		</FOOTER>
	</BODY>
	<SCRIPT type="text/javascript" src="Js/gallery.js"></SCRIPT>
</HTML>
