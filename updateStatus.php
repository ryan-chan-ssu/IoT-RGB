<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Get the LED status from the form submission
    $status = $_POST['ledStatus'] ?? 'off'; // Default to "off" if not set

    // Read the current contents of results.txt to retain RGB values
    $fileContents = file_get_contents("results.txt");
    $data = $fileContents ? json_decode($fileContents, true) : [];

    // Initialize data structure if results.txt is empty or unreadable
    if ($data === null) {
        $data = ["Node1" => ["LED1" => ["status" => $status, "red" => 0, "green" => 0, "blue" => 0]]];
    } else {
        // Update only the LED status field
        $data["Node1"]["LED1"]["status"] = $status;
    }

    // Save the updated data back to results.txt
    file_put_contents("results.txt", json_encode($data));

    // Display a confirmation message
    echo "LED status updated to: " . strtoupper($status);
}
?>
