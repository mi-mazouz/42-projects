<?php
  session_start();

  function mergedPicture($picture, $stackableImage) {
  	$xpicture = imagesx($picture);
  	$ypicture = imagesy($picture);
  	$xStackableImage = imagesx($stackableImage);
    $yStackableImage = imagesy($stackableImage);
  	imagecopy(
      $picture,
      $stackableImage,
      $xpicture / 3.4,
      $ypicture / 7,
      0,
      0,
      $xStackableImage,
      $yStackableImage
    );
  	ob_start();
    imagejpeg($picture);
  	return (ob_get_clean());
  }

  function writePicture($picture, $filePath) {
    $directoryPath = '../../images/';
    $path = $directoryPath . $filePath;
    if (!file_exists($directoryPath)) mkdir($directoryPath, 0755, true);

    $file = fopen($path, 'w+');
    fputs($file, $picture);
    fclose($file);
  }

  function addCommentsAndLikesInPictures($pictures) {
    include($_SERVER['DOCUMENT_ROOT'] . '/services/comment.php');
    include($_SERVER['DOCUMENT_ROOT'] . '/services/like.php');

    foreach($pictures as $index => $picture) {
      $pictures[$index]['comments'] = loadCommentsByPictureId($picture['id']);
      $pictures[$index]['isLikedByMe'] = getLikesByPictureIdAndUsername($picture['id'], $_SESSION['username']);
      $pictures[$index]['likes'] = countLikesByPictureId($picture['id']);
    }

    return $pictures;
  }

  function displayPictures($pictures) {
    foreach($pictures as $index => $picture) {
      echo '<div id="picture-' . $picture['id'] . '" class="card is-margin-top ';
      if (!$_SESSION['isLogged']) echo 'is-comment-hidden ';
      echo  'is-card-container">
              <header class="card-header">
                <div class="card-header-icon">
                  <span class="icon">
                    <i class="fas fa-user"></i>
                  </span>
                </div>
                <p class="card-header-title">' .
                  $picture['username']
              . '</p>
              </header>';
      if ($_SESSION['isLogged']) echo '<div class="card-content">';
      echo    '<div class="card">
                  <div class="card-image">
                    <figure class="image">
                      <img src="/images/' . $picture['path'] . '">
                    </figure>
                  </div>
                  <footer class="card-footer">
                    <div class="card-footer-item">
                      <span id="likeIcon-' . $picture['id'] . '" class="icon '; if ($picture['isLikedByMe']) echo 'has-text-link';
      echo            ' is-small" style="cursor: pointer;">
                          <i class="fas fa-heart" onClick="postLike(' . $picture['id'] . ')"></i>
                         </span>
                         <strong id="likes-' . $picture['id'] . '" class="is-margin-left">' . $picture['likes'] . '</strong>
                       </div>';
                       if ($picture['username'] === $_SESSION['username']) echo '<div class="card-footer-item">
                         <a onClick=deletePicture(' . $picture['id'] . ') class="button is-outlined is-danger">Delete</a>
                       </div>';
      echo        '</footer>
                </div>';
      if ($_SESSION['isLogged']) {
        echo    '<div class="content">
                  <div class="header is-spaced">
                    <h1 class="title is-4">Comments</h1>
                  </div>
                  <div id="commentContainer-' . $picture['id'] . '" class="is-overflow-scroll">';
        foreach($picture['comments'] as $pictureComment) {
          echo    '<article class="media">
                      <div class="media-content">
                        <p>
                          <strong>' . $pictureComment['username'] . '</strong>
                        </p>
                        <p>' .
                          $pictureComment['text'] .
                        '</p>
                      </div>
                      <div class="media-right">
                        <button class="delete"></button>
                      </div>
                    </article>';
        }
        echo    '</div>
                  <div class="columns">
                    <div class="column is-8">
                      <textarea id="comment-' . $picture['id'] . '" class="textarea" placeholder="Add a comment..."></textarea>
                    </div>
                    <div class="column has-text-centered">
                      <button class="button is-primary is-outlined" onclick="postComment(' . $picture['id'] . ',`' . $_SESSION['username']. '`)">Post comment</button>
                    </div>
                  </div>
              </div>';
      }
      if ($_SESSION['isLogged']) echo '</div>';

      echo  '</div>';
    }
  }
?>