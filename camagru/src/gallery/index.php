<?php
  session_start();
  include($_SERVER['DOCUMENT_ROOT'] . '/services/picture.php');
  include($_SERVER['DOCUMENT_ROOT'] . '/tools/picture.php');

  $pictures = addCommentsAndLikesInPictures(loadPictures(0, 5));
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
      if (empty($pictures)) {
        echo '<div id="notificationWrapper" class="is-display notification notification-margin has-text-centered is-danger">
                <button class="delete"></button>
                <strong>No pictures available</strong>
              </div>
              <div class="section has-text-centered">
                <img src="/src/profile/assets/default.png" style="width: 400px;">
              </div>';
      } else {
        echo '<div class="section is-section-margin" id="articleSection">';
                  displayPictures($pictures);
        echo    '</div>
              <div id="notificationWrapper" class="notification has-text-centered">
                <button class="delete"></button>
                <strong></strong>
              </div>
              <div class="section has-text-centered">
                <button id="submitButton" class="button is-primary is-outlined" onclick="loadMorePictures()">Load more pictures!</button>
              </div>';
      }
      include($_SERVER['DOCUMENT_ROOT'] . '/src/common/footer/index.html');
    ?>
  </body>
  <script defer src="https://use.fontawesome.com/releases/v5.0.7/js/all.js"></script>
  <script type="text/javascript" src="./actions.js"></script>   
  <script type="text/javascript" src="../common/actions.js"></script>   
  </html>