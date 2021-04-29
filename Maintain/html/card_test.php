<?php

/*
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/esp32-esp8266-mysql-database-php/
*/

$servername = "localhost";

// REPLACE with your Database name
$dbname = "phpmyadmin";
// REPLACE with Database user
$username = "phpmyadmin";
// REPLACE with Database user password
$password = "00000000";

// Keep this API Key value to be compatible with the ESP32 code provided in the project page. 
// If you change this value, the ESP32 sketch needs to match
$api_key_value = "tPmAT5Ab3j7F9";

$api_key= $tableNum = $sum = $payment = $recharge = "";

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $api_key = test_input($_POST["api_key"]);
    if($api_key == $api_key_value) {
        $tableNum = test_input($_POST["tableNum"]);
        $sum = test_input($_POST["sum"]);
        $payment = test_input($_POST["payment"]);
        $recharge = test_input($_POST["recharge"]);
        
        
        // Create connection
        $conn = new mysqli($servername, $username, $password, $dbname);
        // Check connection
        if ($conn->connect_error) {
            die("Connection failed: " . $conn->connect_error);
        } 
        
        $sql = "INSERT INTO SensorData (sensor, location, value1, value2, value3)
        VALUES ('" . $tableNum . "', '" . $sum . "', '" . $payment . "', '" . $recharge . "')";
        
        if ($conn->query($sql) === TRUE) {
            echo "New record created successfully";
        } 
        else {
            echo "Error: " . $sql . "<br>" . $conn->error;
        }
    
        $conn->close();
    }
    else {
        echo "Wrong API Key provided.";
    }

}
else {
    echo "No data posted with HTTP POST.";
}


function test_input($data) {
    $data = trim($data);
    $data = stripslashes($data);
    $data = htmlspecialchars($data);
    return $data;
}

