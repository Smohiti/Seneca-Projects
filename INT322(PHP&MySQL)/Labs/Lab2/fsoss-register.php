 <html>
 <head>
     <title>HTML Form Example</title>
     <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
     <link href="https://fonts.googleapis.com/css?family=Roboto+Mono" rel="stylesheet">
     <link rel="stylesheet" href="styles.css">
     
 </head>
 <body>

<div class="wrapper">
    <?php

        //Initialize and store variable
        $usernameError = "";
        $passwordError = "";
        $schoolError = "";
        $isValidInput = true;

        if($_POST){

            if($_POST['username'] == ""){
                $usernameError = '<- Enter a valid username';
                $isValidInput = false;
            }   
            if($_POST['password'] == ""){
                $passwordError = '<- Enter a valid password';
                $isValidInput = false;
            }   
            if($_POST['school'] == ""){
                $schoolError = '<- Enter a valid school';
                $isValidInput = false;
            }   

        }


    ?>
    
    <h3>Sign In Form</h3>
    <h5>Lab 2</h5>
    <br>

    <form method="POST" action="fsoss-register.php">
      <label for="username">Username:</label><input type="text" name="username" value="<?php if ($_POST) echo $_POST['username']; ?>">
      <span><?php if(!($isValidInput)) echo $usernameError ?>  </span> <br>
      <label for="password">Password: </label><input type="password" name="password" value="<?php if ($_POST) echo $_POST['password']; ?>"> 
      <span><?php if(!($isValidInput)) echo $passwordError ?>  </span> <br>
      <label for="school">&nbsp School: </label><input type="text" name="school" value="<?php if ($_POST) echo $_POST['school']; ?>"> 
      <span><?php if(!($isValidInput)) echo $schoolError ?>  </span> <br>
      <input type="submit" class="btn btn-primary" value="Submit">
     
    </form>


    <?php

		if($_POST && $isValidInput){

			$username = $_POST['username'];
			$password = $_POST['password'];
            $school = $_POST['school'];


            echo "Entered information";
			echo "<br/>Username: $username";
			echo "<br/>Password: $password ";
            echo "<br/>  School: $school ";
		}
	?>


    

   

        </div>
    

 </body>
 </html>

