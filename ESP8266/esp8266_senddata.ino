#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <Wire.h>
#include <DHT.h>
#include <MQ135.h>
#define ANALOGPIN D8
int PPMStatus = 0;
int PPMStatusOld = 0;

float  airTemperature, airHumidity, ppm, ppmbalanced, rzero;
int initStep=1;                 // 1 = Connection in progress / 2 = Connection Done 

MQ135 gasSensor = MQ135(ANALOGPIN);

// Replace with your network credentials
const char* ssid     = "vivo";
const char* password = "00000000";

// REPLACE with your Domain name and URL path or IP address with path
const char* serverName = "http://192.168.43.211/post-esp-data.php";

// Keep this API Key value to be compatible with the PHP code provided in the project page. 
// If you change the apiKeyValue value, the PHP file /post-esp-data.php also needs to have the same key 
String apiKeyValue = "tPmAT5Ab3j7F9";

String sensorName = "Angel";
String sensorLocation = "myroom";

int smokeA0 = D0;
// Your threshold value
int sensorThres = 500;

#define SEALEVELPRESSURE_HPA (1013.25)
#define DHTPIN D1
#define DHTTYPE DHT11

DHT dht(DHTPIN,DHTTYPE,11);  // I2C


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

  pinMode(smokeA0, INPUT);
  // (you can also pass in a Wire library object like &Wire2)
  dht.begin();

}

void loop() {
  //Check WiFi connection status
  if(WiFi.status()== WL_CONNECTED){
    HTTPClient http;
    
    // Your Domain name with URL path or IP address with path
    http.begin(serverName);
    
    // Specify content-type header
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    ppm = gasSensor.getPPM(); // 取得 ppm 值
    int analogSensor = analogRead(smokeA0);
    
    // Prepare your HTTP POST request data
    String httpRequestData = "api_key=" + apiKeyValue + "&sensor=" + sensorName
                          + "&location=" + sensorLocation + "&value1=" + String(dht.readTemperature()) +"°C"
                          + "&value2=" + String(dht.readHumidity()) + "%" + "&value3="  + String(gasSensor.getPPM() ) +"ppm";
    Serial.print("httpRequestData: ");
    Serial.println(httpRequestData);
    
    // You can comment the httpRequestData variable above
    // then, use the httpRequestData variable below (for testing purposes without the BME280 sensor)
    //String httpRequestData = "api_key=tPmAT5Ab3j7F9&sensor=BME280&location=Office&value1=24.75&value2=49.54&value3=1005.14";

    // Send HTTP POST request
    int httpResponseCode = http.POST(httpRequestData);
     
    // If you need an HTTP request with a content type: text/plain
    //http.addHeader("Content-Type", "text/plain");
    //int httpResponseCode = http.POST("Hello, World!");
    
    // If you need an HTTP request with a content type: application/json, use the following:
    //http.addHeader("Content-Type", "application/json");
    //int httpResponseCode = http.POST("{\"value1\":\"19\",\"value2\":\"67\",\"value3\":\"78\"}");
        
    if (httpResponseCode>0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
    }
    else {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
    }
    // Free resources
    http.end();
  }
  else {
    Serial.println("WiFi Disconnected");
  }
  //Send an HTTP POST request every 30 seconds
  delay(30000);  
}
