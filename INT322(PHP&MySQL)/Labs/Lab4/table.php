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
<h3>MySQL & PHP - Database</h3>
    <h5>Lab 4</h5>
    <br>
<?php

            //Display info in a table
            $servername = 'localhost';
            $dbusername = 'root';
            $dbpassword = '';
            $dbname = 'lab4';
            $conn = new mysqli ($servername,$dbusername,$dbpassword,$dbname);     
            // get all records from db
			$sql_query = "SELECT * from fsossregister ORDER BY ID";
			$result = mysqli_query($conn, $sql_query) or die('Query failed: '. mysqli_error($conn));
			if($result)
			{	
				// show records
				if (mysqli_num_rows($result) > 0) 
				{
					// table header
                    echo "<p style='border-bottom: 1px solid green;'>Table</p>";
					echo "<table border='2px solid black'>" .
					     "<tr>" . 
                            "<td>ID</td>" . 
						   "<td>First Name</td>" . 
						   "<td>Last Name</td>" . 
						   "<td>Gender</td>" . 
						   "<td>T-Shirt Size</td>" . 
						   "<td>Multiple Yes</td>" . 
						   "<td>Multiple No</td>" . 
						   "<td>Amount</td>" . 
                           "<td>Cancel</td>" . 
						   
						 "</tr>";
							  
					// show each row
                    $totalAmount = 200;
                    
					while($row = mysqli_fetch_assoc($result)) 
					{
						
						$totalAmount = $totalAmount - $row["Amount"];
						$id = $row["ID"];
						$cancelURL = "cancel.php?id=$id&dbpassword=$dbpassword";

						echo "<tr>" . 
                               "<td>" . $row["ID"] . "</td>" . 
					     	   "<td>" . $row["First_Name"] . "</td>" . 
							   "<td>" . $row["Last_Name"] . "</td>" . 
							   "<td>" . $row["Sex"] . "</td>" . 
							   "<td>" . $row["Size"] . "</td>" . 
							   "<td>" . ($row["Multiple_Yes"] == true ? "yes" : "no") . "</td>" . 
							   "<td>" . ($row["Multiple_No"] == true ? "yes" : "no") . "</td>" . 
							   "<td>" . $row["Amount"] . "</td>" .
							   "<td><a href='$cancelURL'>Cancel</a></td>" .
							 "</tr>";
					}
						
					echo "</table>";
                    echo "<p>Remaining T-Shirts:$totalAmount</p>";
				} 
				else 
					echo "No data in the database.";
			}

            $conn->close();

		
	?>

        
        <a class="btn btn-info" href="fsosstshirt.php" role="button">Go Back</a>
        </div>
    
     
 </body>
 </html>