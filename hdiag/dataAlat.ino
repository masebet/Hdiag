//0x72,0x05,0x73,0x00,0x16
//0x72,0x05,0x73,0x01,0x15
//0x72,0x05,0x74,0x01,0x14
//0x72,0x07,0x72,0xd1,0x00,0x06,0x3e
//0x72,0x07,0x72,0x20,0x00,0x02,0xf3
//0x72,0x07,0x72,0x17,0x00,0x0f,0xef
//0x72,0x07,0x72,0xd0,0x00,0x0e,0x37



//7,8,12,20,21
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
  for (int i=0;i<sizeof(isi.data20.body);i++) {
    Serial.print(isi.data20.body[i],HEX);Serial.print(" ");
  }
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
  for (int i=0;i<sizeof(isi.data21.body);i++) {
    Serial.print(isi.data21.body[i],HEX);Serial.print(" ");
  }
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
  for (int i=0;i<sizeof(isi.data8.body);i++) {
    Serial.print(isi.data8.body[i],HEX);Serial.print(" ");
  }
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
  for (int i=0;i<sizeof(isi.data12.body);i++) {
    Serial.print(isi.data12.body[i],HEX);Serial.print(" ");
  }
  Serial.println();
}

void data00(){//7
  Serial.print(" data00> ");
  mySerial.write(0x72);
  mySerial.write(0x05);
  mySerial.write(0x73);
  mySerial.write(uint8_t(0x00));
  mySerial.write(0x16);
  delay(100); 
  cetakData();
  for (int i=0;i<sizeof(isi.data7.body);i++) {
    Serial.print(isi.data7.body[i],HEX);Serial.print(" ");
  }
  Serial.println();
}

void data01(){//12
  Serial.print(" data01> ");
  mySerial.write(0x72);
  mySerial.write(0x05);
  mySerial.write(0x73);
  mySerial.write(0x01);
  mySerial.write(0x15);
  delay(100); 
  cetakData();
  for (int i=0;i<sizeof(isi.data12.body);i++) {
    Serial.print(isi.data12.body[i],HEX);Serial.print(" ");
  }
  Serial.println();
}

void data02(){//12
  Serial.print(" data02> ");
  mySerial.write(0x72);
  mySerial.write(0x05);
  mySerial.write(0x74);
  mySerial.write(0x01);
  mySerial.write(0x14);
  delay(100); 
  cetakData();
  for (int i=0;i<sizeof(isi.data12.body);i++) {
    Serial.print(isi.data12.body[i],HEX);Serial.print(" ");
  }
  Serial.println();
}
