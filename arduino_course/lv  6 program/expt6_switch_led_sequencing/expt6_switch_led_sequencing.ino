int value;
void setup()
{
 pinMode(A4,INPUT);
 pinMode(1,OUTPUT);
 pinMode(2,OUTPUT);
 pinMode(3,OUTPUT);
 pinMode(4,OUTPUT);
 pinMode(5,OUTPUT);
 pinMode(6,OUTPUT);
 pinMode(7,OUTPUT);
 pinMode(8,OUTPUT);
 pinMode(9,OUTPUT);
 pinMode(10,OUTPUT);
 digitalWrite(2,LOW);
 digitalWrite(4,LOW);
 digitalWrite(6,LOW);
 digitalWrite(8,LOW);
 digitalWrite(10,LOW);
}
void loop()
{
 value=digitalRead(A4);
if(value==HIGH)
{  
  digitalWrite(1,HIGH);
  delay(50);
  digitalWrite(1,LOW);
  digitalWrite(3,HIGH);
  delay(50);
  digitalWrite(3,LOW);
  digitalWrite(5,HIGH);
  delay(50);
  digitalWrite(5,LOW);
  digitalWrite(7,HIGH);
  delay(50);
  digitalWrite(7,LOW);
  digitalWrite(9,HIGH);
  delay(50);
  digitalWrite(9,LOW);
}
else
{
  digitalWrite(9,HIGH);
  delay(50);
  digitalWrite(9,LOW);
  digitalWrite(7,HIGH);
  delay(50);
  digitalWrite(7,LOW);
  digitalWrite(5,HIGH);
  delay(50);
  digitalWrite(5,LOW);
  digitalWrite(3,HIGH);
  delay(50);
  digitalWrite(3,LOW);
  digitalWrite(1,HIGH);
  delay(50);
  digitalWrite(1,LOW);  
}
}
