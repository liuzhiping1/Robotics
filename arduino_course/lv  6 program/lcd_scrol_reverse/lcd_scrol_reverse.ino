#include <LiquidCrystal.h>
LiquidCrystal Lcd(13,12,8,7,4,2);
int i,a;
void setup()
{
 Lcd.begin(16,2);
}
 void loop()
 {
  for(i=1;i>=0;i--)
 {
  for(a=15;a>=0;a--) 
 {  
  Lcd.setCursor(a,i);
  Lcd.print("robot");
  delay(100);
  Lcd.clear();
 }
 }
 }
