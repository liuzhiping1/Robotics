#include <LiquidCrystal.h>
LiquidCrystal Lcd(13,12,8,7,4,2);
#include<SPIRremote.h> 
SPIRrecv remote(9);
int value;
void setup()
{
 remote.enableIR();
 pinMode(3,OUTPUT);
 pinMode(5,OUTPUT);
 pinMode(6,OUTPUT);
 Lcd.begin(16,2);
}
 void loop()
{
  value=remote.getIRValue();
  if(value==1) 
{
 digitalWrite(3,LOW);
 digitalWrite(5,HIGH);
 digitalWrite(6,LOW);
 delay(1000);
 Lcd.clear();
 Lcd.print("kidobotikz");
}
 else if(value==2)
{
 digitalWrite(3,LOW);
 digitalWrite(5,HIGH);
 digitalWrite(6,LOW);
 delay(1000); 
 Lcd.clear();
}
 else if(value==3)
{
 digitalWrite(3,HIGH);
 digitalWrite(5,HIGH);
 digitalWrite(6,LOW);
 delay(1000);
}
 else if(value==4)
{
 digitalWrite(3,LOW);
 digitalWrite(5,LOW);
 digitalWrite(6,LOW);
 delay(1000); 
}
}
  
  
