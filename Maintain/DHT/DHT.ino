#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#define DHTPIN 14     // 5 = GPIO5 Digital pin connected to the DHT sensor (ESP8266 D1!!!)
#define DHTTYPE    DHT11     // DHT 11

DHT dht(DHTPIN, DHTTYPE);


void setup(){
  // Serial port for debugging purposes
  Serial.begin(115200);
  dht.begin();
}

void loop() 
{
    float newT = dht.readTemperature();
      Serial.print("Temperature");
      Serial.print(newT);
      Serial.print("\t");
    
    float newH = dht.readHumidity();
      Serial.print("Humidity");
      Serial.print(newH);
      Serial.print("\t");
      delay(2000);
      Serial.print("\n");
}
