#include <SPIRremote.h>
SPIRrecv remote(9);
int a;
int value;
void setup()
{
  remote.enableIR();
  pinMode(3,OUTPUT);
  pinMode(A3,INPUT); 
}
 void loop()
{
  value=remote.getIRValue();
  a=analogRead(A3); 
  if(value==1)
{
  if(a>500)
 {
  digitalWrite(3,HIGH); 
 }
 else
 {
 digitalWrite(3,LOW);
}
}
}
