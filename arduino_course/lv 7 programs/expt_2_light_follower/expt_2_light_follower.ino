int lmt1=5,lmt2=6,rmt1=11,rmt2=10;
int ls=A0;
int cs=A1;
int rs=A2;
int lsv;
int csv;
int rsv;
  void setup()
{
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
  digitalWrite(lmt1,HIGH);
  digitalWrite(lmt2,LOW);
  digitalWrite(rmt1,HIGH);
  digitalWrite(rmt2,LOW); 
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

