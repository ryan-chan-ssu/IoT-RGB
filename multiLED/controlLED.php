<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>LED Control</title>
</head>
<body>
    <h1>Control LED Status</h1>
    
    <?php
    $filename = 'results.txt';
    $data = json_decode(file_get_contents($filename), true);

    $led1Status = $data['Node1']['LED1']['status'] ?? 'off';
    $led2Status = $data['Node1']['LED2']['status'] ?? 'off';
    ?>
    
    <form method="post" action="updateStatus.php">
        <!-- Checkbox control for LED 1 -->
        <h2>LED 1</h2>
        <label>
            <input type="checkbox" name="ledStatus1" value="on">
            Turn ON
        </label>

        <!-- Checkbox control for LED 2 -->
        <h2>LED 2</h2>
        <label>
            <input type="checkbox" name="ledStatus2" value="on">
            Turn ON
        </label>

        <br><br>
        <input type="submit" value="Submit Change">
    </form>
    
    <br><br>
    <h3>Previous Status</h3>
    <p>LED 1: <?php echo ucfirst($led1Status); ?></p>
    <p>LED 2: <?php echo ucfirst($led2Status); ?></p>
</body>
</html>
