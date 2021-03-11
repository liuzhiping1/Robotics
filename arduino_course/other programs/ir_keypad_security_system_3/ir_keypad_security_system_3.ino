#include <Servo.h>
#include<SPIRremote.h> 
SPIRrecv remote(9);
#include<LiquidCrystal.h>
LiquidCrystal Lcd(13,12,8,7,4,2);
int value,s,a,h;
Servo si;
void setup()
{
  remote.enableIR();
  Lcd.begin(16,2);
  si.attach(A0);
  pinMode(3,OUTPUT);
  pinMode(A5,OUTPUT);
}
 void loop()
{
  value = remote.getIRValue();
  if(value==1)
{ 
  Lcd.clear(); 
  Lcd.print("wrong password");
  Lcd.setCursor(0,0);
  delay(500);
  digitalWrite(3,LOW);
  digitalWrite(A5,LOW); 
}
 else if(value==2)
{ 
  Lcd.clear();
  Lcd.print("wrong password");
  Lcd.setCursor(0,0);
  delay(500);
  digitalWrite(3,LOW);
  digitalWrite(A5,LOW);
}
 else if(value==3)
{ 
  Lcd.clear();
  Lcd.print("wrong password");
  Lcd.setCursor(0,0);
  delay(500);
  digitalWrite(3,LOW);
  digitalWrite(A5,LOW);
}
 else if(value==4)
{ 
  Lcd.clear();
  Lcd.print("wrong password");
  Lcd.setCursor(0,0);
  delay(500);
  digitalWrite(3,LOW);
  digitalWrite(A5,LOW);
}
 else if(value==5)
{ 
  Lcd.clear();
  Lcd.print("wrong password");
  Lcd.setCursor(0,0);
  delay(500);
  digitalWrite(3,LOW);
  digitalWrite(A5,LOW);
}
 else if(value==6)
{ 
  Lcd.clear();
  Lcd.print("wrong password");
  Lcd.setCursor(0,0);
  delay(500);
  digitalWrite(3,LOW);
  digitalWrite(A5,LOW);
}
 else if(value==7)
{ 
  Lcd.clear();
  Lcd.print("wrong password");
  Lcd.setCursor(0,0);
  delay(500);
  digitalWrite(3,LOW);
  digitalWrite(A5,LOW);
}
 else if(value==8)
{ 
  Lcd.clear();
  Lcd.print("wrong password");
  Lcd.setCursor(0,0);
  delay(500);
  digitalWrite(3,LOW);
  digitalWrite(A5,LOW);
}
 else if(value==9)
{ 
  Lcd.clear();
  Lcd.print("wrong password");
  Lcd.setCursor(0,0);
  delay(500);
  digitalWrite(3,LOW);
  digitalWrite(A5,LOW);
}
 else if(value==0)
{    
    Lcd.clear();
    Lcd.print("lock open");  
    digitalWrite(3,HIGH);
    digitalWrite(A5,HIGH);
    si.write(175);
    delay(5000);
    si.write(5);
}
}
/*  {
    Lcd.clear();
    Lcd.print("enter password");
    Lcd.setCursor(0,0);
    delay(1000);
    s = remote.getIRValue();
    Lcd.print("*");
    Lcd.setCursor(1,1);
    delay(1000);
    a = remote.getIRValue();
    Lcd.print("*");
    Lcd.setCursor(2,1);
    delay(1000);
    h = remote.getIRValue();
    Lcd.print("*");
    Lcd.setCursor(3,1);
    delay(1000);
    }  
    if(s==1&&a==2&&h==3)
    {*/
 
   
