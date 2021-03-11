int lmt1=6,lmt2=5,rmt1=10,rmt2=11;
int ms=A0,bs=A1,ls=A2,cs=A3,rs=A4;
int msv,bsv,lsv,csv,rsv;
void setup()
{
 pinMode(ms,INPUT);
 pinMode(bs,INPUT); 
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
 msv=digitalRead(ms);
 bsv=digitalRead(bs);
 lsv=digitalRead(ls);
 csv=digitalRead(cs);
 rsv=digitalRead(rs);
 if(msv==LOW&&bsv==LOW)
{
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
 left();
} 
 else if(lsv==LOW&&csv==HIGH&&rsv==HIGH)
{
 right();
} 
 else if(lsv==HIGH&&csv==HIGH&&rsv==HIGH)
{
 forward();
}
}
else if(msv==HIGH&&bsv==LOW)
{
 back();
 delay(500);
 left();
 delay(1000);
}
else if(msv==LOW&&bsv==HIGH)
{
forward();
}
else if(lsv==HIGH&&csv==HIGH)
{
 forward(); 
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
  void right()
{
 digitalWrite(lmt1,HIGH);
 digitalWrite(lmt2,LOW);
 digitalWrite(rmt1,LOW);
 digitalWrite(rmt2,HIGH);
}
 void back()
{
  digitalWrite(lmt1,LOW);
 digitalWrite(lmt2,HIGH);
 digitalWrite(rmt1,LOW);
 digitalWrite(rmt2,HIGH);
}
