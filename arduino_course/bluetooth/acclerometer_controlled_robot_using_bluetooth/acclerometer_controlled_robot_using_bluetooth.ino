int lmt1=5,lmt2=3,rmt1=11,rmt2=6;
int x,y;
int flag = 0;
void setup()
{
 pinMode(lmt1,OUTPUT);
 pinMode(lmt2,OUTPUT);
 pinMode(rmt1,OUTPUT);
 pinMode(rmt2,OUTPUT); 
 Serial.setTimeout(5);
 Serial.begin(9600);
 Stop();
}
 void loop()
{
  if(Serial.available() > 0)
  {
   y=Serial.parseInt();
   x=Serial.parseInt();
  }
  if(x>=0 && x<=2.0 && y>=0 && y<=2.0)
 {
  Stop();
  if(flag == 0)
  Serial.println("stop");
flag = 1;
}

  if(x>=-15.0 && x<=-50.0)
 {
  forward();
  if(flag == 0)
{
Serial.println("forward");
flag = 1;
}
}
 
  if(x>=15.0 && x<=50.0)
 {
  back();
  if(flag == 0)
{
Serial.println("back");
flag = 1;
}
}
 
  if(y>=-15.0 && y<=-50.0) 
 {
  left();
  if(flag == 0)
{
Serial.println("left");
flag = 1;
}
}
 
  if(y>=15.0 && y<=50.0) 
 {
  right();
  if(flag == 0)
{
Serial.println("right");
flag = 1;
}
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
   digitalWrite(lmt1,HIGH);
 digitalWrite(lmt2,LOW);
 digitalWrite(rmt1,LOW);
 digitalWrite(rmt2,HIGH);
 }
  void right()
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
