<html>
 <head>
     <title>testMenu</title>
     <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
     <link rel="stylesheet" href="https://bootswatch.com/readable/bootstrap.css">
     <link href="https://fonts.googleapis.com/css?family=Roboto+Mono" rel="stylesheet">
     <link rel="stylesheet" href="styles.css">
     
 </head>
 <body>
 
<div class="wrapper">
<h3>Lab 6 - Test Menu</h3>
<h5>lab 6</h5>

<ul class="list-group">

 <?php

require "myClasses.php";
echo 'Passing this array to myClasses.php' . '<br><br>';
$items = array('Home','Features','About','Seneca','PHP');
echo var_dump($items) . '<br>';

$menu = new Menu($items);


?>

</ul>



</div>
</body>
</html>


