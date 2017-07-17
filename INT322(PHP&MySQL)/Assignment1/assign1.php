 <html>
 <head>
     <title>Assignment 1</title>
    
     <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
     <link rel="stylesheet" href="https://bootswatch.com/readable/bootstrap.css">
     
     <link href="https://fonts.googleapis.com/css?family=Roboto+Mono" rel="stylesheet">
     <link rel="stylesheet" href="styles.css">
     
 </head>
 <body>

<div class="wrapper">
<h3>Assignment 1 - PHP Comparison Tool</h3>
<h5>Assignment 1</h5>
<div class="buttons">
<a class="btn btn-success btn-sm" href="createtable.php" role="button">Add Data</a>
<a class="btn btn-danger btn-sm" href="removetable.php" role="button">Remove Data</a>
</div>
<br>
<?php
//Connect to the database using localhost
/*$servername = 'localhost';
$dbusername = 'root';
$dbpassword = '';
$dbname = 'assign1';
$conn = new mysqli ($servername,$dbusername,$dbpassword,$dbname);*/

//Connect to locahost
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

//Deleting previous table
$query = 'DELETE from product';
mysqli_query($conn, $query) or die ('Pls insert the data first');
//or die ('query did not work' . mysqli_error($conn));
				
//Getting data from each file
$phone = file('phone.txt');
$os    = file('os.txt');
$price = file ('price.txt');
$model = file ('model.txt');

//Inserting data
for($i = 0; $i < sizeof($phone); $i++){
		$query = 'INSERT INTO product set itemName = "'.trim($phone[$i]).'", model = "'.trim($model[$i]).'", os = "'.trim($os[$i]).'", price = "'.trim($price[$i]).'"'.';'; 
		//Running query and printing error in case
		mysqli_query($conn,$query) or die ('Error -> ' . mysqli_error($conn));
}



//validating all form information
$isValid      = true;
$phoneError   = "";
$minimumError = "";
$maximumError = "";

//If submit button has been pressed
if($_POST){
	//Validation with PHP for empty fields and minimum higher than maximum
	if($_POST['typeofphone'] == ""){
			$phoneError = "<span style='border-bottom: 1px solid red;'> <- Please choose a phone</span>";
			$isValid = false;		
	}
	if($_POST['pricemax'] == ""){
			$maximumError = "<span style='border-bottom: 1px solid red;'> <- Please choose a maximum</span>";
			$isValid = false;
	}
	if($_POST['pricemin'] == ""){
			$minimumError = "<span style='border-bottom: 1px solid red;'> <- Please choose a minimum</span>";
			$isValid = false;
	}
	if($_POST['pricemin'] != "" && $_POST['pricemax'] != ""){
	if($_POST['pricemin'] > $_POST['pricemax']){
		$minimumError = "<span style='border-bottom: 1px solid red;'> <- Minimum can't be bigger than maximum</span>";
		$isValid = false;
	}
	}
}
//If validation is passed
if($_POST && $isValid){
	$phoneError   = "";
	$minimumError = "";
	$maximumError = "";
	$maxprice = $_POST['pricemax'];
	$minprice = $_POST['pricemin'];
	$typeofphone = $_POST['typeofphone'];
	if($typeofphone == "all"){
		//Pull all phones
	$query = "SELECT * FROM product where price between $minprice AND $maxprice order by price desc ";
	}
	else{
		//Pull specific phones    
	$query = "SELECT * FROM product where os = '$typeofphone' AND price between $minprice AND $maxprice order by price desc";	
	}

	$request = mysqli_query($conn, $query) or die ('SELECT Query Failed: ' . mysqli_error($conn));
	

?>




<!--Printing table-->
<table border = "1">
<tr>
	<th>Phone</th>
	<th>OS</th>
	<th>Model</th>
	<th>Price (CAD)</th>
</tr>

<?php
//Start printing with while
$emptyFlag = 0;

//Printing Current Date
	$timeDatabase = "SELECT CURDATE()";
	$date = mysqli_query($conn, $timeDatabase) or die ('Error getting the date ' . mysqli_error($conn));
	$printDate = mysqli_fetch_assoc($date);
	echo "Query Date: " . $printDate['CURDATE()'];
	echo "<br><br><hr>";

while($row = mysqli_fetch_assoc($request)){
	$emptyFlag++;
?>
<tr>
    <td><?php echo $row['itemName']?></td>
    <td><?php echo $row['os']?></td>
    <td><?php echo $row['model']?></td>
    <td><?php echo "$" . $row['price']?></td>
	
</tr>

<?php
}


?>
</table>

<?php

if($emptyFlag==0){
	echo "--> Query Return is empty <--";
}

}else{
?>

<!--Form with repopulated fields-->
<form action="" method = "post">
<label for="typeofphone">Phone: </label><select name = "typeofphone">
			<option value="all">All</option>
			<option value="ios" <?php if($_POST & !($isValid)){if(isset($_POST['typeofphone'])){if($_POST['typeofphone'] == 'ios') echo "selected";}} ?> >iOS</option>
			<option value="android" <?php if($_POST & !($isValid)){if(isset($_POST['typeofphone'])){if($_POST['typeofphone'] == 'android') echo "selected";}} ?>>Android</option>
			<option value="blackberry" <?php if($_POST & !($isValid)){if(isset($_POST['typeofphone'])){if($_POST['typeofphone'] == 'blackberry') echo "selected";}} ?>>Blackberry</option>
			<option value="microsoft" <?php if($_POST & !($isValid)){if(isset($_POST['typeofphone'])){if($_POST['typeofphone'] == 'microsoft') echo "selected";}} ?>>Microsoft</option>
			
	</select>
<?php echo $phoneError;?>
<br/>
<br/>
<label for="pricemin">Minimum Price:</label><input type="number" name = "pricemin" value ="<?php if (isset($_POST['pricemin'])) echo $_POST['pricemin']; ?>">
<?php echo $minimumError;?>
<br />
<br />
<label for="pricemax">Maximum Price:</label><input type="number" name = "pricemax" value ="<?php if (isset($_POST['pricemax'])) echo $_POST['pricemax']; ?>">
<?php echo $maximumError;?>
<br/>
<br/>	
<input class="btn btn-primary btn-sm" type="submit" value="Submit">
</form>
</body>
</html>

<?php
}
?>