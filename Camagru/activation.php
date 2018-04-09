<?php
  include('Config/setup.php');
  include('class.php');

  if (!empty($_GET))
  {
     $request = new Request;
     $cmd = $cnx->prepare("SELECT username, key_valid FROM users WHERE username = :usr AND key_valid = :key");
     $cmd->bindValue(':usr', $_GET['usr'], PDO::PARAM_STR);
     $cmd->bindValue(':key', $_GET['key'], PDO::PARAM_STR);
     $cmd->execute();
     $ret = $cmd->fetch();
     if ($ret['username'] !== NULL && $ret['key_valid'] !== NULL)
          $request->account_activation($_GET['usr'], $cnx);
  }
  header("Location: index.php");
?>
