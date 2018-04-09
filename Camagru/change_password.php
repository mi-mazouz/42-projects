<?php
    include('Config/setup.php');
    include('class.php');
    session_start();

    if (!empty($_POST))
    {
      $request = new Request;
      $cmd = $cnx->prepare("SELECT username, password FROM users WHERE username = :usr");
      $cmd->bindValue(':usr', $_SESSION['usr'], PDO::PARAM_STR);
      $cmd->execute();
      if (strcmp($_POST['new_pwd'], $_POST['confirm_pwd']) === 0)
      {
          $result = $cmd->fetch();
          if (!empty($result['username']) && password_verify($_POST['old_pwd'], $result['password']) !== false)
          {
            $pwd = password_hash($_POST['confirm_pwd'], PASSWORD_BCRYPT);
            $request->update_pwd($cnx, $pwd, $_SESSION['usr']);
          }
          else
            http_response_code(401);
      }
      else
          http_response_code(400);
    }
    else
    {
        header("Location: index.php");
        exit;
    }
?>
