int cs=A1;
int csv;
int lmt1=5,lmt2=6,rmt1=11,rmt2=10;
void setup()
{
 pinMode(cs,INPUT);  
 pinMode(lmt1,OUTPUT);
 pinMode(lmt2,OUTPUT);
 pinMode(rmt1,OUTPUT);
 pinMode(rmt2,OUTPUT); 
}
void loop()
{
 csv=digitalRead(cs);
 if(csv==HIGH)
{
 forward();
}
else
{
 Stop();
}
}
 void forward()
{
 digitalWrite(lmt1,HIGH);
 digitalWrite(lmt2,LOW);
 digitalWrite(rmt1,HIGH);
 digitalWrite(rmt2,LOW); 
}
  void Stop()
{
 digitalWrite(lmt1,LOW);
 digitalWrite(lmt2,LOW);
 digitalWrite(rmt1,HIGH);
 digitalWrite(rmt2,HIGH);
}

 
