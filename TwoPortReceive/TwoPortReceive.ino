#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11,1); // RX, TX

void setup() {
  Serial.begin(9600);
  mySerial.begin(10400);
}

uint8_t buffer1[] = "haloo";
uint8_t buffer2[] = "hal";
uint8_t buffer3[] = "helo";

uint8_t openDt[] = {0xfe,0x04,0x72,0x8c};
uint8_t pesan[]  = {0x72,0x05,0x73,0x00,0x16};
uint8_t pesan1[] = {0x72,0x05,0x73,0x01,0x15};
uint8_t pesan2[] = {0x72,0x05,0x74,0x01,0x14};
uint8_t pesan3[] = {0x72,0x07,0x72,0xd1,0x00,0x06,0x3e};
uint8_t pesan4[] = {0x72,0x07,0x72,0x20,0x00,0x02,0xf3};
uint8_t pesan5[] = {0x72,0x07,0x72,0x17,0x00,0x0f,0xef};
uint8_t pesan6[] = {0x72,0x07,0x72,0xd0,0x00,0x0e,0x37};

void printHex(uint8_t num) {
  char hexCar[2];
  sprintf(hexCar, "0X%02X", num);
  Serial.print(hexCar);
  Serial.print(" ");
}


void balasOpenDt(){
  mySerial.write(0x0e);
  mySerial.write(0x04);
  mySerial.write(0x72);
  mySerial.write(0x7c);
}
void balasPesan(){
    mySerial.write(0x02);
  mySerial.write(0x07);
  mySerial.write(0x73);
  mySerial.write(0x00);
  mySerial.write(0x00);
      mySerial.write(0x00);
  mySerial.write(0x84);
}
void balasPesan1(){
      mySerial.write(0x02);
  mySerial.write(0x0c);
  mySerial.write(0x73);
  mySerial.write(0x01);
  mySerial.write(0x00);
      mySerial.write(0x00);
  mySerial.write(0x00);
  mySerial.write(0x00);
  mySerial.write(0x00);
  mySerial.write(0x00);
      mySerial.write(0x00);
  mySerial.write(0x7e);

}
void balasPesan2(){
      mySerial.write(0x02);
  mySerial.write(0x0c);
  mySerial.write(0x74);
  mySerial.write(0x01);
  mySerial.write(0x00);
      mySerial.write(0x00);
  mySerial.write(0x00);
  mySerial.write(0x00);
  mySerial.write(0x00);
  mySerial.write(0x00);
      mySerial.write(0x00);
  mySerial.write(0x7d);
}
void balasPesan3(){
      mySerial.write(0x02);
  mySerial.write(0x0c);
  mySerial.write(0x72);
  mySerial.write(0xd1);
  mySerial.write(0x00);
      mySerial.write(0x00);
  mySerial.write(0x00);
  mySerial.write(0x00);
  mySerial.write(0x00);
  mySerial.write(0x00);
      mySerial.write(0x10);
  mySerial.write(0x9f);
}
void balasPesan4(){
    mySerial.write(0x02);
  mySerial.write(0x08);
  mySerial.write(0x72);
  mySerial.write(0x20);
  mySerial.write(0x00);
      mySerial.write(0xc4);
  mySerial.write(0x80);
  mySerial.write(0x20);
}
void balasPesan5(){
   mySerial.write(0x02);
  mySerial.write(0x15);
  mySerial.write(0x72);
  mySerial.write(0x17);
  mySerial.write(0x00);
   mySerial.write(0x00);
  mySerial.write(0x00);
  mySerial.write(0x19);
  mySerial.write(0x00);
  mySerial.write(0x95);
   mySerial.write(0x43);
  mySerial.write(0xff);
  mySerial.write(0xff);
  mySerial.write(0xff);
  mySerial.write(0xff);
   mySerial.write(0x70);
  mySerial.write(0x00);
  mySerial.write(0x00);
  mySerial.write(0x80);
  mySerial.write(0x84);
   mySerial.write(0xff);

}
void balasPesan6(){
       mySerial.write(0x02);
  mySerial.write(0x14);
  mySerial.write(0x72);
  mySerial.write(0xd0);
  mySerial.write(0x00);
        mySerial.write(0x00);
  mySerial.write(0x00);
  mySerial.write(0x00);
  mySerial.write(0x00);
  mySerial.write(0x00);
        mySerial.write(0x00);
  mySerial.write(0x00);
  mySerial.write(0x00);
  mySerial.write(0x00);
  mySerial.write(0x00);
        mySerial.write(0x00);
  mySerial.write(0x00);
  mySerial.write(0x00);
  mySerial.write(0x00);
  mySerial.write(0xa8);
}

void loop() {
  int i = 0;
  if(Serial.available()>0){
    memset(buffer1, 0, sizeof(buffer1));   
  }
  while(Serial.available()>0){
    buffer1[i++] = Serial.read();
  }

  Serial.println((char*)buffer1);
  int na=memcmp ( buffer1, buffer2, sizeof(buffer2) );
  int nb=memcmp ( buffer1, buffer3, sizeof(buffer3) );
  
  int n =memcmp ( buffer1, pesan, sizeof(pesan) );
  int n1=memcmp ( buffer1, pesan1, sizeof(pesan1) );
  int n2=memcmp ( buffer1, pesan2, sizeof(pesan2) );
  int n3=memcmp ( buffer1, pesan3, sizeof(pesan3) );
  int n4=memcmp ( buffer1, pesan4, sizeof(pesan4) );
  int n5=memcmp ( buffer1, pesan5, sizeof(pesan5) );
  int n6=memcmp ( buffer1, pesan6, sizeof(pesan6) );
  
  if(na==0)Serial.println("aaa");
  if(nb==0)Serial.println("bbb");
 
 for(int i=0; i<sizeof(buffer1); i++){
    printHex(buffer1[i]);
 }

  delay(100);
  
}
