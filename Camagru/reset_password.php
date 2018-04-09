<?php
  include('Config/setup.php');
  include('class.php');

  if (!empty($_POST))
  {
    $cmd = $cnx->prepare("SELECT username, email FROM users WHERE username = :usr AND email = :email");
    $cmd->bindValue(':usr', $_POST['usr'], PDO::PARAM_STR);
    $cmd->bindValue(':email', $_POST['email'], PDO::PARAM_STR);
    $cmd->execute();
    if ($cmd->fetch() !== false)
    {
      $mail = new Mail;
      $request = new Request;
      $characts = 'afklzj4180BDPEMS';
      for($i = 0; $i < 16; $i++)
        $pwd .= $characts[rand()%strlen($characts)];
      if ($mail->send_mail_reset($_POST['email'], $_POST['usr'], $pwd) === true)
      {
          $pwd = password_hash($pwd, PASSWORD_BCRYPT);
          $request->update_pwd($cnx, $pwd, $_POST['usr']);
      }
      else
          http_response_code(400);
    }
    else
        http_response_code(401);
  }
  else
    header("Location: index.php");
?>
