#include<LiquidCrystal.h>
LiquidCrystal lcd(13,12,8,7,4,2);
void setup()
{
 lcd.begin(16,2);
 pinMode(A1,INPUT);
 pinMode(A5,OUTPUT);
}
void loop()
{
 int a = analogRead(A1);
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("moisture=");
 lcd.print(a);
 delay(1000);
 if(a> 200)
{
 lcd.setCursor(0,2);
 lcd.println("moisture lv low");
 digitalWrite(A5,HIGH);
}
 else
{
 lcd.setCursor(0,2);
 lcd.println("moisture lv good ");  
 digitalWrite(A5,LOW);
}
} 
