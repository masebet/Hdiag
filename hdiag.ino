
void setup() {
  // initialize both serial ports:
  Serial.begin(9600);
  Serial2.begin(10400);
  pinMode(7,OUTPUT);
  digitalWrite(7,1);
}

void loop() {
  digitalWrite(7,1);
  delay(65);
  digitalWrite(7,0);
  delay(156);
  Serial2.write(0xfe);
  Serial2.write(0x04);
  Serial2.write(0x72);
  Serial2.write(0x8c);  
  while (Serial2.available()) {
    int inByte = Serial2.read();
    Serial.print(inByte,HEX);
  }
  Serial.println();
  delay(156);
}
