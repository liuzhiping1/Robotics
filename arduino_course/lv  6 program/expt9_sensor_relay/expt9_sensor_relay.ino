int value;
void setup()
{
 pinMode(A5,OUTPUT);
 pinMode(A1,INPUT);
}
void loop()
{
value=digitalRead(A1);
if(value==HIGH)
{
 digitalWrite(A5,HIGH);
}
 else
{
 digitalWrite(A5,LOW);
} 
}
