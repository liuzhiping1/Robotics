int a=0,value;
void setup()
{
  pinMode(A4,INPUT);
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
    analogWrite(3,255);
    delay(100);
    break;
    case 2:
    analogWrite(3,127);
    delay(100);
    break;
    case 3:
    analogWrite(3,0);
    delay(100);
    break;
    case 4:
    analogWrite(3,127);
    delay(100);
    break;
    case 5:
    analogWrite(3,255);
    delay(100);
    break;
  }
  }



