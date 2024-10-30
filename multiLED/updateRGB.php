<?php
// Enable error reporting for debugging
ini_set('display_errors', 1);
ini_set('display_startup_errors', 1);
error_reporting(E_ALL);

// Fetch status and RGB values for LED 1
$status1 = isset($_POST['status1']) ? $_POST['status1'] : 'off';
$red1 = isset($_POST['redValue1']) ? intval($_POST['redValue1']) : 0;
$green1 = isset($_POST['greenValue1']) ? intval($_POST['greenValue1']) : 0;
$blue1 = isset($_POST['blueValue1']) ? intval($_POST['blueValue1']) : 0;

// Fetch status and RGB values for LED 2
$status2 = isset($_POST['status2']) ? $_POST['status2'] : 'off';
$red2 = isset($_POST['redValue2']) ? intval($_POST['redValue2']) : 0;
$green2 = isset($_POST['greenValue2']) ? intval($_POST['greenValue2']) : 0;
$blue2 = isset($_POST['blueValue2']) ? intval($_POST['blueValue2']) : 0;

// Read current JSON data from results.txt
$filename = 'results.txt';
$jsonData = file_get_contents($filename);
$data = json_decode($jsonData, true);

// Update data for LED 1
$data['Node1']['LED1']['status'] = $status1;
$data['Node1']['LED1']['red'] = $red1;
$data['Node1']['LED1']['green'] = $green1;
$data['Node1']['LED1']['blue'] = $blue1;

// Update data for LED 2
$data['Node1']['LED2']['status'] = $status2;
$data['Node1']['LED2']['red'] = $red2;
$data['Node1']['LED2']['green'] = $green2;
$data['Node1']['LED2']['blue'] = $blue2;

// Write the updated JSON data back to results.txt
file_put_contents($filename, json_encode($data, JSON_PRETTY_PRINT));

// Confirmation message
echo "LED 1 - Status: $status1, RGB: ($red1, $green1, $blue1)<br>";
echo "LED 2 - Status: $status2, RGB: ($red2, $green2, $blue2)";
?>
