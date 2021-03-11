#include <LiquidCrystal.h>
LiquidCrystal Lcd(13,12,8,7,4,2);
int i,a;
void setup()
{
 Lcd.begin(16,2);
}
 void loop()
 {
  for(i=0;i<2;i++)
 {
  for(a=0;a<16;a++) 
 {  
  Lcd.setCursor(a,i);
  Lcd.print("robot");
  delay(500);
  Lcd.clear();
 }
 }
 }
 

