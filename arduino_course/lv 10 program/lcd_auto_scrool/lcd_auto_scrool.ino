#include <LiquidCrystal.h>
LiquidCrystal Lcd(13,12,8,7,4,2);
int i,x,y;
void setup()
{
  Lcd.begin(16,2);
  Lcd.print("be good do good");
}
void loop()
{
 for(int pos=0;pos<=36;pos++)
{
 for(x=0;x<=4;y++)
{
  for(y=0;y<=4;y++)
      {
  Lcd.scrollDisplayRight();
  Lcd.setCursor(x,y);
  delay(500);

}
  delay(100);
}
}
}

