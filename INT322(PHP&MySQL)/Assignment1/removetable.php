<html>
 <head>
     <title>Add Table</title>
    
     <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
     <link rel="stylesheet" href="https://bootswatch.com/readable/bootstrap.css">
     <link href="https://fonts.googleapis.com/css?family=Roboto+Mono" rel="stylesheet">
     
     
 </head>
 <body>

<?php

//Removing table
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

if (mysqli_connect_errno()){
        echo "Connection failed -> " . mysqli_connect_error();
}
$sql_query="DROP TABLE product";
if (mysqli_query($conn, $sql_query)){
echo "Table removed successfully";
}
else{
echo "Error encountered while removing the table : " . mysqli_error($conn);
}


?>
<br>
<a class="btn btn-info" href="assign1.php" role="button">Go Back</a>
</body>
</html>