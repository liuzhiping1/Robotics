#include<LiquidCrystal.h>
LiquidCrystal Lcd(13,12,8,7,4,2);
float temp=0,t=0;
float val = 0;
float RH = 0;
int value;
int ps;
int ls=A0;
int rs=A2;
int lsv;
int rsv;
int a=0;
void setup()
{
  Lcd.begin(16,2); 
  pinMode(A4,INPUT);
}
void loop()
{
  value=digitalRead(A4);
  if(value==HIGH)
  {
    a=a+1;
  }
  if(a==4)
  {
    a=0;
  }

  switch(a)
  {
  case 1: 
    t=analogRead(ls);
    temp=t*0.48828125;//5v=supply voltage//
    Lcd.clear();
    Lcd.setCursor(0,0);
    Lcd.print("TEMPERATURE=");
    Lcd.print(temp); //1000=toconvert voltage to millivolt//
    Lcd.print("*c"); //1024=analog(0-1023)//
    //delay(500);  //10=10millivolt=1celcius//
    break;

  case 2:
    val = analogRead(rs);
    Lcd.clear();
    Lcd.setCursor(0,0);
//    Lcd.println(val);   //Lcd.println(RH);
    RH = ((((val/1023)*5)-0.8)/3.1)*100;//RH = ((0,0004*20 + 0,149)*val)-(0,0617*20 + 24,436);
    Lcd.print("HUMIDITY="); 
    Lcd.print(RH);
  //  delay(500);
    break;

  case 3:
    // Read the input on analog pin 0:
    ps = analogRead(A1);
    // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
    float voltage = ps * (5.0 / 1023.0);
    Lcd.clear();
    Lcd.setCursor(0,0);
    Lcd.print("PRESSURE=");
    // Print out the value you read:
    Lcd.print(voltage);
    // Wait 100 milliseconds
//    delay(500);
    break;
  } 
  delay(300);
}

