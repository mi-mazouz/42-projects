<?php
  session_start();
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
    <?php
      include($_SERVER['DOCUMENT_ROOT'] . '/src/common/header/index.php');
    ?>
    <div class="section is-section-margin">
      <div class="container">
        <div class="columns is-centered">
          <div class="column is-10">
            <div class="header is-spaced">
              <h1 class="title is-4">Montage</h1>
            </div>
            <div class="columns">
              <div class="is-relative column is-8">
                <loader class="loader"></loader>
                <figure class="image">
                  <video playsinline></video>
                </figure>
                <figure class="image is-stackable">
                  <img id="selectedImg">
                </figure>
                <figure class="image">
                  <img id="uploadedImg">
                </figure>
              </div>
              <div class="column">
                <div id="facesDropDown" class="dropdown">
                  <div class="dropdown-trigger">
                    <button class="button" aria-haspopup="true" aria-controls="dropdown-menu">
                      <span>Faces</span>
                      <span class="icon is-small">
                        <i class="fas fa-angle-down" aria-hidden="true"></i>
                      </span>
                    </button>
                  </div>
                  <div class="dropdown-menu" role="menu">
                    <div class="dropdown-content">
                      <img src="/src/profile/assets/faces/elon.png" onClick="onClick(this)">
                      <img src="/src/profile/assets/faces/trump.png" onClick="onClick(this)">
                      <img src="/src/profile/assets/faces/morty.png" onClick="onClick(this)">
                      <img src="/src/profile/assets/faces/gang.png" onClick="onClick(this)">
                      <img src="/src/profile/assets/faces/kim.png" onClick="onClick(this)">
                      <img src="/src/profile/assets/faces/rick.png" onClick="onClick(this)">
                    </div>
                  </div>
                </div>
                <div id="glassesDropDown" class="dropdown">
                  <div class="dropdown-trigger">
                    <button class="button" aria-haspopup="true" aria-controls="dropdown-menu">
                      <span>Glasses</span>
                      <span class="icon is-small">
                        <i class="fas fa-angle-down" aria-hidden="true"></i>
                      </span>
                    </button>
                  </div>
                  <div class="dropdown-menu" role="menu">
                    <div class="dropdown-content">
                      <img src="/src/profile/assets/glasses/sun.png" onClick="onClick(this)">
                      <img src="/src/profile/assets/glasses/see.png" onClick="onClick(this)">
                      <img src="/src/profile/assets/glasses/sport.png" onClick="onClick(this)">
                      <img src="/src/profile/assets/glasses/3d.png" onClick="onClick(this)">
                    </div>
                  </div>
                </div>
                <div id="fruitsDropDown" class="dropdown">
                  <div class="dropdown-trigger">
                    <button class="button" aria-haspopup="true" aria-controls="dropdown-menu">
                      <span>Fruits</span>
                      <span class="icon is-small">
                        <i class="fas fa-angle-down" aria-hidden="true"></i>
                      </span>
                    </button>
                  </div>
                  <div class="dropdown-menu" role="menu">
                    <div class="dropdown-content">
                      <img src="/src/profile/assets/fruits/raspberry.png" onClick="onClick(this)">
                    </div>
                  </div>
                </div>
                <div class="file">
                  <button id="takePicture" type="submit" disabled class="button is-width is-primary is-outlined" onclick="takePicture()">Shot</button>
                  <label class="file-label">
                    <input class="file-input" type="file" onChange="uploadFile()">
                    <span class="file-cta">
                      <span class="file-icon">
                        <i class="fas fa-upload"></i>
                      </span>
                      <span class="file-label">
                        Upload
                      </span>
                    </span>
                  </label>
                </div>
              </div>
            </div>
          </div>
          <div class="column is-vh">
            <div class="header is-spaced">
              <h1 class="title is-4">Preview</h1>
            </div>
            <div id="picturesList" class="columns is-multiline is-pictures-list">
            </div>
            <footer class="pitures-list-footer">
              <a href="/src/gallery" class="see-in-the-gallery">See in the gallery!</a>
            </footer>
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
  <script type="text/javascript" src="./events.js"></script>   
</html>
