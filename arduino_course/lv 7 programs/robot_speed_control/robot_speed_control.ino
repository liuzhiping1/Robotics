int lmt1=5,lmt2=6,rmt1=11,rmt2=10;
void setup()
{
 pinMode(lmt1,OUTPUT);
 pinMode(lmt2,OUTPUT);
 pinMode(rmt1,OUTPUT);
 pinMode(rmt2,OUTPUT);
}
 void loop()
 {
 analogWrite(lmt1,255);
 analogWrite(lmt2,0);
 analogWrite(rmt1,255);
 analogWrite(rmt2,0);
  delay(1000);
 analogWrite(lmt1,175);
 analogWrite(lmt2,0);
 analogWrite(rmt1,175);
 analogWrite(rmt2,0);
 delay(1000);
 analogWrite(lmt1,0);
 analogWrite(lmt2,0);
 analogWrite(rmt1,0);
 analogWrite(rmt2,0);
 delay(1000);
}
