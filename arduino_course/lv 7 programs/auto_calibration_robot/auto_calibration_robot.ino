int lmt1=6,lmt2=5,rmt1=10,rmt2=11;
long int Sum=0;
int i,ambient,fire,water;
int cs=A1,csv;
void setup()
{
 pinMode(lmt1,OUTPUT);
 pinMode(lmt2,OUTPUT);
 pinMode(rmt1,OUTPUT);
 pinMode(rmt2,OUTPUT); 
 pinMode(A1,OUTPUT); 
 left();
 for(i=0;i<100;i++)
 {
  csv=analogRead(A1);
  Sum=Sum+csv;
  delay(100); 
} 
 Stop();
 delay(1000);
 ambient=Sum/100;
 fire=ambient+100;
 water=ambient+200;
 delay(500);
}
 void loop()
{
 csv=analogRead(A1);
 if(csv<fire)
 {
  left();
 } 
 else if(csv>ambient&&csv<water)
 {
  forward();
 }
 else if(csv>water)
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
    void left()
 {
 digitalWrite(lmt1,LOW);
 digitalWrite(lmt2,HIGH);
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
