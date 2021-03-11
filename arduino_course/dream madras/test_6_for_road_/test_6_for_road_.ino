
int a=0,value,b;
void setup()
{
  pinMode(A4,INPUT);
 Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A5,INPUT);
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
  digitalWrite(A1,HIGH);
    break;
  case 2:
digitalWrite(A2,HIGH);
    break;
  case 3:
digitalWrite(A3,HIGH);
    break;
  }
  delay(100);
    b=analogRead(A3);
   Serial.println(b);
     delay(1000);
  if(b<=60){
   digitalWrite(A0,HIGH);
  }
  else
  {
    digitalWrite(A0,LOW);
  }
}






