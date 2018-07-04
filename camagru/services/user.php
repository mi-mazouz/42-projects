<?php
	function updateUserByEmail ($email, $newUsername, $newEmail, $newPassword, $commentNotification) {
		include($_SERVER['DOCUMENT_ROOT'] . '/database/connect.php');

		try {
            $request = $cnx->prepare('UPDATE users SET username = :newUsername, email = :newEmail, password = :newPassword, commentNotification = :commentNotification WHERE email = :email');
			$request->bindValue(':newUsername', $newUsername, PDO::PARAM_STR);
			$request->bindValue(':newEmail', $newEmail, PDO::PARAM_STR);
			$request->bindValue(':newPassword', $newPassword, PDO::PARAM_STR);
			$request->bindValue(':commentNotification', $commentNotification, PDO::PARAM_STR);
			$request->bindValue(':email', $email, PDO::PARAM_STR);
			$request->execute();
		} catch (PDOException $e) {
			echo 'Request failled ' . $e->getMessage();
		}
	}
	
	function updateUserPasswordByEmail ($email, $newPassword) {
		include($_SERVER['DOCUMENT_ROOT'] . '/database/connect.php');

		try {
            $request = $cnx->prepare('UPDATE users SET password = :newPassword WHERE email = :email');
			$request->bindValue(':newPassword', $newPassword, PDO::PARAM_STR);
			$request->bindValue(':email', $email, PDO::PARAM_STR);
			$request->execute();
		} catch (PDOException $e) {
			echo 'Request failled ' . $e->getMessage();
		}
	}

    function getUserByUsernameOrEmail ($username, $email) {
        include($_SERVER['DOCUMENT_ROOT'] . '/database/connect.php');

        try {
            $request = $cnx->prepare('SELECT username, email, password, commentNotification, activationToken FROM users WHERE username = :username OR email = :email');
			$request->bindValue(':username', $username, PDO::PARAM_STR);
			$request->bindValue(':email', $email, PDO::PARAM_STR);
            $request->execute();
        } catch (PDOException $e) {
			echo 'Request failled ' . $e->getMessage();
		}
        return ($request->fetch());
    }

    function createUser ($username, $email, $password, $activationToken) {
        include($_SERVER['DOCUMENT_ROOT'] . '/database/connect.php');

        try {
			$request = $cnx->prepare('INSERT INTO users (username, email, password, activationToken) VALUES
	        (
	          :username,
	          :email,
	          :password,
			  :activationToken
	        )');
	        $request->bindValue(':username', $username, PDO::PARAM_STR);
	        $request->bindValue(':password', $password, PDO::PARAM_STR);
	        $request->bindValue(':email', $email, PDO::PARAM_STR);
			$request->bindValue(':activationToken', $activationToken, PDO::PARAM_STR);
	        $request->execute();
		} catch (PDOException $e) {
			echo 'Request failled ' . $e->getMessage();
		}
	}
	
	function getUserByPictureId($pictureId) {
		include($_SERVER['DOCUMENT_ROOT'] . '/database/connect.php');
	   
		try {
		  $request = $cnx->prepare('SELECT users.email, users.username, users.commentNotification FROM pictures JOIN users ON pictures.username = users.username AND pictures.id = :pictureId LIMIT 1');
		  $request->bindValue(':pictureId', $pictureId, PDO::PARAM_INT);
		  $request->execute();
		} catch (PDOException $e) {
		  echo 'Request failled ' . $e->getMessage();
		}
	
		return ($request->fetch());
	  }

	  function activeUserAccountByUsername($username) {
		include($_SERVER['DOCUMENT_ROOT'] . '/database/connect.php');

		try {
            $request = $cnx->prepare('UPDATE users SET activationToken = null WHERE username = :username');
            $request->bindValue(':username', $username, PDO::PARAM_STR);
            $request->execute();
        } catch (PDOException $e) {
            echo 'Request failed ' . $e->getMessage();
        }
	  }
?>