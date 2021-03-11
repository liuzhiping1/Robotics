#include <SoftwareSerial.h>
SoftwareSerial a(10, 11); // RX, TX
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Type Msg :");
  a.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 if (a.available())
    Serial.write(a.read());
 if (Serial.available())
 {
   a.write(Serial.read());
  }
}
