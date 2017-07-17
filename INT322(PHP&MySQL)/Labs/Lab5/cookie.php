<?php
date_default_timezone_set("America/Toronto");
//setcookie('visit', $_COOKIE['visit'] + 1);
if (!isset($_COOKIE['visit'])){
        setcookie("visit", 0);
}
else {
        setcookie("visit", $_COOKIE['visit'] + 1);
}


$valid = true;
$name  = $value = "";
$errName = $errValue = "";

if ($_POST)
{
	$name  = $_POST['name'];
	$value = $_POST['value'];

	if ($name == "")
	{
		$errName = "Error - please enter a name";
		$valid = false;
	}

	if ($value == "")
	{
		$errValue = "Error - please enter a value";
		$valid = false;
	}

	if ($valid)
	{
		setcookie($name, $value);
	}
}
?>

<html>
 <head>
     <title>Lab 5 - Cookie Creation</title>
    
     <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
     <link rel="stylesheet" href="https://bootswatch.com/readable/bootstrap.css">
     <link href="https://fonts.googleapis.com/css?family=Roboto+Mono" rel="stylesheet">
     <link rel="stylesheet" href="styles.css">
     
 </head>
<body>
	<div class="wrapper">
	<h3>Lab 5 - Cookie Creator</h3>
	<h5>Lab 5</h5>
	<hr />
	<form method="post" action="">
		
				<label for="name">Name : </label><input type="text" name="name" value="<?php echo $name; ?>" /></br>
				<?php echo $errName; ?>
			
				
				<label for="value">Value: </label><input type="text" name="value" value="<?php echo $value; ?>" /></br>
				<?php echo $errValue; ?>
			
				<input class="btn btn-primary" type="submit" /> 
				
				
				
	</form>
	
	
	
	<?php

		//Reset to 0
		if(isset($_GET['logout'])) {
			setcookie('visit', $_COOKIE['visit'] - $_COOKIE['visit']);
			header('Location: cookie.php');
			exit;
		}

		//Remove all cookies
		if(isset($_GET['all'])) {
				if (isset($_SERVER['HTTP_COOKIE'])) {
					//exploding on an array with delimer ;
					$cookies = explode(';', $_SERVER['HTTP_COOKIE']);
					foreach($cookies as $cookie) {
						//exploding with delimeter =
						$parts = explode('=', $cookie);
						//trim everyhting
						$name = trim($parts[0]);
						setcookie($name, '', time()-1000);
						setcookie($name, '', time()-1000, '/');
					}
				}
			setcookie('visit', $_COOKIE['visit'] - $_COOKIE['visit']);
			header('Location: cookie.php');
			exit;
		}

		if (isset($_COOKIE['visit']))
			echo "Welcome back - you visited this page  " . $_COOKIE['visit'] . " times. <br />";

	?><br>
<div class="buttons">
	<a class="btn btn-warning btn-sm" href="?logout">Reset Visits</a>
	<a class="btn btn-danger btn-sm" href="?all">Remove All Cookies</a>
	</div>
	
	<br />
	<h4>Cookie Jar</h4>
	
	<table border="1">
		<tr>
			<th>Name</th>
			<th>Value</th>
		</tr>
		<?php
			foreach($_COOKIE as $key => $value) {
  				echo "<tr>";
    			echo "<td>$key</td>";
    			echo "<td>$value</td>";
    			echo "</tr>";
			}
		?>
	</table>
	</div>

</body>
</html>
