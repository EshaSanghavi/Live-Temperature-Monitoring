<!DOCTYPE html>
<html>
<head>
    <title>Temperature Data</title>
    <style type="text/css">
        body{
            font-family: Arial, sans-serif;
        }
        h1{
            margin-left: 20px;
        }

        table{
            width: 90%;
            margin: auto;
            margin-top: 40px;
            align-self: center;
        }

        table, th, td{
            padding: 10px;
            border-collapse: collapse;
            border: 1px solid #000;
        }
    </style>
</head>

<body>
    <h1>Temperature Sensor Data</h1>
    <hr>
    <table id="data" class="data">
        <tr>
            <th>Timestamp</td>
            <th>Temperature</td>
        </tr>
        <?php

        $servername = "localhost";
        $dbname = "esp_sensor_data";
        $username = "YOUR_USERNAME";
        $password = "YOUR_PASSWORD";

        // Create connection
        $conn = new mysqli($servername, $username, $password, $dbname);
        // Check connection
        if ($conn->connect_error) {
            die("Connection failed: " . $conn->connect_error);
        }

        $sql = "SELECT reading_time, temperature_data FROM esp_sensor_data ORDER BY reading_time DESC";

        if ($result = $conn->query($sql)) {
            while ($row = $result->fetch_assoc()) {
                $temperature = $row["temperature_data"];
                $time = $row["reading_time"];
                echo '<tr> 
                <td>'.$time.'</td> 
                <td>'.$temperature.' °C</td> 
              </tr>';
            }

            $result->free();
        }

        $conn->close();
        ?>
    </table>
</body>

</html>
