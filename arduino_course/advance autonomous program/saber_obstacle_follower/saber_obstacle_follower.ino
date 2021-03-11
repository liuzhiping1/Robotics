#include <Servo.h>
Servo s1;
Servo s2;
int lmt1=5,lmt2=6,rmt1=11,rmt2=10;
int ls=A0;
int cs=A1;
int rs=A2;
int lsv;
int csv;
int rsv;
  void setup()
{
  s1.attach(5);
  s2.attach(6);
  Serial.begin(9600);
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
  lsv=digitalRead(ls);
  csv=digitalRead(cs);
  rsv=digitalRead(rs);
  if(lsv==LOW&&csv==LOW&&rsv==LOW)
  {
    forward();
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
    forward();
  }
  else if(lsv==HIGH&&csv==HIGH&&rsv==LOW) 
  {
    forward();
  }
  else if(lsv==LOW&&csv==HIGH&&rsv==HIGH) 
  {
    forward();
  }
  else if(lsv==HIGH&&csv==LOW&&rsv==HIGH)
  {
    forward();
  } 
   else if(lsv==HIGH&&csv==HIGH&&rsv==HIGH)
  {
    forward();
  } 
  }
  void forward()
{
 s1.write(180);
 s2.write(180);
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

