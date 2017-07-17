<html>
 <head>
     <title>testDB</title>
     <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
     <link rel="stylesheet" href="https://bootswatch.com/readable/bootstrap.css">
     <link href="https://fonts.googleapis.com/css?family=Roboto+Mono" rel="stylesheet">
     <link rel="stylesheet" href="styles.css">
     
     
 </head>
 <body>
 
<div class="wrapper">
<h3>Lab 6 - Test Database</h3>
<h5>Lab 6</h5>

<?php

require "myClasses.php";
$show   = "SELECT itemName, price FROM product;";
$remove = "DELETE FROM product WHERE itemName='LG V10';";
$insert = "INSERT INTO product VALUES ('0000000009','HTC M10','1.0','android','700.00');";
$update = "UPDATE product SET itemName= 'Samsung S8' where itemName ='Samsung S7';";
echo "<h5>Trying SELECT, DELETE, INSERT & UPDATE through PHP Classes</h5>";
//PRINTING TABLE (small sample)
$mysqli = new DBLink();
echo "<h5>Printing all Devices</h5>";
echo "<br>There is " . $mysqli->isEmptyResult($result = $mysqli->query($show)) . " devices on the table<br>";
$result = $mysqli->query($show);
printResults($result);

echo "<h5 style='color:red'>Let's DELETE the LG V10</h5> & <h5 style='color:green'>INSERT the HTC M10"."</h5>";
$mysqli->query($remove);
$mysqli->query($insert);

echo "<h5>Printing all Devices</h5>";
$result = $mysqli->query($show);
printResults($result);

echo "<h5 style='color:blue'>UPDATE the Samsung S7 to the Samsung S8</h5>";
$mysqli->query($update);

echo "<h5>Final Table</h5>";
$result = $mysqli->query($show);
printResults($result);

?>

<?php
function printResults($results){
?>
<br>
<table class="table table-hover">
      <tr>
        <th>Phone</th>
        <th>Price</th>
      </tr>
      <?php while($row = mysqli_fetch_assoc($results))  { ?>
      <tr>
    <td><?php echo $row['itemName']?></td>
    <td><?php echo "$" . $row['price']?></td>
</tr>
      <?php } ?>
      </tr>
  </table>
  <br>

<?php 
    }
?>


</div>

</body>
</html>
