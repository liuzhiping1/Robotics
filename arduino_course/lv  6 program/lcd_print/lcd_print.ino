#include <LiquidCrystal.h>
LiquidCrystal Lcd(13,12,8,7,4,2);
#include <SPIRremote.h>
SPIRrecv remote(9);
int value;
void setup()
{
 remote.enableIR();
 Lcd.begin(16,2);
}
  void loop()
{
  value=remote.getIRValue();    
  if(value==1)
 {
  Lcd.print("1");
 }
  else if(value==2)
 {
  Lcd.print("2"); 
 }
   else if(value==3)
 {
  Lcd.print("3");
 } 
    else if(value==4)
 {
  Lcd.print("4");
 }
    else if(value==5)
 {
  Lcd.print("5");
 }
    else if(value==6)
 {
  Lcd.print("6");
 }
    else if(value==7)
 {
  Lcd.print("7");
 }
    else if(value==8)
 {
  Lcd.print("8");
 }
    else if(value==9)
 {
  Lcd.print("9");
 }
     else if(value==0)
 {
  Lcd.print("0");
 }
 }


