//0x72,0x05,0x73,0x00,0x16
//0x72,0x05,0x73,0x01,0x15
//0x72,0x05,0x74,0x01,0x14
//0x72,0x07,0x72,0xd1,0x00,0x06,0x3e
//0x72,0x07,0x72,0x20,0x00,0x02,0xf3
//0x72,0x07,0x72,0x17,0x00,0x0f,0xef
//0x72,0x07,0x72,0xd0,0x00,0x0e,0x37


void printHex(uint8_t num) {
  char hexCar[2];
  sprintf(hexCar, "0x%02x", num);
  Serial.print(hexCar);
  Serial.print(",");
}

//7,8,12,20,21
uint8_t dataPesan[11]  {0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};
union{
  uint8_t data[32];
  uint8_t data21a[21];
  uint8_t data20a[20];
  uint8_t data12a[12];
  uint8_t data8a[8];
  uint8_t data7a[7];
  struct{
    uint8_t head[3];
    uint8_t body[17];
    uint8_t tail;
  } data21;
    struct{
    uint8_t head[3];
    uint8_t body[16];
    uint8_t tail;
  } data20;
    struct{
    uint8_t head[3];
    uint8_t body[8];
    uint8_t tail;
  } data12;
    struct{
    uint8_t head[3];
    uint8_t body[4];
    uint8_t tail;
  } data8;
    struct{
    uint8_t head[3];
    uint8_t body[3];
    uint8_t tail;
  } data7;
} isi;

void cetakData(){
  int a;
  while (mySerial.available()) {
    uint8_t inByte = mySerial.read();
    isi.data[a++]=inByte;
//    printHex(inByte);
    //Serial.print(inByte,HEX);Serial.print(" ");
  }
}

void open(){
  Serial.print(" open> ");
  delay(156);
  digitalWrite(7,1);
  delay(65);
  digitalWrite(7,0);
  delay(156);
  mySerial.write(0xfe);
  mySerial.write(0x04);
  mySerial.write(0x72);
  mySerial.write(0x8c);  
  delay(100);
  while (mySerial.available()) {
    int inByte = mySerial.read();
    //Serial.print(inByte,HEX);Serial.print(" ");
  }
  Serial.println();
}

void data1(){//20
  Serial.print(" data1> ");
  uint8_t add[]={0x72,0x07,0x72,0xd0,0x00,0x0e,0x37};
  mySerial.write(add[0]);
  mySerial.write(add[1]);
  mySerial.write(add[2]);
  mySerial.write(add[3]);
  mySerial.write(add[4]);
  mySerial.write(add[5]);
  mySerial.write(add[6]);
  delay(100);
  cetakData();
//  for (int i=0;i<sizeof(isi.data20.body);i++) {Serial.print(isi.data20.body[i],HEX);Serial.print(" ");}
  printHex(isi.data[17]);
  Serial.println();  
}

void data2(){//21
  Serial.print(" data2> ");
  uint8_t add[]={0x72,0x07,0x72,0x17,0x00,0x0f,0xef};
  mySerial.write(add[0]);
  mySerial.write(add[1]);
  mySerial.write(add[2]);
  mySerial.write(add[3]);
  mySerial.write(add[4]);
  mySerial.write(add[5]);
  mySerial.write(add[6]);
  delay(100);
  cetakData();  
//  for (int i=0;i<sizeof(isi.data21.body);i++) {Serial.print(isi.data21.body[i],HEX);Serial.print(" ");}
  dataPesan[0]= isi.data[5];dataPesan[1]= isi.data[6]; 
  dataPesan[2]= isi.data[8];
  dataPesan[3]= isi.data[10];
  dataPesan[4]= isi.data[15];
  dataPesan[5]= isi.data[16];dataPesan[6]= isi.data[17];
  
  printHex(isi.data[5]); printHex(isi.data[6]); //rpm
  printHex(isi.data[8]);                        //tps
  printHex(isi.data[10]);                       //suhu oli
  printHex(isi.data[15]);                       //bateray
  printHex(isi.data[16]);printHex(isi.data[17]);//lebar pulsa injektor
  Serial.println();  
}

void data3(){//8
  Serial.print(" data3> ");
  uint8_t add[]={0x72,0x07,0x72,0x20,0x00,0x02,0xf3};
  mySerial.write(add[0]);
  mySerial.write(add[1]);
  mySerial.write(add[2]);
  mySerial.write(add[3]);
  mySerial.write(add[4]);
  mySerial.write(add[5]);
  mySerial.write(add[6]);
  delay(100);
  cetakData();
//  for (int i=0;i<sizeof(isi.data8.body);i++) {Serial.print(isi.data8.body[i],HEX);Serial.print(" ");}
  dataPesan[7]= isi.data[5];
  dataPesan[8]= isi.data[6];
 
  printHex(isi.data[5]); //sensor oksigen
  printHex(isi.data[6]); //campuran bahan bakar
  Serial.println(); 
}

void data4(){//12
  Serial.print(" data4> ");
  uint8_t add[]={0x72,0x07,0x72,0xd1,0x00,0x06,0x3e};
  mySerial.write(add[0]);
  mySerial.write(add[1]);
  mySerial.write(add[2]);
  mySerial.write(add[3]);
  mySerial.write(add[4]);
  mySerial.write(add[5]);
  mySerial.write(add[6]);
  delay(100);
  cetakData();
//  for (int i=0;i<sizeof(isi.data12.body);i++) {Serial.print(isi.data12.body[i],HEX);Serial.print(" ");}
  dataPesan[9] = isi.data[5];
  dataPesan[10]= isi.data[9];
  
  printHex(isi.data[5]); //standar
  printHex(isi.data[9]); //status mesin
  Serial.println();
}

//void data00(){//7
//  Serial.print(" data00> ");
//  mySerial.write(0x72);
//  mySerial.write(0x05);
//  mySerial.write(0x73);
//  mySerial.write(uint8_t(0x00));
//  mySerial.write(0x16);
//  delay(100); 
//  cetakData();
////  for (int i=0;i<sizeof(isi.data7.body);i++) {    Serial.print(isi.data7.body[i],HEX);Serial.print(" ");}
//  Serial.println();
//}
//
//void data01(){//12
//  Serial.print(" data01> ");
//  mySerial.write(0x72);
//  mySerial.write(0x05);
//  mySerial.write(0x73);
//  mySerial.write(0x01);
//  mySerial.write(0x15);
//  delay(100); 
//  cetakData();
////  for (int i=0;i<sizeof(isi.data12.body);i++) {    Serial.print(isi.data12.body[i],HEX);Serial.print(" ");}
//  Serial.println();
//}
//
//void data02(){//12
//  Serial.print(" data02> ");
//  mySerial.write(0x72);
//  mySerial.write(0x05);
//  mySerial.write(0x74);
//  mySerial.write(0x01);
//  mySerial.write(0x14);
//  delay(100); 
//  cetakData();
////  for (int i=0;i<sizeof(isi.data12.body);i++) {    Serial.print(isi.data12.body[i],HEX);Serial.print(" ");}
//  Serial.println();
//}

void cetak(){    
   printHex(dataPesan[0]);
   printHex(dataPesan[1]);
   printHex(dataPesan[2]);
   printHex(dataPesan[3]);
   printHex(dataPesan[4]);
   printHex(dataPesan[5]);
   printHex(dataPesan[6]);
   printHex(dataPesan[7]);
   printHex(dataPesan[8]);
   printHex(dataPesan[9]);
   printHex(dataPesan[10]);
   Serial3.write(dataPesan[0]);
   Serial3.write(dataPesan[1]);
   Serial3.write(dataPesan[2]);
   Serial3.write(dataPesan[3]);
   Serial3.write(dataPesan[4]);
   Serial3.write(dataPesan[5]);
   Serial3.write(dataPesan[6]);
   Serial3.write(dataPesan[7]);
   Serial3.write(dataPesan[8]);
   Serial3.write(dataPesan[9]);
   Serial3.write(dataPesan[10]);
      Serial.println();
      uint16_t rpm = ((uint16_t) dataPesan[0] << 8) | dataPesan[1];
      Serial.print("RPM ");Serial.println(rpm);
      float tps = (float) dataPesan[2]/2;
      Serial.print("TPS ");Serial.println(tps);
      float soli = (float) dataPesan[3]-40.0;
      Serial.print("suhu oli ");Serial.println(soli);
      float vbat = (float) dataPesan[4]/10;
      Serial.print("baterai ");Serial.println(vbat);
      float lPulsa = (float)dataPesan[5];
      lPulsa += (float)dataPesan[6]/0xff;
      Serial.print("lebar pulsa ");Serial.println(lPulsa );
      float sOksi =  ((float) dataPesan[7]/0xff)* 5.0;
      Serial.print("sensor oksigen ");Serial.println(sOksi);
      float cBahan =  ((float) dataPesan[8]/0xff)* 2.0;
      Serial.print("campuran bahan ");Serial.println(cBahan);
      
      Serial.print("standar ");Serial.println(dataPesan[9]);
      Serial.print("setatus mesin ");Serial.println(dataPesan[10]);
}
