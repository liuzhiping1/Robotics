int b;
void setup()
{
  Serial.begin(9600);
 pinMode(A3,INPUT);
 /*pinMode(13,OUTPUT);
 pinMode(A1,OUTPUT);
 pinMode(A2,OUTPUT);
 pinMode(A4,OUTPUT);*/
}
 void loop()
 {
  b=analogRead(A3);
 Serial.println(value);
  delay(1000);
  if(b<=60){
   digitalWrite(13,HIGH);
  }
  else
  {
    digitalWrite(13,LOW);
  }
 }
