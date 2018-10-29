#include <ESP8266WiFi.h>
#include <ThingerESP8266.h>

#define USERNAME "HARICHOZHAN"
#define DEVICE_ID "dht11"
#define DEVICE_CREDENTIAL "************" // device credential detail

#define SSID "dj"
#define SSID_PASSWORD "0987654321"

ThingerESP8266 thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);
#include "DHT.h"        
#define DHTTYPE DHT11  

#define dht_dpin 0
DHT dht(dht_dpin, DHTTYPE); 
void setup(void)
{ 
  dht.begin();
  Serial.begin(9600);
  Serial.println("Humidity and temperature\n\n");
  delay(1000);
    float h = dht.readHumidity();
    float t = dht.readTemperature();         
    Serial.print("Current humidity = ");
    Serial.print(h);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(t); 
    Serial.println("C  ");
  delay(1000);
  thing.add_wifi(SSID, SSID_PASSWORD);
  thing["temperature"] >> outputValue(dht.readTemperature());
  thing["humidity"] >> outputValue(dht.readHumidity());
}
void loop() {
  thing.handle();  
}
