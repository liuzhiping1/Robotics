int value;
void setup()
{
 pinMode(A4,INPUT);
 pinMode(3,OUTPUT);
}
void loop()
{
 value=digitalRead(A4);
 if(value==HIGH)
{
  digitalWrite(3,HIGH);
}
else
{
digitalWrite(3,LOW);
}
}

