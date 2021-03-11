int lm1=3,lm2=5,rm1=11,rm2=6;
int x=A2,y=A3;
int xv,yv;
void setup()
{
 pinMode(lm1,OUTPUT);
 pinMode(lm2,OUTPUT);
 pinMode(rm1,OUTPUT);
 pinMode(rm2,OUTPUT); 
 pinMode(x,INPUT);
 pinMode(y,INPUT);
}
 void loop()
{
  xv=analogRead(x);
  yv=analogRead(y);
  if(xv>=315 && xv<=345 && yv>=320 && yv<=345)
 {
  Stop();
 }
  if(yv>=375 && yv<=391)
 {
  forward();
 }
  if(yv>=275 && yv<=290)
 {
  back();
 }
  if(xv>=270 && xv<=285) 
 {
  left();
 }
  if(xv>=375 && xv<=400) 
 {
  right();
 }
 }
  void forward()
{
      analogWrite(lm1, 127.5);
    analogWrite(lm2, 0);
    analogWrite(rm1, 127.5);
    analogWrite(rm2, 0);
// digitalWrite(lmt1,HIGH);
// digitalWrite(lmt2,LOW);
// digitalWrite(rmt1,HIGH);
// digitalWrite(rmt2,LOW); 
}
 void back()
{
      analogWrite(lm1, 0);
    analogWrite(lm2, 127.5);
    analogWrite(rm1, 0);
    analogWrite(rm2, 127.5);
//  digitalWrite(lmt1,LOW);
// digitalWrite(lmt2,HIGH);
// digitalWrite(rmt1,LOW);
// digitalWrite(rmt2,HIGH);
}
   void left()
 {
     analogWrite(lm1, 0);
    analogWrite(lm2, 127.5);
    analogWrite(rm1, 127.5);
    analogWrite(rm2, 0);
// digitalWrite(lmt1,LOW);
// digitalWrite(lmt2,HIGH);
// digitalWrite(rmt1,HIGH);
// digitalWrite(rmt2,LOW);
 }
  void right()
{
    analogWrite(lm1, 127.5);
    analogWrite(lm2, 0);
    analogWrite(rm1, 0);
    analogWrite(rm2, 127.5);
// digitalWrite(lmt1,HIGH);
// digitalWrite(lmt2,LOW);
// digitalWrite(rmt1,LOW);
// digitalWrite(rmt2,HIGH);
}
  void Stop()
{
 digitalWrite(lm1,LOW);
 digitalWrite(lm2,LOW);
 digitalWrite(rm1,HIGH);
 digitalWrite(rm2,HIGH);
 }
