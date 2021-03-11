#include<LiquidCrystal.h>
LiquidCrystal Lcd(13,12,8,7,4,2);
float temp=0,t=0;
char value,a=0,b;
void setup()
{
 Serial.begin(9600);
 pinMode(A0,INPUT);
 pinMode(A1, INPUT);
 pinMode(6, OUTPUT);
 pinMode(5, OUTPUT);
  Lcd.begin(16,2);
}
 void loop()
{ 
 value = Serial.read();
 int x =analogRead(A1);
 temp=t* 0.48828125;//5v=supply voltage//
 b = digitalRead(A4); 
 t=analogRead(A0);
 //switch(a)
//{
// case '1': 
if(b==1)
{ 
   Lcd.clear();
  Lcd.print("TEMPRATURE=");
  Lcd.print(temp); //1000=toconvert voltage to millivolt//
  Lcd.print("*c"); //1024=analog(0-1023)//
  delay(1000);
}
 //break;
 //case '2':  
 else if(b==2)
 {
 Lcd.print(x);
 Lcd.setCursor(0,0);
 delay(1000);
  if(x<=100)
 {
 Lcd.print("plant need water");
 Lcd.setCursor(0,1);
 }
  else
 {
 Lcd.print("no water needed");
 Lcd.setCursor(0,1);
 }
 }
// break;
 //case 'a': 
else if(value=='a')
 { 
 digitalWrite(13,HIGH);
 Lcd.print("room light on");
  Lcd.setCursor(1,0);
 }
// break;
// case 'b':
else if(value=='2')
{
  digitalWrite(13,LOW);
 Lcd.print("room light off");
  Lcd.setCursor(1,0);
// break; 
}
}
