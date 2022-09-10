#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <Wire.h>

// Network credentials
const char* ssid     = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";

// Domain name and URL path
const char* serverName = "http://192.168.xxx.xxx:80/esp_sensor_data/esp_data.php";

String apiKeyValue = "abc123";

int ThermistorPin = 0;

/*thermistor parameters:
 * RT0: 5 kΩ
 * B: 3470 K +- 0.75%
 * T0:  25 C
 * +- 5%
 */
 
//These values are in the datasheet
#define RT0 5000    // Ω
#define B 3470      // K
//-------------------------------------

#define VCC 3.3  //Supply voltage
#define R 1000   //R=1KΩ

//Variables
float RT, VR, ln, TX, T0, VRT;
String payload;

void setup() {
  Serial.begin(115200);
  
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) { 
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
  T0 = 25 + 273.15;
}

void loop() {
  //Check WiFi connection status
  if(WiFi.status()== WL_CONNECTED){
    WiFiClient client;
    HTTPClient http;
    
    // Domain name with URL path or IP address with path
    http.begin(serverName);
    
    // Specify content-type header
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");

    VRT = analogRead(ThermistorPin);   //Analog value of VRT
    Serial.print(VRT);
    
    VRT = (3.00 / 1023.00) * VRT;      //Conversion to voltage
    VR = VCC - VRT;
    RT = VRT / (VR / R);               //Resistance of RT
  
    ln = log(RT / RT0);
    TX = (1 / ((ln / B) + (1 / T0)));  //Temperature from thermistor
  
    TX = TX - 273.15;             //Conversion to Celsius

    Serial.print(" ");
    Serial.print(VRT);
    Serial.print(" Temperature: "); 
    Serial.print(TX);
    Serial.println(" °C"); 
    
    // HTTP POST request data
    String httpRequestData = "api_key=" + apiKeyValue + "&temperature=" + TX + "";
    Serial.print("httpRequestData: ");
    Serial.println(httpRequestData);
    
    int httpResponseCode = http.POST(httpRequestData);
        
    if (httpResponseCode>0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
    }
    else {
      Serial.print("Error code: ");
      Serial.println(http.errorToString(httpResponseCode).c_str());
    }

    // Free resources
    http.end();
  }
  else {
    Serial.println("WiFi Disconnected");
  }
  
  //Send an HTTP POST request every 10 seconds
  delay(10000);  
}
