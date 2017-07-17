 <html>
 <head>
     <title>Regex Form Validation</title>
    
     <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
     <link rel="stylesheet" href="https://bootswatch.com/readable/bootstrap.css">
     
     <link href="https://fonts.googleapis.com/css?family=Roboto+Mono" rel="stylesheet">
     <link rel="stylesheet" href="styles.css">
     
 </head>
 <body>

<div class="wrapper">
    <?php

        //Errors
        $postalCodeError = $courseCodeError = $phoneNumberError = "";
        //Regex Variables
        // Step 1 $postalRegex = '/^[A-Za-z]\d[A-Za-z]\d[A-Za-z]\d$'; 
        /* Step 2 $postalRegex = '/^[A-Za-z]\d[A-Za-z]\s?\d[A-Za-z]\d$/'; 
        /* Step 3 */ $postalRegex = '/^\s*([A-Za-z]\d[A-Za-z]\s?\d[A-Za-z]\d)\s*$/'; 
        /* Step 4 */ $courseRegex = '/^\s*([A-Z]{3}\d{3}[A-Z]{1,3})\s*$/';
        /* Step 5 $phoneRegex = '/^\s*(\d{3}-\d{3}-\d{4})\s*$/'; */
        /* Step 6 */ $phoneRegex = '/^\s*(\d{3}-\d{3}-\d{4}|[(]?\d{3}[)]?[\s]*\d{3}([\s]*|[-]?)\d{4})\s*$/';
        
        //Flags
        $isValidPostal = $isValidCourse = $isValidNumber = false;
        $isValidForm = false;

        if($_POST){

            if($_POST['postalCode'] == ""){
                $postalCodeError = '<- Must enter a postal code';
            }   
            else{
                $postalCode = $_POST['postalCode'];

                if(preg_match($postalRegex,$postalCode,$matches)){
                    $isValidPostal = true;
                    $postalCodeError = "<span style='border-bottom: 1px solid green;'>✓</span>";
                }   
                else{
                    $isValidPostal = false;
                    $postalCodeError = '<- Must be X9X9X9 or X9X 9X9';
                } 
                

            }
            if($_POST['courseCode'] == ""){
                $courseCodeError = '<- Must enter a course code'; 
            }   
            else{
                $courseCode = $_POST['courseCode'];

                if(preg_match($courseRegex,$courseCode,$matches)){
                    $isValidCourse = true;
                    $courseCodeError = "<span style='border-bottom: 1px solid green;'>✓</span>";
                }   
                else{
                    $isValidCourse = false;
                    $courseCodeError = '<- Must be XXX999X or XXX999XX or XXX999XXX';
                } 
                

            }
            if($_POST['phoneNumber'] == ""){
                $phoneNumberError = '<- Must enter a phone number';
            }   
            else{
                $phoneNumber = $_POST['phoneNumber'];

                if(preg_match($phoneRegex,$phoneNumber,$matches)){
                    $isValidNumber = true;
                    $phoneNumberError = "<span style='border-bottom: 1px solid green;'>✓</span>";
                }   
                else{
                    $isValidNumber = false;
                    $phoneNumberError = '<- Must be 999-999-9999 or 999 999 9999 or 999 999-9999 or 9999999999 or 999 9999999 or (999) 999-9999 or (999) 999 9999';
                } 
                

            }

            if($isValidCourse && $isValidNumber && $isValidPostal){
                $isValidForm = true;
            }
            else{
                $isValidForm = false;
            }

        }


    ?>
    
    <h3>Regex Validation</h3>
    <h5>Lab 3</h5>
    <br>

    <form method="POST" action="regexValidation.php">
      <label for="postalCode">&nbspPostal Code:</label><input type="text" name="postalCode" autofocus value="<?php if ($_POST & !($isValidForm)) echo $_POST['postalCode']; ?>">
      <?php if(!($isValidForm)) echo "<span>$postalCodeError</span>" ?> <br> 
      <label for="courseCode">&nbspCourse Code:</label><input type="text" name="courseCode" value="<?php if ($_POST & !($isValidForm)) echo $_POST['courseCode']; ?>"> 
      <?php if(!($isValidForm)) echo "<span>$courseCodeError</span>" ?>  <br> 
      <label for="phoneNumber">Phone Number: </label><input type="text" name="phoneNumber" value="<?php if ($_POST & !($isValidForm)) echo $_POST['phoneNumber']; ?>"> 
      <?php if(!($isValidForm)) echo "<span>$phoneNumberError</span>" ?>  <br> 
      <input type="submit" class="btn btn-primary" value="Submit">
     
    </form>


    <?php

		if($_POST && $isValidForm){

			$postalCode = $_POST['postalCode'];
			$courseCode = $_POST['courseCode'];
            $phoneNumber = $_POST['phoneNumber'];


            echo "<p style='border-bottom: 1px solid green;'>✓ Information is Valid</p>";
			echo "&nbspPostal Code: $postalCode";
			echo "<br/>&nbspCourse Code: $courseCode ";
            echo "<br/>Phone Number:  $phoneNumber ";
		}
	?>

   
    

   

        </div>
    

 </body>
 </html>

