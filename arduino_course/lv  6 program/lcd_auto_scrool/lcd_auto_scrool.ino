#include <LiquidCrystal.h>
LiquidCrystal Lcd(13,12,8,7,4,2);
int i;
void setup()
{
  Lcd.begin(16,2);
  Lcd.print("big bad wolf bite a sheep");
}
void loop()
  {
  for(int pos=0;pos<=36;pos++)
  {
    Lcd.scrollDisplayRight();
    delay(500);

  }
  delay(100);
}


