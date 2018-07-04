<?php
  function createPicture($username, $path) {
    include($_SERVER['DOCUMENT_ROOT'] . '/database/connect.php');

    try {
      $request = $cnx->prepare('INSERT INTO pictures (path, username) VALUES
      (
        :path,
        :username
      )');
      $request->bindValue(':username', $username, PDO::PARAM_STR);
      $request->bindValue(':path', $path, PDO::PARAM_STR);
      $request->execute();
    } catch (PDOException $e) {
      echo 'Request failled ' . $e->getMessage();
    }
  }

  function loadPictures($offset, $limit) {
    include($_SERVER['DOCUMENT_ROOT'] . '/database/connect.php');
   
    try {
      $request = $cnx->prepare('SELECT * FROM pictures ORDER BY id DESC LIMIT :offset, :limit');
      $request->bindValue(':offset', $offset, PDO::PARAM_INT);
      $request->bindValue(':limit', $limit, PDO::PARAM_INT);
      $request->execute();
    } catch (PDOException $e) {
      echo 'Request failled ' . $e->getMessage();
    }
    
    return ($request->fetchAll());
  }

  function deletePictureById($pictureId, $username) {
    include($_SERVER['DOCUMENT_ROOT'] . '/database/connect.php');
    
    try {
      $request = $cnx->prepare('DELETE FROM pictures WHERE id = :pictureId AND username = :username');
      $request->bindValue(':pictureId', $pictureId, PDO::PARAM_INT);
      $request->bindValue(':username', $username, PDO::PARAM_STR);
      $request->execute();
    } catch (PDOException $e) {
      echo 'Request failled ' . $e->getMessage();
    }
  }
?>