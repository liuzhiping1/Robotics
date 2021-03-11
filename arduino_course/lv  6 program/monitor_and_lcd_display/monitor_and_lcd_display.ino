#include <LiquidCrystal.h>
LiquidCrystal Lcd(13,12,8,7,4,2);
int i,a;
void setup()
{
 Serial.begin(9600);  
 Lcd.begin(16,2);
}
 void loop()
{
  i=Serial.read();
  switch(i)
{
 case '0':
 Lcd.setCursor(a,i);
 Lcd.print("0");
 break;
 case '1':
 Lcd.print("1");
 break;
  case '2':
 Lcd.print("2");
 break;
  case '3':
 Lcd.print("3");
 break;
  case '4':
 Lcd.print("4");
 break;
  case '5':
 Lcd.print("5");
 break;
  case '6':
 Lcd.print("6");
 break;
  case '7':
 Lcd.print("7");
 break;
  case '8':
 Lcd.print("8");
 break;
  case '9':
 Lcd.print("9");
 break;
}
}

