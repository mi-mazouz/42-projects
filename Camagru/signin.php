<?php
	session_start();

	if (empty($_SESSION['usr']))
		header("Location: index.php");
 ?>
<!DOCTYPE HTML>
<HTML>
	<HEAD>
		<META charset="utf-8"/>
		<META name="viewport" content="width=device-width, initial-scale=1"/>
		<LINK rel="icon" type="image/ico" href="Pics/Icone.ico" />
		<LINK rel="stylesheet" href="Css/signin.css"/>
		<TITLE>Camagru</TITLE>
	</HEAD>
	<BODY>
		<HEADER>
			<A class="onglets" href="signin.php">Home</A>
			<A class="onglets" href="gallery.php">Gallery</A>
			<UL class="onglets">
				<LI id="link">
					<A id="setting">Settings</A>
					<UL id="none">
						<LI><A href="logout.php">Logout</A></LI>
						<LI><A href="javascript:change_pwd()">Change password</A></LI>
					</UL>
				</LI>
			</UL>
			<STYLE>
			@font-face
			{
				font-family: Main Title;
				src: url(Police/yerbaluisa.ttf);
			}
			</STYLE>
		</HEADER>
		<MAIN>
			<DIV id="webcam">
				<DIV id="shoot">
					<DIV id="stream">
						<IMG id="superpose_img"></IMG>
						<IMG class="stream" id="upload_img"></IMG>
						<VIDEO class="stram" id="video"></VIDEO><BR/>
					</DIV>
					<DIV id="setting">
						<BUTTON id="startbutton">Take a shot</BUTTON>
						<input type="file" name="file" id="file" class="inputfile" />
						<LABEL for="file">Choose a file</LABEL></BR></BR>
						<IMG class="mini_pics" src="Pics/Carapuce.png" onclick="filter(this)"/>
						<IMG class="mini_pics" src="Pics/Glasses.png" onclick="filter(this)"/>
						<IMG class="mini_pics" src="Pics/Tiger.png" onclick="filter(this)"/>
						<IMG class="mini_pics" src="Pics/Hot_dog.png" onclick="filter(this)"/>
					</DIV>
				</DIV>
				<DIV id="pics_list">
					<IMG id="no_pics" src="Pics/no_pics.jpg"></IMG>
					<CANVAS id="canvas"></CANVAS>
				</DIV>
			</DIV>
			<DIV id="form">
				<FORM id="change_pwd" class="forms">
					<H3 class="title">Change password</H3>
					<INPUT id="old_pwd" class="input" type="password" name="old_pwd" placeholder="Old password"/>
					<INPUT id="new_pwd" class="input" type="password" name="new_pwd" placeholder="New password"/>
					<INPUT id="confirm_pwd" class="input" type="password" name="confirm_pwd" placeholder="Confirm password"/>
					<P id="msg_change"></P>
				<DIV id="return">
					<INPUT class="button" type="button" value="Validate" onclick="verif_change()"/>
					<INPUT class="button" type="button" value="Return" onclick="return_change_pwd()"/>
				</DIV>
				</FORM>
			</DIV>
		</MAIN>
		<FOOTER>
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
		<SCRIPT type="text/javascript" src="Js/webcam.js"></SCRIPT>
		<SCRIPT type="text/javascript" src="Js/msg.js"></SCRIPT>
		<SCRIPT type="text/javascript" src="Js/reset_field.js"></SCRIPT>
		<SCRIPT type="text/javascript" src="Js/verif_field.js"></SCRIPT>
</HTML>
