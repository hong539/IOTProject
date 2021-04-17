#include <ESP8266WiFi.h>
#include <PubSubClient.h>

void conWifi();
void conMQTT();

const char* ssid = "wifi ssid";                   // wifi ssid
const char* password =  "wifi password";         // wifi password
const char* mqttServer = "IP adress Raspberry Pi";    // IP adress Raspberry Pi
const int mqttPort = 1883;
const char* mqttUser = "";      // if you don't have MQTT Username, no need input
const char* mqttPassword = "";  // if you don't have MQTT Password, no need input

WiFiClient espClient;
PubSubClient client(espClient);

void setup() 
{

  Serial.begin(115200);
  conWifi();
  conMQTT();
  



//  client.publish("esp8266", "Hello Raspberry Pi");
//  client.subscribe("esp8266");

}

void callback(char* topic, byte* payload, unsigned int length) 
{

  Serial.print("Message arrived in topic: ");
  Serial.println(topic);

  Serial.print("Message:");
  for (int i = 0; i < length; i++) 
  {
    Serial.print((char)payload[i]);
  }

  Serial.println();
  Serial.println("-----------------------");

}

void loop() 
{
    client.publish("esp8266", "Hello Raspberry Pi");
    client.subscribe("esp8266");
    delay(300);
  client.loop();
}

void conWifi()
{
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");
};

void conMQTT()
{
    client.setServer(mqttServer, mqttPort);
  client.setCallback(callback);

  while (!client.connected()) 
  {
    Serial.println("Connecting to MQTT...");

    if (client.connect("ESP8266Client", mqttUser, mqttPassword )) 
    {

      Serial.println("connected");

    } else     
    {

      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);

    }
  }
};
