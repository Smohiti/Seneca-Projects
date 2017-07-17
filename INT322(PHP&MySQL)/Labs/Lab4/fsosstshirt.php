 <html>
 <head>
     <title>PHP & MySQL</title>
    
     <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
     <link rel="stylesheet" href="https://bootswatch.com/readable/bootstrap.css">
     
     <link href="https://fonts.googleapis.com/css?family=Roboto+Mono" rel="stylesheet">
     <link rel="stylesheet" href="styles.css">
     
 </head>
 <body>

<div class="wrapper">
    <?php

        //Errors
        $firstNameError = $lastNameError = $orderAmountError = $sexError = $shirtError = "";
        
        //Flags
        $isValidName = $isValidLast = $isValidOrderAmount = $isValidSex = $isValidShirt = false;
        $isValidForm = false;

        if($_POST){

            if($_POST['firstName'] == ""){
                $firstNameError = '<- Must not be empty';
            }   
            else{
                $firstName = $_POST['firstName'];
                $isValidName = true;                    
            }
            if($_POST['lastName'] == ""){
                $lastNameError = '<- Must not be empty'; 
            }   
            else{
                $lastName = $_POST['lastName'];
                $isValidLast = true;
            }

            if(!isset($_POST['sex'])){
                $sexError = '<- Must select one'; 
            }   
            else{
                $sex = $_POST['sex'];
                $isValidSex = true;
            }

            if($_POST['orderAmount'] == ""){
                $orderAmountError = '<- Must not be empty';
            }   
            else{

                if(isset($_POST['multipleYes']) && isset($_POST['multipleNo'])){

                    if($_POST['orderAmount']<=200 && $_POST['orderAmount']>=1){
                        $orderAmount = $_POST['orderAmount'];
                        $isValidOrderAmount = true;
                    }
                    else{
                        $orderAmountError = '<- Must be between 1 and 200 if -> Yes and No selected';
                    }
                    
                }
                else if(!isset($_POST['multipleYes']) && !isset($_POST['multipleNo'])){

                    if($_POST['orderAmount']!=1){
                        $orderAmountError = '<- Must be 1 if -> Yes and No were not selected';
                    }
                    else{
                        $isValidOrderAmount = true;
                    }
                    
                }
                else if(isset($_POST['multipleNo'])){
                    
                    if($_POST['orderAmount']!=1){
                        $orderAmountError = '<- Must be 1 if -> No was selected';
                    }
                    else{
                        $isValidOrderAmount = true;
                    }
                    
                }
                else if(isset($_POST['multipleYes'])){

                    if($_POST['orderAmount']<=200 && $_POST['orderAmount']>=1){
                        $orderAmount = $_POST['orderAmount'];
                        $isValidOrderAmount = true;
                    }
                    else{
                        $orderAmountError = '<- Must be between 1 and 200 if -> Yes selected';
                    }

                } 

            }
            if($_POST['t-shirt'] == 'default'){
                $shirtError = '<- Choose one';
            }
            else{
                $isValidShirt = true;
            }


            if($isValidLast && $isValidOrderAmount && $isValidName && $isValidSex && $isValidShirt){
                $isValidForm = true;
            }
            else{
                $isValidForm = false;
            }

        }


    ?>
    
    <h3>MySQL & PHP</h3>
    <h5>Lab 4</h5>
    <br>

    <form method="POST" action="fsosstshirt.php">
      <label for="firstName">First Name:</label><input type="text" name="firstName" autofocus value="<?php if ($_POST & !($isValidForm)) echo $_POST['firstName']; ?>">
      <?php if(!($isValidForm)) echo "<span>$firstNameError</span>" ?> <br> 
      <label for="lastName">Last Name&nbsp:</label><input type="text" name="lastName" value="<?php if ($_POST & !($isValidForm)) echo $_POST['lastName']; ?>"> 
      <?php if(!($isValidForm)) echo "<span>$lastNameError</span>" ?>  <br> 
      <label for="sex">Gender:</label><?php if(!($isValidForm)) echo "<span>$sexError</span>" ?><br>


      Male:<input type="radio" name="sex" value="m" <?php if ($_POST & !($isValidForm)){
                                                            if (isset($_POST['sex'])){
                                                                if(($_POST['sex']) == "m") echo "checked";
                                                                }
                                                                } ?>>
      Female:<input type="radio" name="sex" value="f" <?php if ($_POST & !($isValidForm)){
                                                            if (isset($_POST['sex'])){
                                                                if(($_POST['sex']) == "f") echo "checked";
                                                                }
                                                                } ?>> <br>
      
      
      
      <label for="shirtSize">T-Shirt Size:</label>
        <select name="t-shirt">
	        <option name="default" value="default">--Please choose--</option>
	        <option name="small" value="small" <?php if($_POST & !($isValidForm)){if(isset($_POST['t-shirt'])){if($_POST['t-shirt'] == 'small') echo "selected";}} ?>>Small</option>
	        <option name="medium" value="medium" <?php if($_POST & !($isValidForm)){if(isset($_POST['t-shirt'])){if($_POST['t-shirt'] == 'medium') echo "selected";}} ?>>Medium</option>
	        <option name="large" value="large" <?php if($_POST & !($isValidForm)){if(isset($_POST['t-shirt'])){if($_POST['t-shirt'] == 'large') echo "selected";}} ?>>Large</option>
	        <option name="x-large" value="x-large" <?php if($_POST & !($isValidForm)){if(isset($_POST['t-shirt'])){if($_POST['t-shirt'] == 'x-large') echo "selected";}} ?>>X-Large</option>
	      </select> <?php if(!($isValidForm)) echo "<span>$shirtError</span>" ?> <br> 
      <label for="">Multiple T-Shirts:</label><br>
      

      
          Yes:<input name="multipleYes" type="checkbox" value="YES" <?php if($_POST & !($isValidForm)){if (isset($_POST['multipleYes'])) echo "checked"; }?>>
          No:<input name="multipleNo" type="checkbox" value="NO" <?php if($_POST & !($isValidForm)){if (isset($_POST['multipleNo'])) echo "checked"; }?>><br>
				
      <label for="orderAmount">Number to Order: </label><input id="orderCheck" type="number" name="orderAmount" value="<?php if ($_POST & !($isValidForm)) echo $_POST['orderAmount']; ?>"> 
      <?php if(!($isValidForm)) echo "<span>$orderAmountError</span>" ?>  <br> 
      <input type="submit" class="btn btn-primary" value="Submit">
      <a class="btn btn-success" href="table.php" role="button">See Table</a>
     
    </form>


    <?php

		if($_POST && $isValidForm){

			$firstName = $_POST['firstName'];
			$lastName = $_POST['lastName'];
            $orderAmount = $_POST['orderAmount'];
            $sex = ucfirst($_POST['sex']);
            $size = ucfirst($_POST['t-shirt']);
            $yesText = $noText = "";

            if(isset($_POST['multipleYes'])){
                $yes = 1;
                $yesText = "✓";
            }
            else{
                $yes = 0;
                $yesText = "✗";
            }
            if(isset($_POST['multipleNo'])){
                $no = 1;
                $yesText = "✓";
            }
            else{
                $no = 0;
                $noText = "✗";
            }
            


            echo "<p style='border-bottom: 1px solid green;'>✓ Information is Valid</p>";
			echo "First Name: $firstName";
			echo "<br/>Last Name&nbsp: $lastName";
            echo "<br/>Gender&nbsp: $sex";
            echo "<br/>Size:$size";
            echo "<br/>YES Selected:$yesText ";
            echo "<br/>NO Selected:$noText ";
            echo "<br/>Number to Order: $orderAmount <br>";

            


            //Start connecting
            $servername = 'localhost';
            $dbusername = 'root';
            $dbpassword = '';
            $dbname = 'lab4';

            //create connection
            $conn = new mysqli ($servername,$dbusername,$dbpassword,$dbname);

            //enter info
            $sql = "INSERT INTO fsossregister (First_Name, Last_Name, Sex, Size, Multiple_Yes, Multiple_No, Amount) VALUES ('$firstName','$lastName','$sex','$size','$yes','$no','$orderAmount')";

            if($conn->connect_error){
                die("Connection failed:" . $conn-> connect_error);
            }

            if($conn->query($sql)===TRUE){
                echo "Thank you, info entered";
                header('Location: table.php');
            }else{
                echo "Error:" .$sql . "<br>" . $conn->error;
            }

		}
	?>

   
    

   

        </div>
    
     
 </body>
 </html>

