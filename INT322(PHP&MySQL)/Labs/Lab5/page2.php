


<html>
 <head>
     <title>Lab 5 - Protected Stuff</title>
    
     <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
     <link rel="stylesheet" href="https://bootswatch.com/readable/bootstrap.css">
     
     <link href="https://fonts.googleapis.com/css?family=Roboto+Mono" rel="stylesheet">
     <link rel="stylesheet" href="styles.css">
     
 </head>
<body>
	<div class="wrapper">
	<h3>Lab 5 - Sessions</h3>
	<h5>lab 5</h5>
	<hr/>

<?php

session_start();

// Check if the user is logged in or redirect on the contrary
if(isset($_SESSION['isLogged']) && $_SESSION['isLogged']){
	echo "Session Number:" . $_SESSION['isLogged'] . " present.";
}else{
	//Redirect
	header('Location: login.php');
}
?>


	</div>
</body>
</html>