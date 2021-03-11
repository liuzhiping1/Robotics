int a=0,value;
void setup()
{
  pinMode(A4,INPUT);
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(A5,OUTPUT);
}
void loop()
{
  value=digitalRead(A4);
  if(value==HIGH)
  {
    a=a+1;
  }
  if(a==6)
  {
    a=0;
  }

  switch(a)
  {  
   case 1:
   digitalWrite(3,LOW);
   digitalWrite(5,HIGH);
   digitalWrite(6,LOW);
   delay(1000);
   digitalWrite(A5,HIGH);
   break;
  case 2:
   digitalWrite(3,LOW);
   digitalWrite(5,HIGH);
   digitalWrite(6,LOW);
   delay(1000);
   digitalWrite(A5,LOW);
   break;
  case 3:
    digitalWrite(3,HIGH);
   digitalWrite(5,HIGH);
   digitalWrite(6,LOW);
   delay(1000);
   digitalWrite(A5,LOW);
   break;
   case 4:
     digitalWrite(3,LOW);
   digitalWrite(5,LOW);
   digitalWrite(6,LOW);
   delay(1000);
   digitalWrite(A5,LOW);
   break;
  }
}
   
   
   
   
   
   
   
   
    
