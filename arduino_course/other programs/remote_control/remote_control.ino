
  #include <LiquidCrystal.h>
LiquidCrystal Lcd(13,12,8,7,4,2);
#include <SPIRremote.h>
SPIRrecv remote(9);
int a=0,value,b=0,temp=0;
float t;
void setup()
{
  remote.enableIR();
  pinMode(3,OUTPUT); 
  Lcd.begin(16,2);
  pinMode(A5,OUTPUT);
  pinMode(A0,INPUT);
}
void loop()
{
  
  value=remote.getIRValue();
  a=value;
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
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
    Lcd.clear();
    Lcd.setCursor(0,0);
    Lcd.print("FAN ON");
    delay(100);
    break;
  case 4:
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    Lcd.clear();
    Lcd.setCursor(0,0);
    Lcd.print("FAN OFF");
    delay(100);
    break;
    case 5:
   t=analogRead(A0);
  temp=t* 0.48828125;//5v=supply voltage//
  Lcd.setCursor(0,0);
  Lcd.print("TEMPRATURE=");
  Lcd.print(temp); //1000=toconvert voltage to millivolt//
  Lcd.print("*c"); //1024=analog(0-1023)//
  delay(1000);
  Lcd.clear();
  
    if(temp>=40)
  {
  delay(2000);

  if(temp>=40)
  {

   Lcd.setCursor(0,1);
    Lcd.print("FAN ON");
   digitalWrite(A5,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
    
    delay(100);
    break;
  }
}      
  }
}



