<?php
class Request
{
    private $_cmd;

    public function load_pictures($cnx, $load, $usr)
    {
        while (($result = $load->fetch()) !== false)
    	{
    		$this->_cmd = $cnx->prepare("SELECT username, date, text FROM comments WHERE pics = :path");
    		$this->_cmd->bindValue(':path', $result['path'], PDO::PARAM_STR);
    		$this->_cmd->execute();
    		echo '<DIV class="pics_list">';
    		echo '<DIV class="left">';
    		echo '<IMG class="pics" src="' . $result['path'] . '"/>';
    		if ($usr === $result['username'])
    			echo 	'<IMG class="logo" src="Pics/Delete.png" onclick="delete_img(this)"/>';
    		echo '</DIV><DIV id="comment">';
    		while (($result_2 = $this->_cmd->fetch()) !== false)
    			echo '<P class="com">' . '- '
    						. htmlspecialchars($result_2['username']) . '  at  '
    						. htmlspecialchars($result_2['date']) . ' : '
    						. htmlspecialchars($result_2['text']) . '</P></BR>';
    		echo '</DIV>
    			 <DIV class="setting">';
    		if (!empty($usr))
    		{
    					echo '<P id="like" onclick="like_img(this)">Like</P>
    						  <P class="nb_likes">' . $result['likes'] . '</P>';
    					echo '<INPUT class="input" type="text" placeholder="Comment"/>
    						  <BUTTON class="button" onclick="add_com(this)">Submit</BUTTON>';
    		}
    		else
    			echo '<P id="like">Like</P>
    				  <P class="nb_likes">' . $result['likes'] . '</P>';
    		echo '</DIV>
    			  </DIV>';
    	}
    }

    public function saving_picture($cnx, $usr, $path)
    {
        $this->_cmd = $cnx->prepare("INSERT INTO pictures VALUES
    	(
    		:likes,
    		:usr,
    		:path
    	)");
    	$this->_cmd->bindValue(':usr', $usr, PDO::PARAM_STR);
    	$this->_cmd->bindValue(':likes', 0, PDO::PARAM_INT);
    	$this->_cmd->bindValue(':path', $path, PDO::PARAM_STR);
    	$this->_cmd->execute();
    }

    public function delete_picture($cnx, $path)
    {
        $this->cmd = $cnx->prepare("DELETE FROM pictures WHERE path = :path");
        $this->cmd->bindValue(':path', $path, PDO::PARAM_STR);
        $this->cmd->execute();
        $this->cmd = $cnx->prepare("DELETE FROM comments WHERE pics = :path");
        $this->cmd->bindValue(':path', $path, PDO::PARAM_STR);
        $this->cmd->execute();
        $this->cmd = $cnx->prepare("DELETE FROM likes WHERE path = :path");
        $this->cmd->bindValue(':path', $path, PDO::PARAM_STR);
        $this->cmd->execute();
    }

    public function select_email($cnx, $usr)
    {
      $this->_cmd = $cnx->prepare("SELECT email FROM users WHERE username = :usr");
      $this->_cmd->bindvalue(':usr', $usr, PDO::PARAM_STR);
      $this->_cmd->execute();
      return ($this->_cmd->fetch());
    }

    public function select_usr($cnx, $path)
    {
      $this->_cmd = $cnx->prepare("SELECT username FROM pictures WHERE path = :path");
    	$this->_cmd->bindvalue(':path', $path, PDO::PARAM_STR);
    	$this->_cmd->execute();
      return ($this->_cmd->fetch());
    }

    public function add_comment($cnx, $usr, $date, $com, $path)
    {
      $this->_cmd = $cnx->prepare("INSERT INTO comments VALUES
      (
        :usr,
        :date,
        :com,
        :pics
      )");
      $this->_cmd->bindValue(':usr', $usr, PDO::PARAM_STR);
      $this->_cmd->bindValue(':date', $date, PDO::PARAM_STR);
      $this->_cmd->bindValue(':com', $com, PDO::PARAM_STR);
      $this->_cmd->bindValue(':pics', $path, PDO::PARAM_STR);
      $this->_cmd->execute();
    }

    public function check_usr_like($cnx, $usr, $path)
    {
      $this->_cmd = $cnx->prepare("SELECT * FROM likes WHERE path = :path AND username = :usr");
    	$this->_cmd->bindValue(':path', $path, PDO::PARAM_STR);
    	$this->_cmd->bindValue(':usr', $usr, PDO::PARAM_STR);
    	$this->_cmd->execute();
      if ($this->_cmd->fetch() === false)
        return (false);
      return (true);
    }

    public function create_usr_like($cnx, $usr, $path)
    {
      $this->_cmd = $cnx->prepare("INSERT INTO likes VALUES
  		(
  			:username,
  			:pics
  		)");
  		$this->_cmd->bindValue(':pics', $path, PDO::PARAM_STR);
  		$this->_cmd->bindValue(':username', $usr, PDO::PARAM_STR);
  		$this->_cmd->execute();
    }

    public function delete_usr_like($cnx, $usr, $path)
    {
      $this->_cmd = $cnx->prepare("DELETE FROM likes WHERE username = :usr AND path = :path");
  		$this->_cmd->bindValue(':usr', $usr, PDO::PARAM_STR);
  		$this->_cmd->bindValue(':path', $path, PDO::PARAM_STR);
  		$this->_cmd->execute();
    }

    public function increment_likes($cnx, $path)
    {
      $this->_cmd = $cnx->prepare("UPDATE pictures SET likes = likes + 1 WHERE path = :path");
      $this->_cmd->bindValue(':path', $path, PDO::PARAM_STR);
      $this->_cmd->execute();
    }

    public function decrement_likes($cnx, $path)
    {
      $this->_cmd = $cnx->prepare("UPDATE pictures SET likes = likes - 1 WHERE path = :path");
      $this->_cmd->bindValue(':path', $path, PDO::PARAM_STR);
      $this->_cmd->execute();
    }

    public function update_pwd($cnx, $pwd, $usr)
    {
      $this->_cmd = $cnx->prepare("UPDATE users SET password = :pwd WHERE username = :usr");
      $this->_cmd->bindValue(':pwd', $pwd, PDO::PARAM_STR);
      $this->_cmd->bindValue(':usr', $usr, PDO::PARAM_STR);
      $this->_cmd->execute();
    }

    public function check_usr_valid($cnx, $usr)
    {
      $this->_cmd = $cnx->prepare("SELECT username, password, key_valid FROM users WHERE  username = :usr");
      $this->_cmd->bindValue(':usr', $usr, PDO::PARAM_STR);
      $this->_cmd->execute();
      return ($this->_cmd->fetch());
    }

    public function check_usr_exist($cnx, $email, $usr)
    {
      $this->_cmd = $cnx->prepare("SELECT username, email FROM users WHERE username = :usr OR email = :email");
      $this->_cmd->bindValue(':usr', $usr, PDO::PARAM_STR);
      $this->_cmd->bindValue(':email', $email, PDO::PARAM_STR);
      $this->_cmd->execute();
      if ($this->_cmd->fetch() === false)
        return (false);
      return (true);
    }

    public function account_activation($usr, $cnx)
    {
        $this->_cmd = $cnx->prepare("UPDATE users SET key_valid = :OK WHERE username = :usr");
        $this->_cmd->bindValue(':usr', $usr, PDO::PARAM_STR);
        $this->_cmd->bindValue(':OK', "OK", PDO::PARAM_STR);
        $this->_cmd->execute();
    }

    public function usr_registration($cnx, $usr, $pwd, $email, $key)
    {
      $this->_cmd = $cnx->prepare("INSERT INTO users VALUES
      (
        :usr,
        :pwd,
        :email,
        :key_valid
      )");
      $this->_cmd->bindValue(':usr', $usr, PDO::PARAM_STR);
      $this->_cmd->bindValue(':pwd', $pwd, PDO::PARAM_STR);
      $this->_cmd->bindValue(':email', $email, PDO::PARAM_STR);
      $this->_cmd->bindValue(':key_valid', $key, PDO::PARAM_STR);
      $this->_cmd->execute();
    }
}

class Mail
{
    private $_subject;
    private $_header;
    private $_message;
    private $_link;

    public function send_mail_activation($dest, $usr, $key, $path)
    {
      $this->_subject = "Activation of your account camagru";
      $this->_header = "From: admin@camagru.fr";
      $this->_link = $path . "activation.php?usr=".urlencode($usr)."&key=".urlencode($key);
      $this->_message = "
      Welcome on camagru and thank you for your registration,
      To activate your account, click on the link below or copy
      and paste into your internet browser.
      $this->_link.
      --------------
      This is an automated email, please do not respond.";
      return (mail($dest, $this->_subject, $this->_message, $this->_header));
    }

    public function send_mail_reset($dest, $usr, $new_pwd)
    {
      $this->_subject = "Your new password on camagru";
      $this->_header = "From: admin@camagru.fr";
      $this->_message = "
      Hello $usr please find here is your new password on camagru

      $new_pwd.

      --------------
      This is an automated email, please do not respond.";
      return (mail($dest, $this->_subject, $this->_message, $this->_header));
    }

    public function send_mail_comments($dest, $usr)
    {
      $this->_subject = "One of your photos was commented";
      $this->_header = "From: admin@camagru.fr";
      $this->_message = "
      One of your photos was commented by $usr.
      Go to your gallery for see the comment.

      --------------
      This is an automated email, please do not respond.";
      return (mail($dest, $this->_subject, $this->_message, $this->_header));
    }
}
?>
