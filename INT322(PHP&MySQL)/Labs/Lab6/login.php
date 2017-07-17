<?php

include_once("myClasses.php");

$dataValid = true;
$salt = "123456789";    
$password = "";
$email = "";
$errorPassword = "";
$errorEmail = "";
$errorLoginFail = "";

/* Paste on mysql

create table users (
username varchar(100) not null,
password blob not null,
role enum('user','admin') not null,
passwordHint varchar(100),
primary key (username)
);

//Non Hashed
insert into users values ('james@server.com','secret','user',"shh, don't tell anyone");
//Hashed
insert into users values ('james@server.com','12FJgqDtVOg7Q','user',"shh, don't tell anyone");

*/

//Start connecting to WAMP
$data = file('topsecret_wamp.txt');
$servername = trim($data[0]);
$dbusername = trim($data[1]);
$dbpassword = trim($data[2]);
$dbname     = trim($data[3]);
$conn       = new mysqli ($servername,$dbusername,$dbpassword,$dbname);

//Connect to Zenit
/*$data = file('/home/int322_171d16/secret/topsecret_zenit');
$servername = trim($data[0]);
$dbusername =  trim($data[1]);
$dbpassword = trim($data[2]);
$dbname     = trim($data[3]);
$conn = mysqli_connect($servername,$dbusername,$dbpassword,$dbname) or die ('Can not connect: ' . mysqli_error($data));*/

if ($_POST){
	
			
	if ($_POST['email'] == ""){
		$errorEmail = "<span style='border-bottom: 1px solid red;'> Error => you must fill in an user</span>";
		
		$dataValid = false;
	}

	if ($_POST['password'] == ""){
		$errorPassword = "<span style='border-bottom: 1px solid red;'> Error => you must fill in a password</span>";
		
		$dataValid = false;
	}

	//If Validations passes
	if ($_POST && $dataValid){

		$errorPassword = "";
		$errorEmail = "";
		$email = $_POST['email'];
		$password = $_POST['password'];
		
		$sql = "SELECT * FROM users";
		$query = mysqli_query($conn, $sql) or die('Query Failed => '. mysqli_error($mysqli));

		if($query){
			//Fetching data and checking for equal username and password
			if(mysqli_num_rows($query)>0){

				while($row = mysqli_fetch_assoc($query)){

					if($row['username'] == $email && $row['password'] == crypt($password,$salt)){


						$emailSent = "";
						$errorLoginFail = "";
						// create session
						session_start();
						$_SESSION['isLogged'] = true;
						$_SESSION['username'] = $user;

						// redirect to protectedstuff page
						header('Location: protectedstuff.php?user=' . $user);	
						break;


					}
					else{
						$errorLoginFail = "<span style='border-bottom: 1px solid red;'> ^ Wrong username or password ^</span>";
						
					}

				}

			}
			else{
				
				echo "No results from the database";
			}
		}
	}


	}


	




?>

<html>
 <head>
     <title>Lab 6 - Hashed Passwords</title>
    
     <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
     <link rel="stylesheet" href="https://bootswatch.com/readable/bootstrap.css">
     
     <link href="https://fonts.googleapis.com/css?family=Roboto+Mono" rel="stylesheet">
     <link rel="stylesheet" href="styles.css">
     
 </head>
<body>
	<div class="wrapper">
	<h3>Lab 6 - Hashed Passwords</h3>
	<h5>Lab 6</h5>

	<h2>Login</h2>
	<hr/>
	<form class="form-horizontal" method="post" action="">
		
		
		
		<div class="form-group">
		<label class="col-sm-3 control-label" for="email">Email:</label>
		<div class="col-sm-9">
		<input class="form-control" type="text" name="email" value="<?php echo $email; ?>" />
		<?php echo $errorEmail; ?>
		</div>
		
		</div>
		

		<?php if (!isset($_GET['forgot'])) { ?>

		<div class="form-group">
		<label class="col-sm-3 control-label" for="password">Password:</label>
		<div class="col-sm-9">
		<input class="form-control" type="password" name="password" value="<?php echo $password; ?>" />
		<?php echo $errorPassword; ?>
		</div>
		
		</div>
		

		<?php } ?>

		<br><?php echo $errorLoginFail; ?><br>
		<input class="btn btn-primary "type="submit" value="Submit" />
		<a class="btn btn-success" href="createHash.php"  />Generate Hash Password<a></br>
		
				
			
			
		
	
	</form>
	</div>
<body>
</html>
