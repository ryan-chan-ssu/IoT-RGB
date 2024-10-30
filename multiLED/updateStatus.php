<?php
// Enable error reporting for debugging
ini_set('display_errors', 1);
ini_set('display_startup_errors', 1);
error_reporting(E_ALL);

// Determine LED 1 status: if not set in POST, default to 'off'
$status1 = isset($_POST['ledStatus1']) ? $_POST['ledStatus1'] : 'off';

// Determine LED 2 status: if not set in POST, default to 'off'
$status2 = isset($_POST['ledStatus2']) ? $_POST['ledStatus2'] : 'off';

// Read current JSON data from results.txt
$filename = 'results.txt';
$jsonData = file_get_contents($filename);
$data = json_decode($jsonData, true);

// Update status for LED 1 and LED 2 in JSON structure
$data['Node1']['LED1']['status'] = $status1;
$data['Node1']['LED2']['status'] = $status2;

// Write the updated JSON data back to results.txt
file_put_contents($filename, json_encode($data, JSON_PRETTY_PRINT));

// Confirmation messages
echo "LED 1 Status: $status1<br>";
echo "LED 2 Status: $status2";
?>
