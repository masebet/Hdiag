#include <time.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11,1); // RX, TX

void setup() {
  // initialize both serial ports:
  Serial.begin(9600);
  Serial2.begin(10400);
  mySerial.begin(10400);
  pinMode(7,OUTPUT);
  digitalWrite(7,1);
}

void loop() {
  open();
  data1();
  data2();
  data3();
  data4();
//  data00();
//  data01();
//  data02();
  delay(156);
  digitalWrite(7,1);
  delay(5000);
  delay(156);
  digitalWrite(7,1);
  delay(65);
  digitalWrite(7,0);
  delay(156);
}//
