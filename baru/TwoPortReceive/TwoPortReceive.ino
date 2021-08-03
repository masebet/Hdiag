#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11,1); // RX, TX

void setup() {
  Serial.begin(9600);
  mySerial.begin(10400);
}

uint8_t buffer1[20];
uint8_t buffer2[] = "hal";
uint8_t buffer3[] = "helo";

uint8_t openDt[] = {0xfe,0x04,0x72,0x8c};
uint8_t pesan[]  = {0x72,0x05,0x73,0x00,0x16}; //data00
uint8_t pesan1[] = {0x72,0x05,0x73,0x01,0x15}; //data01
uint8_t pesan2[] = {0x72,0x05,0x74,0x01,0x14}; //data02
uint8_t pesan3[] = {0x72,0x07,0x72,0xd1,0x00,0x06,0x3e}; //data4
uint8_t pesan4[] = {0x72,0x07,0x72,0x20,0x00,0x02,0xf3}; //data3
uint8_t pesan5[] = {0x72,0x07,0x72,0x17,0x00,0x0f,0xef}; //data2
uint8_t pesan6[] = {0x72,0x07,0x72,0xd0,0x00,0x0e,0x37}; //data1

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
 for(int i=0; i<sizeof(pesan); i++){mySerial.write(pesan[i]);}  
 uint8_t add[]={0x02,0x07,0x73,0x00,0x00,0x00,0x84};
 for(int i=0; i<sizeof(add); i++){mySerial.write(add[i]);}  
}
void balasPesan1(){
 for(int i=0; i<sizeof(pesan1); i++){mySerial.write(pesan1[i]);}  
 uint8_t add[]={0x02,0x0c,0x73,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7e};
 for(int i=0; i<sizeof(add); i++){mySerial.write(add[i]);}  
}
void balasPesan2(){
  for(int i=0; i<sizeof(pesan2); i++){mySerial.write(pesan2[i]);}  
 uint8_t add[]={0x02,0x0c,0x74,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7d};
 for(int i=0; i<sizeof(add); i++){mySerial.write(add[i]);}  
}
void balasPesan3(){
 for(int i=0; i<sizeof(pesan3); i++){mySerial.write(pesan3[i]);}  
 uint8_t add[]={0x02,0x0c,0x72,0xd1,0x00,0x00,0x00,0x00,0x00,0x01,0x10};
 for(int i=0; i<sizeof(add); i++){mySerial.write(add[i]);}

 uint8_t chk = 0;
 for ( uint8_t i=0; i<sizeof(add); i++) chk += add[i];    
 chk = (chk^0xFF);
 chk = chk+01;
 mySerial.write(chk);
}

void balasPesan4(){
 for(int i=0; i<sizeof(pesan4); i++){mySerial.write(pesan4[i]);}  
 uint8_t add[]={0x02,0x08,0x72,0x00,0x00,0xff,0x7f};
 for(int i=0; i<sizeof(add); i++){mySerial.write(add[i]);}  
 
 uint8_t chk = 0;
 for ( uint8_t i=0; i<sizeof(add); i++) chk += add[i];    
 chk = (chk^0xFF);
 chk = chk+01;
 mySerial.write(chk);
}

void balasPesan5(){
  for(int i=0; i<sizeof(pesan5); i++){mySerial.write(pesan5[i]);}  
 uint8_t add[]={0x02,0x15,0x72,0x17,0x00,0xff,0xff,0x7f,0xff,0xff,0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0xff};
 for(int i=0; i<sizeof(add); i++){mySerial.write(add[i]);}  
 
  uint8_t chk = 0;
 for ( uint8_t i=0; i<sizeof(add); i++) chk += add[i];    
 chk = (chk^0xFF);
 chk = chk+01;
 mySerial.write(chk);
}
void balasPesan6(){
  for(int i=0; i<sizeof(pesan6); i++){mySerial.write(pesan6[i]);}  
 uint8_t add[]={0x02,0x14,0x72,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0x7f,0x00};
 for(int i=0; i<sizeof(add); i++){mySerial.write(add[i]);} 
  
  uint8_t chk = 0;
 for ( uint8_t i=0; i<sizeof(add); i++) chk += add[i];    
 chk = (chk^0xFF);
 chk = chk+01;
 mySerial.write(chk); 
}
//==================================================================================================================//
void loop() {
  int i = 0;
//  if(Serial.available()>0){
//    memset(buffer1, 0, sizeof(buffer1));   
//  }
//  while(Serial.available()>0){
//    buffer1[i++] = Serial.read();
//  }
  
//  if(mySerial.available()>0){
//    memset(buffer1, 0, sizeof(buffer1));   
//  }
  while(mySerial.available()>0){
    buffer1[i++] = mySerial.read();
  }



  int na=memcmp ( buffer1, buffer2, sizeof(buffer2) );
  int nb=memcmp ( buffer1, buffer3, sizeof(buffer3) );

  int o =memcmp ( buffer1, openDt, sizeof(openDt) );
  int n =memcmp ( buffer1, pesan, sizeof(pesan) );
  int n1=memcmp ( buffer1, pesan1, sizeof(pesan1) );
  int n2=memcmp ( buffer1, pesan2, sizeof(pesan2) );
  int n3=memcmp ( buffer1, pesan3, sizeof(pesan3) );
  int n4=memcmp ( buffer1, pesan4, sizeof(pesan4) );
  int n5=memcmp ( buffer1, pesan5, sizeof(pesan5) );
  int n6=memcmp ( buffer1, pesan6, sizeof(pesan6) );
  memset(buffer1, 0, sizeof(buffer1));   

//  Serial.println((char*)buffer1);
//  if(na==0)Serial.println("aaa");
//  if(nb==0)Serial.println("bbb");

  if(o==0)  {
    balasOpenDt();
    Serial.println("open");
  }
  if(n==0)  {
    balasPesan();
    Serial.println("d");
  }
  if(n1==0) {
    balasPesan1();
    Serial.println("d1");
  }
  if(n2==0) {
    balasPesan2();
    Serial.println("d2");
  }
  if(n3==0) {
    balasPesan3();
    Serial.println("d3");
  }
  if(n4==0) {
    balasPesan4();
    Serial.println("d4");
  }
  if(n5==0) {
    balasPesan5();
    Serial.println("d5");
  }
  if(n6==0) {
    balasPesan6();
    Serial.println("d6");
  }

// for(int i=0; i<sizeof(buffer1); i++){
//    printHex(buffer1[i]);
// }
//  mySerial.write(0xaa);
  Serial.println();
  delay(112);
//  mySerial.flush();
}
