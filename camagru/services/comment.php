<?php
  function addComment($username, $date, $comment, $pictureId) {
      include($_SERVER['DOCUMENT_ROOT'] . '/database/connect.php');

      try {
        $request = $cnx->prepare('INSERT INTO comments VALUES
        (
          id,
          :username,
          :date,
          :text,
          :pictureId
        )');
        $request->bindValue(':username', $username, PDO::PARAM_STR);
        $request->bindValue(':date', $date, PDO::PARAM_STR);
        $request->bindValue(':text', $comment, PDO::PARAM_STR);
        $request->bindValue(':pictureId', $pictureId, PDO::PARAM_STR);
        $request->execute();
      } catch (PDOException $e) {
        echo 'Request failled ' . $e->getMessage();
      }
  }

  function loadCommentsByPictureId($pictureId) {
    include($_SERVER['DOCUMENT_ROOT'] . '/database/connect.php');

    try {
      $request = $cnx->prepare('SELECT * FROM comments WHERE pictureId = :pictureId');
      $request->bindValue(':pictureId', $pictureId, PDO::PARAM_INT);
      $request->execute();
    } catch (PDOException $e) {
      echo 'Request failled ' . $e->getMessage();
    }

    return ($request->fetchAll());
  }
?>