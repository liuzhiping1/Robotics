#include <LiquidCrystal.h>
LiquidCrystal Lcd(13,12,8,7,4,2);
int i;
int a[]={1,2,3,4,5,6,7,8,9,10};
void setup()
{
  Lcd.begin(16,2);
}
 void loop()
 {
  for(i=0;i<=9;i++)
 {
  Lcd.setCursor(5,0);
  Lcd.print(a[i]);
  delay(500);
  Lcd.clear();
 }
 }
