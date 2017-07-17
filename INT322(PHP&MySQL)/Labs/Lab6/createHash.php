<?php 
//Declaring variables
$hashConversion = "";
$showHash = false;

if($_POST)
{
	if(isset($_POST['pass']) && isset($_POST['salt']))
	{
		$hashConversion = crypt($_POST['pass'], $_POST['salt']);
		$showHash = true;
	}
}
?>

<!DOCTYPE html>
<html>
  <head>
    <title>Lab 6 - Create Hash Password</title>
  	<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
    <link rel="stylesheet" href="https://bootswatch.com/readable/bootstrap.min.css">
    <link href="https://fonts.googleapis.com/css?family=Roboto+Mono" rel="stylesheet">
    <link rel="stylesheet" href="styles.css">
     
 </head>

  <body>
		<div class="wrapper">
		<h3>Lab 6 - Hashed Passwords</h3>
		<h5>Lab 6</h5>
    <h5>Generate hashed password</h5>
	<form action="createHash.php" method="post">
	  <label>Enter a password</label>
	  <input type="text" name="pass" id="pass" />
	  <br /><br>
		<h6>Default salt is 123456789 - is also the salt on the login.php page</h6>
	  <label>Enter the salt for encryption</label>
	  <input type="text" name="salt" id="salt" value="123456789"/>
	  <br />
	  <input class="btn btn-success" type="submit" name="submit" id="submit" />

		<a class="btn btn-danger" href="login.php">Go Back</a>
	</form>
	
	<?php if($showHash) echo "Hashed password => " . $hashConversion; ?>
	</div>
  </body>
</html>