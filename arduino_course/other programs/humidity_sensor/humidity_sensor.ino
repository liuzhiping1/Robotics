float val = 0;
float RH = 0;
#include<LiquidCrystal.h>
LiquidCrystal Lcd(13,12,8,7,4,2);

void setup() 
{
  Serial.begin(9600);
  Lcd.begin(16,2);
}


void loop() 
{
  val = analogRead(A0);
  delay(500);
  Lcd.print("value=");
  Serial.println(val);   //Serial.println(RH);
  RH = ((((val/1023)*5)-0.8)/3.1)*100;//RH = ((0,0004*20 + 0,149)*val)-(0,0617*20 + 24,436);
  Lcd.print("humidity="); 
  Lcd.println(RH);
  delay(500);
}
