<?php
    require_once "Mail.php";

  function connection() {
    $config = require($_SERVER['DOCUMENT_ROOT'] . '/config.php');
    $smtp = Mail::factory(
      'smtp',
      array (
        'host' => 'ssl://smtp.gmail.com',
        'port' => '465',
        'auth' => true,
        'username' => $config['gmail_user'],
        'password' => $config['gmail_passwd']
      )
    );
    return $smtp;
  }

  function sendAccountActivationEmail($to, $username, $activationToken) {
    $body = 'Welcome on camagru ' . $username . " and thanks for your registration\n" .
            "To activate your account, click on the link below or copy and paste it into your internet browser.\n" .
            'http://localhost:8080/src/authentication/confirm-email/controller.php?token=' . $activationToken . '&username=' . $username .
            "\n----------------------------------------\n" .
            "This is an automated email, please do not respond.\n" .
            'The Camagru Team.';
    $headers = array(
      'From' => 'Admin <admin@camagru.com>',
      'To' => $username . ' <' . $to . '>',
      'Subject' => 'Account activation!'
    );

    try {
      $smtp = connection();
      $mail = $smtp->send($to, $headers, $body);
    } catch (PEAR_Exception $e) {
      echo 'Request failled ' . $e->getMessage();
    }
  }

  function sendNewCommentEmail($to, $username, $commentatorUsername) {
    $body = 'Hello ' . $username . "!!\n" .
            'One of your picture was commented by ' . $commentatorUsername .
            "\n----------------------------------------\n" .
            "This is an automated email, please do not respond.\n" .
            'The Camagru Team.';
    $headers = array(
      'From' => 'Admin <admin@camagru.com>',
      'To' => $username . ' <' . $to . '>',
      'Subject' => 'New comment!'
    );

    try {
      $smtp = connection();
      $mail = $smtp->send($to, $headers, $body);
    } catch (PEAR_Exception $e) {
      echo 'Request failled ' . $e->getMessage();
    }
  }

  function sendPasswordReset($to, $username, $resetPwdToken){
    $body = 'Hi '.$username.", we have recieved a request to change your password.\n" .
            "To proceed, please click on the link below or copy and past it into your Internet browser.\n" .
            'http://localhost:8080/src/authentication/password/reset/index.php?token=' . $resetPwdToken . '&username=' . $username .
            "\n----------------------------------------\n" .
            "Too high to remember a multitude of weird passwords? Use 'pass' Unix tool :)\n" .
            "This is an automated email, please do not respond.\n" .
            'The Camagru Team.';
    $headers = array(
      'From' => 'Admin <admin@camagru.com>',
      'To' => $username . ' <' . $to . '>',
      'Subject' => 'Password Reset'
    );

    try {
      $smtp = connection();
      $mail = $smtp->send($to, $headers, $body);
    } catch (PEAR_Exception $e) {
      echo 'Request failled ' . $e->getMessage();
    }
  }
?>