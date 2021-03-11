#include <SoftwareSerial.h>
SoftwareSerial a(10, 11); // RX, TX
int i;
void setup()
{
//  Serial.begin(9600);
//  Serial.println("Type Msg :");
  a.begin(9600);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
}
void loop()
{
   i = a.read();
   if(i=='Y')
   {
    digitalWrite(13, HIGH);
   }
   if(i=='N')
   {
    digitalWrite(13, LOW);
   }
  
//  if (a.available())
//    Serial.write(a.read());
//  {
//    if (a.read() == '1')
//    {
//      digitalWrite(13, HIGH);
//      delay(2000);
//      digitalWrite(13, LOW);
//    }
//  }
  /* if (Serial.available())
    {
     a.write(Serial.read());
    }*/
}
