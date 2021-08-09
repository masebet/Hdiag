#define BLYNK_PRINT Serial
#define BLYNK_DEBUG

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "DnZ1dBEFNXZF-lGYXH9QZGVEyw3ItDwQ";
char ssid[] = "beat";
char pass[] = "beat2013";

uint8_t dataPesan[16]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02};
uint8_t a = 0;

//WidgetLED led1(V7);//setatus mesin
//WidgetLED led2(V8);//status setandar

BLYNK_READ(V0){//rpm
  uint16_t rpm = ((uint16_t) dataPesan[0] << 8) | dataPesan[1];
  Serial.print("RPM ");Serial.println(rpm);
  Blynk.virtualWrite(V0, rpm);
}
BLYNK_READ(V1){//bateray
  float vbat = (float) dataPesan[4]/10;
  Serial.print("baterai ");Serial.println(vbat);
  Blynk.virtualWrite(V1, vbat);
}
BLYNK_READ(V2){//suhu oli
  float soli = (float) dataPesan[3]-40.0;
  Serial.print("suhu oli ");Serial.println(soli);
  Blynk.virtualWrite(V2, soli);
}
BLYNK_READ(V3){//lebar pulsa injektor
  float lPulsa = (float)dataPesan[5];
  lPulsa += (float)dataPesan[6]/0xff;
  Serial.print("lebar pulsa ");Serial.println(lPulsa );
  Blynk.virtualWrite(V3, lPulsa);
}
BLYNK_READ(V4){//campuran bahan bakar
  float cBahan =  ((float) dataPesan[8]/0xff)* 2.0;
  Serial.print("campuran bahan ");Serial.println(cBahan);
  Blynk.virtualWrite(V4, cBahan);
}
BLYNK_READ(V5){//sensor oksigen
  float sOksi =  ((float) dataPesan[7]/0xff)* 5.0;
  Serial.print("sensor oksigen ");Serial.println(sOksi);
  Blynk.virtualWrite(V5, sOksi);
}
BLYNK_READ(V6){//sensor tps
  float tps = (float) dataPesan[2]/2;
  Serial.print("TPS ");Serial.println(tps);
  Blynk.virtualWrite(V6, tps);
}
BLYNK_READ(V7){
//  if( dataPesan[9] == 0x00 )led1.off();
//  else led1.on();
  Blynk.virtualWrite(V7, dataPesan[9]);
}
BLYNK_READ(V8){
//  if( dataPesan[10]== 0x00 )led2.off();
//  else led2.on();
  Blynk.virtualWrite(V8, dataPesan[10]);
}

void setup(){
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}

void loop(){
  Blynk.run();
  int i =0;
  while(Serial.available()>0){
    a = Serial.read();
    dataPesan[i++] = a;
  }
}
