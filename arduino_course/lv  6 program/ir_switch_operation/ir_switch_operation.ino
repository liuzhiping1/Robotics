#include <LiquidCrystal.h>
LiquidCrystal Lcd(13,12,8,7,4,2);
#include <SPIRremote.h>
SPIRrecv remote(9);
int a=0,value;
void setup()
{
  remote.enableIR();
  pinMode(3,OUTPUT); 
  Lcd.begin(16,2);
  pinMode(A5,OUTPUT);
}
void loop()
{
  value=remote.getIRValue();
  if(value==1)
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
    digitalWrite(3,HIGH);
    Lcd.clear();
    Lcd.setCursor(0,0);
    Lcd.print("Led on");
    delay(100);
    break;
  case 2: 
    digitalWrite(3,LOW);
    Lcd.clear();
    Lcd.setCursor(0,0);
    Lcd.print("Led off");
    delay(100);
    break;
  case 3:
    digitalWrite(A5,HIGH);
    Lcd.clear();
    Lcd.setCursor(0,0);
    Lcd.print("relay on");
    delay(100);
    break;
  case 4:
    digitalWrite(A5,LOW);
    Lcd.clear();
    Lcd.setCursor(0,0);
    Lcd.print("relay off");
    delay(100);
    break;
  }
}



