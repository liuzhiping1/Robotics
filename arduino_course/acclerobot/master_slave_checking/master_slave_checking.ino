#include <SoftwareSerial.h>
SoftwareSerial a(10, 11); // RX, TX
void setup()
{
//  Serial.begin(9600);
//  Serial.println("Type Msg :");
  a.begin(9600);
}
void loop()
{
//  if (a.available())
//    Serial.write(a.read());
//  if (Serial.available())
//  {
//    a.write(Serial.read());
//  }

a.print("Y");
delay(1000);
a.print("N");
delay(1000);
}

