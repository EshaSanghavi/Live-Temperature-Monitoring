# Live-Temperature-Monitoring
This is an IoT system to diplay real time measured temperatures. It even displays previously recorded temperatures day and month wise. 

## Execution
1. Import the esp_sensor_data.sql file in your database
2. Clone this repository.
3. Change your database credentials in esp_data.php and sensor_data.php
4. Change your network credentials and server name in esp_sketch.ino.
5. Store all the php files at /var/www/html/esp_sensor_data for linux or c:\inetpub\wwwroot\esp_sensor_data for windows.

## Hardware setup
1. Materials required-
    1. NodeMCU (Esp8266 wifi module)
    2. NTC 5k thermistor 
    3. 1 k ohm resistor
    4. Jumper wires
    5. Breadboard
    6. Power supply 
2. NTC thermistor is used for temperature sensing.
3. The thermistor and resistor are connected in series forming a voltage divider.
4. Output of this voltage divider is connected to analog input 0 of the ESP.
5. The Esp8266 is powered via a usb cable connected to the computer
6. Uplading the ino code to the NodeMCU-
    1. Open the ino file in Arduino IDE.
    2. Connect your NodeMCU to your computer using a usb cable.
    3. Select board as NodeMCU 0.9 and your posrt, under tool option.
    4. Verify and upload the sketch to the NodeMCU.

## Snapshots
### Webpage 
<kbd><img src="https://github.com/EshaSanghavi/Live-Temperature-Monitoring/blob/main/Snapshots/Screenshot%20from%202022-09-10%2000-08-22.png?raw=true"/></kbd>

### Database 
<kbd><img src="https://github.com/EshaSanghavi/Live-Temperature-Monitoring/blob/main/Snapshots/Screenshot%20from%202022-09-10%2000-08-43.png"/></kbd>
