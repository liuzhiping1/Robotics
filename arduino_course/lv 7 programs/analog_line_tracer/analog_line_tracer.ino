int lmt1=3,lmt2=5,rmt1=6,rmt2=11;
int lms=A0;
int rms=A1;
int ls=A2;
int cs=A3;
int rs=A4;
int lmsv;
int rmsv;
int lsv;
int csv;
int rsv;
void setup()
{
 
 pinMode(lms,INPUT);
 pinMode(rms,INPUT); 
 pinMode(ls,INPUT);
 pinMode(cs,INPUT);
 pinMode(rs,INPUT);
 pinMode(lmt1,OUTPUT);
 pinMode(lmt2,OUTPUT);
 pinMode(rmt1,OUTPUT);
 pinMode(rmt2,OUTPUT); 
}
  void loop()
{
 lmsv=digitalRead(lms);
 rmsv=digitalRead(rms);
 lsv=digitalRead(ls);
 csv=digitalRead(cs);
 rsv=digitalRead(rs);
 if(lmsv==LOW&&rmsv==LOW)
{
 if(lsv==LOW&&csv==LOW&&rsv==LOW)  
{
  left();
  delay (1000);
}
 else if(lsv==HIGH&&csv==LOW&&rsv==LOW)
{
 Stopleft();
}
 else if(lsv==LOW&&csv==LOW&&rsv==HIGH)
{
 Stopright();
}
 else if(lsv==LOW&&csv==HIGH&&rsv==LOW)
{
 forward();
}
 else if(lsv==HIGH&&csv==HIGH&&rsv==LOW)
{
 slowleft();
 delay(100);
}
 else if(lsv==LOW&&csv==HIGH&&rsv==HIGH)
{
 slowright();
 delay(100);
}
 else if(lsv==HIGH&&csv==LOW&&rsv==HIGH)
{
 left();
}
 else if(lsv==HIGH&&csv==HIGH&&rsv==HIGH)
{
 forward();
}
}
else if(lmsv==HIGH&&rmsv==LOW)
{
 Stopleft();
}
else if(lmsv==LOW&&rmsv==HIGH)
{
 Stopright();
}
else if(lmsv==HIGH&&rmsv==HIGH)
{
 left();
}
}
  void forward()
{
 analogWrite(lmt1,175);
 analogWrite(lmt2,0);
 analogWrite(rmt1,175);
 analogWrite(rmt2,0); 
}
    void left()
 {
 analogWrite(lmt1,175);
 analogWrite(lmt2,0);
 analogWrite(rmt1,0);
 analogWrite(rmt2,175);
 }
  void right()
{
 analogWrite(lmt1,0);
 analogWrite(lmt2,175);
 analogWrite(rmt1,175);
 analogWrite(rmt2,0);
}
 void Stopleft()
{
 analogWrite(lmt1,0);
 analogWrite(lmt2,0);
 analogWrite(rmt1,255);
 analogWrite(rmt2,0); 
}
 void Stopright()
 {
 analogWrite(lmt1,255);
 analogWrite(lmt2,0);
 analogWrite(rmt1,0);
 analogWrite(rmt2,0); 
}
 void slowleft()
 {
 analogWrite(lmt1,175);
 analogWrite(lmt2,0);
 analogWrite(rmt1,200);
 analogWrite(rmt2,0); 
}
 void slowright()
{
 analogWrite(lmt1,200);
 analogWrite(lmt2,0);
 analogWrite(rmt1,175);
 analogWrite(rmt2,0); 
}
