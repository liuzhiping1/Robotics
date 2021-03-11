#include <LiquidCrystal.h>
LiquidCrystal Lcd(13,12,8,7,4,2);
int lmt1=3,lmt2=5,rmt1=11,rmt2=6;
void setup()
{
 pinMode(lmt1,OUTPUT);
 pinMode(lmt2,OUTPUT);
 pinMode(rmt1,OUTPUT);
 pinMode(rmt2,OUTPUT);
}
 void loop()
 {
 digitalWrite(lmt1,HIGH);
 digitalWrite(lmt2,LOW);
 digitalWrite(rmt1,HIGH);
 digitalWrite(rmt2,LOW);
 Lcd.clear();
 Lcd.print("robot fordward");
 delay(1000);
 digitalWrite(lmt1,LOW);
 digitalWrite(lmt2,HIGH);
 digitalWrite(rmt1,LOW);
 digitalWrite(rmt2,HIGH);
 Lcd.clear();
 Lcd.print("robot backward");
 delay(1000);
 }
