<?php


$servername = "localhost";

// REPLACE with your Database name
$dbname = "phpmyadmin";
// REPLACE with Database user
$username = "phpmyadmin";
// REPLACE with Database user password
$password = "00000000";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);
// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}



$sql = "SELECT id, sensor, location, value1, value2, value3, reading_time FROM SensorData where sensor ='Red' order by CHAR_LENGTH(ID) desc";




if ($result = $conn->query($sql)) {
    while ($row = $result->fetch_assoc()) {
        $row_id = $row["id"];
        $row_sensor = $row["sensor"];
        $row_location = $row["location"];
        $row_value1 = $row["value1"];
        $row_value2 = $row["value2"]; 
        $row_value3 = $row["value3"]; 
        $row_reading_time = $row["reading_time"];
        // Uncomment to set timezone to - 1 hour (you can change 1 to any number)
        //$row_reading_time = date("Y-m-d H:i:s", strtotime("$row_reading_time - 1 hours"));
      
        // Uncomment to set timezone to + 4 hours (you can change 4 to any number)
        //$row_reading_time = date("Y-m-d H:i:s", strtotime("$row_reading_time + 4 hours"));
        
        //$a = $row_value2;
        
        //$a = $a[count($a)-1];
        
        
        
      
        echo  $row_id .' ' . $row_sensor . ' ' . $row_location . ' ' . $row_value1 . ' ' . $row_value2 . ' ' . $row_value3 . ' ' . $row_reading_time .',';
        
        
              
    }
    
    //$a = array($row_value2);
    //$a = $a[count($a)-1];
    
    //file_put_contents("/var/www/html/avg_h.txt", $a); 
      
    
    $result->free();
}





$conn->close();
?>