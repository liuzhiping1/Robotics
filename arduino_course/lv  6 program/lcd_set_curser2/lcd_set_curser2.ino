#include<LiquidCrystal.h>
LiquidCrystal Lcd(13,12,8,7,4,2);
void setup()
{
  Lcd.begin(16,2);
}
 void loop()
 {
   Lcd.setCursor(7,0);
   Lcd.print("HI ");
   Lcd.setCursor(7,1);
   Lcd.print("BYE");
   delay(1000);
   Lcd.setCursor(7,0);
   Lcd.print("BYE");
   Lcd.setCursor(7,1);
   Lcd.print("HI ");
   delay(1000);
 } 
