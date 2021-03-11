int lmt1=6,lmt2=5,rmt1=10,rmt2=11;
int ls=A0;
int cs=A1;
int lsv;
int csv;
  void setup()
{
  pinMode(ls,INPUT);
  pinMode(cs,INPUT); 
  pinMode(lmt1,OUTPUT);
  pinMode(lmt2,OUTPUT);
  pinMode(rmt1,OUTPUT);
  pinMode(rmt2,OUTPUT); 
}
void loop()
{
  lsv=digitalRead(ls);
  csv=digitalRead(cs);
  if(lsv==LOW&&csv==LOW)
{
  Stopleft();
}
 else if(lsv==HIGH&&csv==LOW)
{
 Stopright();
}
 else if(lsv==LOW&&csv==HIGH)
{
 right();
 delay(500);
}
 else if(lsv==HIGH&&csv==HIGH)
{
 right();
 delay(500);
}
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
  void right()
{
 digitalWrite(lmt1,HIGH);
 digitalWrite(lmt2,LOW);
 digitalWrite(rmt1,LOW);
 digitalWrite(rmt2,HIGH);
} 
  
  
  
  
  
  
  
  
