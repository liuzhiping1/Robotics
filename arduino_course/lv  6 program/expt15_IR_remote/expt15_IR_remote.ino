#include<SPIRremote.h> 
SPIRrecv remote(9);
int value;
void setup()
{
  remote.enableIR();
  pinMode(3,OUTPUT);
}
void loop()
{
  value=remote.getIRValue();
  if(value==1)
  {
   digitalWrite(3,HIGH);
  }
  else if(value==2)
  {
  digitalWrite(3,LOW);
}
}



