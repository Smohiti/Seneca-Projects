<?php
//Starting session and destroying session
session_start();
session_destroy();
//Snippet to eliminate session
setcookie("PHPSESSID", "", time() - 61200,"/");
//Redirecting
header('Location: login.php');

?>