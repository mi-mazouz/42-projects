<?php
  session_start();
  include('Config/setup.php');
  include('class.php');

  if (!empty($_POST))
  {
    $request = new Request;
    if ($request->check_usr_exist($cnx, $_POST['email'], $_POST['usr']) === false)
    {
      $mail = new Mail;
      $key = md5(microtime(TRUE) * 100000);
      if ($mail->send_mail_activation($_POST['email'], $_POST['usr'], $key, set_path_mail($_SERVER['HTTP_REFERER'])) !== false)
      {
        $pwd = password_hash($_POST['pwd'], PASSWORD_BCRYPT);
        $request->usr_registration($cnx, $_POST['usr'], $pwd, $_POST['email'], $key);
      }
      else
        http_response_code(400);
    }
    else
      http_response_code(401);
  }
  else
    header("Location: index.php");

  function set_path_mail($str)
  {
      $i = strlen($str);
      while ($str[$i - 1] !== '/')
          $i--;
      return (substr($str, 0, $i));
  }
?>
