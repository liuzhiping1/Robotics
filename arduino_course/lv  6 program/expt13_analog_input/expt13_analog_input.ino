#include<LiquidCrystal.h>
LiquidCrystal Lcd(13,12,8,7,4,2);
int value;
void setup()
{
  Serial.begin(9600);
 Lcd.begin(16,2);
 pinMode(A3,INPUT);
}
 void loop()
 {
  value=analogRead(A3);
  Lcd.setCursor(0,0);
 Serial.println(value);
  delay(1000);
  Lcd.clear();
 }
