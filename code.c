#include "WiFi.h"
#include <PubSubClient.h>

int ledPin = 19;
int digitalPin = 21;
int val = 0;
const char* ssid = "Wokwi-GUEST";
const char* password = "";
const char* mqtt_server = "broker.mqttdashboard.com";
void setup() {
Serial.begin(9600);
Serial.print("Connecting to WiFi");
WiFi.begin("Wokwi-GUEST", "");
while (WiFi.status() != WL_CONNECTED){
delay(100);
Serial.print(".");
}
Serial.println(" Connected!");
Serial.print("IP address: ");
Serial.println(WiFi.localIP());

pinMode(ledPin, OUTPUT); 
pinMode(digitalPin, INPUT);
}
 
void loop() {
val = digitalRead(digitalPin);


if (val == 1) { 
digitalWrite(ledPin, HIGH); 
Serial.println("มีคนกำลังมา"); 

}
else {
digitalWrite(ledPin, LOW); // สั่งให้ LED ดับ
}
delay(1000);
}