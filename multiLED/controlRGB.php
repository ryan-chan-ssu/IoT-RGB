<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>RGB LED Control</title>
</head>
<body>
    <?php
    $filename = 'results.txt';
    $data = json_decode(file_get_contents($filename), true);

    $led1Red = $data['Node1']['LED1']['red'] ?? 0;
    $led1Green = $data['Node1']['LED1']['green'] ?? 0;
    $led1Blue = $data['Node1']['LED1']['blue'] ?? 0;

    $led2Red = $data['Node1']['LED2']['red'] ?? 0;
    $led2Green = $data['Node1']['LED2']['green'] ?? 0;
    $led2Blue = $data['Node1']['LED2']['blue'] ?? 0;
    ?>
    
    <h1>Set RGB Color for LED 1</h1>

    <form method="post" action="updateRGB.php">
    <label for="red1">Red (0-255): </label>
    <input type="range" id="red1" name="redValue1" min="0" max="255" value="0" oninput="this.nextElementSibling.value = this.value">
    <output><?php echo $led1Red; ?></output>
    <br><br>

    <label for="green1">Green (0-255): </label>
    <input type="range" id="green1" name="greenValue1" min="0" max="255" value="0" oninput="this.nextElementSibling.value = this.value">
    <output><?php echo $led1Green; ?></output>
    <br><br>

    <label for="blue1">Blue (0-255): </label>
    <input type="range" id="blue1" name="blueValue1" min="0" max="255" value="0" oninput="this.nextElementSibling.value = this.value">
    <output><?php echo $led1Blue; ?></output>
    <br><br>

    <h1>Set RGB Color for LED 2</h1>

    <label for="red2">Red (0-255): </label>
    <input type="range" id="red2" name="redValue2" min="0" max="255" value="0" oninput="this.nextElementSibling.value = this.value">
    <output><?php echo $led2Red; ?></output>
    <br><br>

    <label for="green2">Green (0-255): </label>
    <input type="range" id="green2" name="greenValue2" min="0" max="255" value="0" oninput="this.nextElementSibling.value = this.value">
    <output><?php echo $led2Green; ?></output>
    <br><br>

    <label for="blue2">Blue (0-255): </label>
    <input type="range" id="blue2" name="blueValue2" min="0" max="255" value="0" oninput="this.nextElementSibling.value = this.value">
    <output><?php echo $led2Blue; ?></output>
    <br><br>

    <input type="submit" value="Set Colors">
    </form>
    
    <br><br>
    <h3>Previous Colors</h3>
    <p>LED 1 - Red: <?php echo $led1Red; ?>, Green: <?php echo $led1Green; ?>, Blue: <?php echo $led1Blue; ?></p>
    <p>LED 2 - Red: <?php echo $led2Red; ?>, Green: <?php echo $led2Green; ?>, Blue: <?php echo $led2Blue; ?></p>
</body>
</html>
