#include <LiquidCrystal.h>
LiquidCrystal Lcd(13,12,8,7,4,2);
int i;
char* name[]={"abhijet","boeing","sankar","malolan","prashanth gi","lord of ring"};
void setup()
{
  Lcd.begin(16,2);
}
 void loop()
 {
  for(i=0;i<=4;i++)
 {
  Lcd.print(name[i]);
  delay(1000);
  Lcd.clear();
 }
 }



