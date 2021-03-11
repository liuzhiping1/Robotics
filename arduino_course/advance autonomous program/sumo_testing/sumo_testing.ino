int ls=A0;
int cs=A1;
int rs=A2;
int lsv;
int csv;
int rsv;
#include <Servo.h>
Servo s1;
Servo s2;
  void setup()
{
  s1.attach(5);
  s2.attach(6);
  pinMode(ls,INPUT);
  pinMode(cs,INPUT); 
  pinMode(rs,INPUT);
 Serial.begin(9600); 
}
void loop()
{
  lsv=digitalRead(ls);
  csv=digitalRead(cs);
  rsv=digitalRead(rs);
  if(lsv==LOW&&csv==LOW&&rsv==LOW)
  {
    fwd();
  }
  else if(lsv==HIGH&&csv==LOW&&rsv==LOW) 
  {
    left();
  }
  else if(lsv==LOW&&csv==LOW&&rsv==HIGH)
  {
    right();
  }
  else if(lsv==LOW&&csv==HIGH&&rsv==LOW)
  {
    fwd();
  }
  else if(lsv==HIGH&&csv==HIGH&&rsv==LOW) 
  {
    fwd();
  }
  else if(lsv==LOW&&csv==HIGH&&rsv==HIGH) 
  {
    fwd();
  }
  else if(lsv==HIGH&&csv==LOW&&rsv==HIGH)
  {
    fwd();
  } 
   else if(lsv==HIGH&&csv==HIGH&&rsv==HIGH)
  {
    fwd();
  } 
}
    void left()
 {
 s1.write(1);
 s2.write(180);
 }
  void right()
{
 s1.write(180);
 s2.write(1);
}
 void back()
{
 s1.write(1);
 s2.write(1);
}
 void Stop()
{
 s1.write(94);
 s2.write(94);
}
  void fwd()
{
 s1.write(180);
 s2.write(180);
}

