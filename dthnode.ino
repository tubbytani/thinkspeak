#include <ThingSpeak.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#include <ESP8266WiFi.h>
 
 const char *apikey = "x";
 unsigned long myChannelNumber = x;
 char ssid[] =  "x";     
 char pass[] =  "x";

WiFiClient client;

#define DHTPIN 0
#define DHTTYPE DHT11
DHT DHT(DHTPIN, DHTTYPE);

float t;
float h;
float c;
bool e;
void setup()
{
  Serial.begin(115200);
  delay(500);
  
  DHT.begin();
  t = DHT.readTemperature();
  h = DHT.readHumidity();
  c = DHT.computeHeatIndex(t, h);
  e = DHT.read();

   Serial.print("The temp is: ");
  Serial.println(t);
  Serial.print("The humidity is: ");
  Serial.println(h);
  Serial.print("The heat index is: ");
  Serial.println(c);
  Serial.print("sensor was read less than two seconds ago 1 for true 0 for false: ");
  Serial.println(e); 
  WiFi.begin(ssid, pass);
  ThingSpeak.begin(client);
  delay(500);
}

void loop()
{ 
 
  ThingSpeak.writeField(myChannelNumber, 2, h, apikey);
  delay(5000);
  ThingSpeak.writeField(myChannelNumber, 1, t, apikey);
   
  delay(500);
 
 

}
