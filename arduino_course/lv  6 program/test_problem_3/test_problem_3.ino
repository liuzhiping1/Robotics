#include <LiquidCrystal.h>
LiquidCrystal Lcd(13,12,8,7,4,2);
int value;
void setup()
{
 Serial.begin(9600);
 pinMode(3,OUTPUT);
 pinMode(5,OUTPUT);
 pinMode(6,OUTPUT);
 Lcd.begin(16,2);
}
 void loop()
{
  value=Serial.read();
  if(value=='a') 
{
 digitalWrite(3,LOW);
 digitalWrite(5,HIGH);
 digitalWrite(6,LOW);
 delay(1000);
 Lcd.clear();
 Lcd.print("kidobotikz");
}
 else if(value=='b')
{
 digitalWrite(3,LOW);
 digitalWrite(5,HIGH);
 digitalWrite(6,LOW);
 delay(1000); 
 Lcd.clear();
}
 else if(value=='c')
{
 digitalWrite(3,HIGH);
 digitalWrite(5,HIGH);
 digitalWrite(6,LOW);
 delay(1000);
}
 else if(value=='d')
{
 digitalWrite(3,LOW);
 digitalWrite(5,LOW);
 digitalWrite(6,LOW);
 delay(1000); 
}
}
