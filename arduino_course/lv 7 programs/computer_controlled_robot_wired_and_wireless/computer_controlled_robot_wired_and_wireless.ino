int lmt1=5,lmt2=6,rmt1=10,rmt2=11;
int value;
  void setup()
{
 Serial.begin(9600); 
 pinMode(lmt1,OUTPUT);
 pinMode(lmt2,OUTPUT);
 pinMode(rmt1,OUTPUT);
 pinMode(rmt2,OUTPUT); 
}
 void loop()
{
 value=Serial.read(); 
 switch(value)
{
 case'w':
 forward();
 break;
 case'a':
 left();
 break;
 case'd':
 right();
 break;
 case's':
 back();
 break;
 case'x':
 Stop();
 break;
}
}
 void forward()
{
 digitalWrite(lmt1,HIGH);
 digitalWrite(lmt2,LOW);
 digitalWrite(rmt1,HIGH);
 digitalWrite(rmt2,LOW); 
}
 void back()
{
  digitalWrite(lmt1,LOW);
 digitalWrite(lmt2,HIGH);
 digitalWrite(rmt1,LOW);
 digitalWrite(rmt2,HIGH);
}
   void left()
 {
   digitalWrite(lmt1,LOW);
 digitalWrite(lmt2,HIGH);
 digitalWrite(rmt1,HIGH);
 digitalWrite(rmt2,LOW);
 }
  void right()
{
 digitalWrite(lmt1,HIGH);
 digitalWrite(lmt2,LOW);
 digitalWrite(rmt1,LOW);
 digitalWrite(rmt2,HIGH);
}
  void Stop()
{
 digitalWrite(lmt1,LOW);
 digitalWrite(lmt2,LOW);
 digitalWrite(rmt1,HIGH);
 digitalWrite(rmt2,HIGH);
 }
