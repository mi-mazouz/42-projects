<?php
    session_start();
    if (!$_SESSION['isLogged']) header('Location: /index.php');
?>

<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/bulma/0.7.1/css/bulma.min.css">
    <link rel="stylesheet" type="text/css" media="screen" href="/src/common/footer/style.css" />
    <link rel="stylesheet" type="text/css" media="screen" href="./style.css" />
    <title>Camagru</title>
  </head>
  <body>
    <?php
        include($_SERVER['DOCUMENT_ROOT'] . '/src/common/header/index.php');
    ?>
    <div id="notificationWrapper" class="notification-margin notification has-text-centered">
      <button class="delete"></button>
      <strong></strong>
    </div>
    <div class="section">
      <div class="section">
        <div class="container">
          <div class="columns">
            <div class="column is-half is-offset-one-quarter">
              <div class="card">
                <div class="card-content">
                  <form action="javascript:update()" enctype="multipart/form-data">
                    <p class="subtitle has-text-centered">
                      Change your settings
                    </p>
                    <div class="field">
                      <label class="label">Username: <?php echo $_SESSION['username'] ?></label>
                      <div class="control has-icons-left">
                        <input id="username" class="input" maxlength="16" type="text" placeholder="New username">
                        <span class="icon is-small is-left">
                          <i class="fas fa-user"></i>
                        </span>
                      </div>
                    </div>
                    <div class="field">
                      <label class="label">Email: <?php echo $_SESSION['email'] ?></label>
                      <div class="control has-icons-left">
                        <input id="email" class="input" maxlength="32" type="email" placeholder="New email">
                        <span class="icon is-small is-left">
                          <i class="fas fa-envelope"></i>
                        </span>
                      </div>
                    </div>
                    <div class="field">
                      <label class="label">Password: ● ● ● ● ● ● ● ●</label>
                      <div class="control has-icons-left">
                        <input id="password" class="input" maxlength="32" type="password" placeholder="New password">
                        <span class="icon is-small is-left">
                          <i class="fas fa-lock"></i>
                        </span>
                      </div>
                    </div>
                    <label class="label">Mute comment notification:</label>
                    <div id="commentNotification" class="control">
                      <label class="radio">
                        <input
                          type="radio"
                          name="answer"
                          <?php
                            if ($_SESSION['commentNotification'] === '0') echo 'checked';
                          ?>
                        >
                        Yes
                      </label>
                      <label class="radio">
                        <input
                          type="radio"
                          name="answer"
                          <?php
                            if ($_SESSION['commentNotification'] === '1') echo 'checked'
                          ?>
                        >
                        No
                      </label>
                    </div>
                    <div class="has-text-centered">
                      <button id="submitButton" type="submit" class="button is-outlined is-primary">Update</button>
                    </div>
                  </form>
                </div>
              </div>
            </div>
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
  <script type="text/javascript" src="../common/actions.js"></script>
</html>