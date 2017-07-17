<?php

	// get passed field
	$id = $_GET['id'];
	$password = $_GET['password'];

	// other part of the info for server access
    $servername = 'localhost';
    $dbusername = 'root';
    $dbname = 'lab4';

	// connect 
    $conn = new mysqli ($servername, $dbusername, $password, $dbname)
     	    	or die('Could not connect: ' . mysqli_error($link));
				



	// uncheck multiple_yes and multiple_no
	$sql_query = "update fsossregister 
                  set Multiple_Yes=0, Multiple_No=0 
                  where ID=$id";
	$result = mysqli_query($conn, $sql_query) or die('Query failed: '. mysqli_error($conn));
	
	// go back to table
	header("Location: fsosstshirt.php?cancelled=true");
?>