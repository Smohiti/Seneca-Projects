<?php
//Database
class DBLink{
    // Variables
    private $conn;
    private $result = "";

    // Functions
    //Connecting to the database
    public function __construct(){
        $this->conn = mysqli_connect('localhost','root','','lab6') or die ("Connection failed =>" . $this->conn->connect_error);
    }
    //Starting the query
    public function query($sql_query){
        $this->result = mysqli_query($this->conn,$sql_query); //or die ("Query failed =>" . $this->conn->connect_error);
        return $this->result;
    }
    //Checking if the result is empty
    public function isEmptyResult(){
        $empty = mysqli_num_rows($this->result);
        return $empty;
    }
    //Closing Connection
    public function __destruct(){
        mysqli_close($this->conn);
    }

} // End of DBLink

class Menu{
    
    // Functions
public function __construct($list){
    $flag = true;
    foreach($list as $item){
        
        if($flag){
        echo '<a href="#" class="list-group-item active">'
             .$item.'</a>'; 
        $flag = false;
        }
        else{
        echo '<a href="#" class="list-group-item">'
             .$item.'</a>';
        }
    }

}


} // End of Menu Class   





?>