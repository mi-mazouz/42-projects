<?php
	include('Config/setup.php');
?>

<!DOCTYPE HTML>
<HTML>
	<HEAD>
		 <META charset="utf-8"/>
		 <META name="viewport" content="width=device-width, initial-scale=1"/>
		<LINK rel="icon" type="image/ico" href="Pics/Icone.ico" />
		<LINK rel="stylesheet" href="Css/index.css" />
		<TITLE>Camagru</TITLE>
	</HEAD>
	<BODY>
	<HEADER>
		<STYLE>
			@font-face
			{
				font-family: Main Title;
				src: url(Police/Billabong.ttf);
			}
			</STYLE>
			<H1 id="title">Camagru</H1>
	</HEADER>
	<MAIN>
		<DIV class="image1">
			<A href="gallery.php">
				<IMG id="iphone" src="Pics/Iphone.jpg"/>
			</A>
		</DIV>
		<DIV id="forms">
			<FORM class="forms">
				<H3 class="title">Sign in</H3>
				<INPUT id="usr_signin" class="input" type="text" name="usr" placeholder="Username"/>
				<INPUT id="pwd_signin" class="input" type="password" name="pwd" placeholder="Password"/>
				<P id="msg_signin"></P>
				<INPUT class="button" type="button" value="Connection" onclick="verif_signin()"/>
				<INPUT class="button" type="button" value="Forget password" onclick="reset_password()"/>
				<H3 class="title">Register</H3>
				<A class="info" id="info_register">
					<INPUT id="usr_register" class="input" type="text" name="usr" placeholder="Username"/>
					<SPAN>Your username must contain between 4 and 16 characters</SPAN>
				</A>
				<A class="info">
					<INPUT id="pwd_register" class="input" type="password" name="pwd" placeholder="Password"/>
					<SPAN>Your password must contain between 4 and 32 characters and at least 1 digit</SPAN>
				</A>
				<INPUT id="email_register" class="input" type="text" name="email" placeholder="Email"/>
				<P id="msg_register"></P>
				<INPUT id="subscribe" class="button" type="button" value="Subscribe" onclick="verif_register()"/>
			</FORM>
			<DIV id ="reset">
				<H3 class="title">Reset password</H3>
				<INPUT id="usr_reset" class="input" type="text" name="usr" placeholder="Username"/>
				<INPUT id="email_reset" class="input" type="text" name="email" placeholder="Email"/>
				<P id="msg_reset"></P>
				<INPUT class="button" type="button" value="Validate" onclick="verif_reset()"/>
				<INPUT class="button" type="button" value="Return" onclick="return_reset()"/>
			</DIV>
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
			<I>&copy CAMAGRU 2017</I>
		</DIV>
	</FOOTER>
	</BODY>
	<SCRIPT type="text/javascript" src="Js/verif_field.js"></SCRIPT>
	<SCRIPT type="text/javascript" src="Js/reset_field.js"></SCRIPT>
	<SCRIPT type="text/javascript" src="Js/msg.js"></SCRIPT>
</HTML>
