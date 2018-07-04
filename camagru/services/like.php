<?php
    function countLikesByPictureId($pictureId) {
        include($_SERVER['DOCUMENT_ROOT'] . '/database/connect.php');

        try {
            $request = $cnx->prepare('SELECT COUNT(*) FROM likes WHERE pictureId = :pictureId');
            $request->bindValue(':pictureId', $pictureId, PDO::PARAM_INT);
            $request->execute();
        } catch (PDOException $e) {
            echo 'Request failled ' . $e->getMessage();
        }

        return ($request->fetchColumn());
    }

    function getLikesByPictureIdAndUsername($pictureId, $username) {
        include($_SERVER['DOCUMENT_ROOT'] . '/database/connect.php');

        try {
            $request = $cnx->prepare('SELECT * FROM likes WHERE pictureId = :pictureId AND username = :username');
            $request->bindValue(':pictureId', $pictureId, PDO::PARAM_INT);
            $request->bindValue(':username', $username, PDO::PARAM_STR);
            $request->execute();
        } catch (PDOException $e) {
            echo 'Request failled ' . $e->getMessage();
        }

        return ($request->fetch());
    }

    function createLike($pictureId, $username) {
        include($_SERVER['DOCUMENT_ROOT'] . '/database/connect.php');

        try {
            $request = $cnx->prepare('INSERT INTO likes VALUES
	        (
			  id,
	          :username,
	          :pictureId
            )');
            $request->bindValue(':username', $username, PDO::PARAM_STR);
            $request->bindValue(':pictureId', $pictureId, PDO::PARAM_INT);
            $request->execute();
        } catch (PDOException $e) {
            echo 'Request failled ' . $e->getMessage();
        }
    }
    
    function deleteLike($pictureId, $username) {
        include($_SERVER['DOCUMENT_ROOT'] . '/database/connect.php');

        try {
            $request = $cnx->prepare('DELETE FROM likes WHERE pictureId = :pictureId AND username = :username');
            $request->bindValue(':username', $username, PDO::PARAM_STR);
            $request->bindValue(':pictureId', $pictureId, PDO::PARAM_INT);
            $request->execute();
        } catch (PDOException $e) {
            echo 'Request failled ' . $e->getMessage();
        }
    }

?>