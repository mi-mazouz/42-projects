<?php
    session_start();
    if ($_SESSION['isLogged']) header('Location: /index.php')
?>

<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/bulma/0.7.1/css/bulma.min.css">
    <link rel="stylesheet" type="text/css" media="screen" href="./style.css" />
    <link rel="stylesheet" type="text/css" media="screen" href="/src/common/footer/style.css" />
    <title>Camagru</title>
  </head>
  <body>
    <div id="notificationWrapper" class="notification has-text-centered">
      <button class="delete"></button>
      <strong></strong>
    </div>
    <div class="section">
      <div class="logo has-text-centered">
        <figure class="image">
          <img src="/src/common/header/assets/logo.png">
        </figure>
      </div>
    </div>
    <div class="want-to-sign-in has-text-centered">
      <a href="/src/authentication/signin">Want to sign in?</a>
    </div>
    <div class="section">
      <div class="container">
        <div class="columns">
          <div class="column is-half is-offset-one-quarter">
            <form action="javascript:forgotPassword()" enctype="multipart/form-data">
              <div class="field">
                <div class="control has-icons-left">
                  <input id="email" class="input" maxlength="32" type="email" placeholder="Email">
                  <span class="icon is-small is-left">
                    <i class="fas fa-envelope"></i>
                  </span>
                </div>
              </div>
              <div class="has-text-centered">
                <button id="submitButton" type="submit" class="button submit-button is-rounded">Send</button>
              </div>
            </form>
          </div>
        </div>
      </div>
    </div>
    <?php
      include($_SERVER['DOCUMENT_ROOT'] . '/src/common/footer/index.html');
    ?>
  </body>
  <script defer src="https://use.fontawesome.com/releases/v5.0.7/js/all.js"></script>
  <script type="text/javascript" src="./actions.js"></script>
  <script type="text/javascript" src="../../../common/actions.js"></script>
</html>
