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
    delay(500);
    if(a<=5)
  {  
    a=a+1;
  }
  else
  {
    a=0;
  }
  }
  switch(a)
  {
  case 0: 
    Lcd.clear();
    Lcd.setCursor(0,0);  
    Lcd.print("zero");
    break;
  case 1:
    Lcd.clear();
    Lcd.setCursor(0,0);
    Lcd.print("one");
    break;
  case 2:
    Lcd.clear();
    Lcd.setCursor(0,0);
    Lcd.print("two");
    break;
   case 3:
    Lcd.clear();
    Lcd.setCursor(0,0);
    Lcd.print("three");
    break;
   case 4:
    Lcd.clear();
    Lcd.setCursor(0,0);
    Lcd.print("four");
    break;
   case 5:
    Lcd.clear();
    Lcd.setCursor(0,0);
    Lcd.print("five");
    break;   
  }
  delay(100);
  }






