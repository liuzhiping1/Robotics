#include<LiquidCrystal.h>
LiquidCrystal Lcd(13,12,8,7,4,2);
#include <SPGSM.h>
float temp=0,t=0;
SPGSM spgsm;
int f;

void setup() 
{
  pinMode(A0,INPUT);
  pinMode(A5,OUTPUT);
  spgsm.begin(9600);
  Lcd.begin(16,2);
}

void loop()
{
  t=analogRead(A0);
  temp=t*0.48828125;
  Lcd.setCursor(0,0);
  Lcd.print("TEMP = ");
  Lcd.print(temp);

  if(temp>=40)
  {
  delay(2000);

  if(temp>=40)
  {

   Lcd.setCursor(0,1);
   Lcd.print("Alert! Fire ");
   digitalWrite(A5,HIGH);

   spgsm.call("9445300781",10000);
   delay(2000);
  }
  }
  else
  {
   Lcd.setCursor(0,1);
   Lcd.print("Safe! No Fire") ;
   digitalWrite(A5,LOW);
   delay(100);
  }
  }



