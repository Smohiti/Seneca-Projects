

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
	<h3>Lab 5 - Protected Stuff</h3>
	<h5>Lab 5</h5>
	<hr/>


	<?php

session_start();

// check if user is logged in, if not redirect to login page
if(isset($_SESSION['isLogged']) && $_SESSION['isLogged']){
	echo "<h5>You are logged in!</h5>";
	echo "<h5>Now you can see the secret stuff</h5>";
	echo "<img src='https://d30y9cdsu7xlg0.cloudfront.net/png/36874-200.png'>";
}else{
	header('Location: login.php');
}
?>

	<form method="post" action="protectedstuff.php">
	  <br />
      <a class="btn btn-warning" href="logout.php">Logout</a>
	</form>

	</div>
</body>
</html>
