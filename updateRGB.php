<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Get the RGB values from the form submission, defaulting to 0 if not set
    $red = isset($_POST['redValue']) ? (int)$_POST['redValue'] : 0;
    $green = isset($_POST['greenValue']) ? (int)$_POST['greenValue'] : 0;
    $blue = isset($_POST['blueValue']) ? (int)$_POST['blueValue'] : 0;

    // Read the current contents of results.txt to retain the LED status
    $fileContents = file_get_contents("results.txt");
    $data = $fileContents ? json_decode($fileContents, true) : [];

    // Initialize data structure if results.txt is empty or unreadable
    if ($data === null) {
        $data = ["Node1" => ["LED1" => ["status" => "off", "red" => $red, "green" => $green, "blue" => $blue]]];
    } else {
        // Update only the RGB values
        $data["Node1"]["LED1"]["red"] = $red;
        $data["Node1"]["LED1"]["green"] = $green;
        $data["Node1"]["LED1"]["blue"] = $blue;
    }

    // Save the updated data back to results.txt
    file_put_contents("results.txt", json_encode($data));

    // Display a confirmation message
    echo "RGB values updated: Red = $red, Green = $green, Blue = $blue";
}
?>
