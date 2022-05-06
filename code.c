#include "WiFi.h"
#include <PubSubClient.h>
#include <TridentTD_LineNotify.h>
#define LINE_TOKEN "hcvqqk838Ciq3HQO7YpjkpapV5p0LxxS095Hhsrrxvt"
//39a7K8TR4FVecoAvstsMXLz92xAu09ROOBCMe1MiBg1
//hcvqqk838Ciq3HQO7YpjkpapV5p0LxxS095Hhsrrxvt
int ledPin = 22;
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
Serial.print("LINE_TOKEN = ");
Serial.println(LINE_TOKEN);
pinMode(ledPin, OUTPUT); // sets the pin as output
pinMode(digitalPin, INPUT); // sets the pin as input
}
 
void loop() {
val = digitalRead(digitalPin); //อ่านค่าสัญญาณ digital ขา8 ที่ต่อกับเซ็นเซอร์
Serial.print("val = "); // พิมพ์ข้อมความส่งเข้าคอมพิวเตอร์ "val = "
Serial.println(val); // พิมพ์ค่าของตัวแปร val
LINE.setToken(LINE_TOKEN);
if (val == 1) { // ค่า เป็น 0 ตรวจจับเจอวัตถุ สั่งให้ไฟ LED ติด
digitalWrite(ledPin, HIGH); // สั่งให้ LED ติดสว่าง

LINE.notify("มีคนกำลังมา");
delay(10000);
}
else {
digitalWrite(ledPin, LOW); // สั่งให้ LED ดับ
}

}