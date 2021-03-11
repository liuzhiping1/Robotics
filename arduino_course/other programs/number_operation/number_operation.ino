#include <LiquidCrystal.h>
LiquidCrystal Lcd(13,12,8,7,4,2);
int a=0,value;
void setup()
{
  pinMode(A4,INPUT);
  Lcd.begin(16,2);
}
void loop()
{
  value=digitalRead(A4);
  if(value==HIGH)
  {
    a=a+1;
  }
  if(a==5)
  {
    a=0;
  }

  switch(a)
  {
  case 1: 
    Lcd.clear();
    Lcd.setCursor(0,0);  
    Lcd.print("1");
    break;
  case 2:
    Lcd.clear();
    Lcd.setCursor(0,0);
    Lcd.print("2");
    break;
  case 3:
    Lcd.clear();
    Lcd.setCursor(0,0);
    Lcd.print("3");
    break;
  case 4:
    Lcd.clear();
    Lcd.setCursor(0,0);
    Lcd.print("4");
    break;
  }
  delay(100);
}
