#include <Servo.h>
Servo s1;
Servo s2;
int ls=A0,cs=A1,rs=A2,bls=A3,brs=A4,dfl=7,dfr=8,dbl=9,dbr=10;
int lsv,csv,rsv,blsv,brsv,dflv,dfrv,dblv,dbrv;
void setup()
{
 s1.attach(4);
 s2.attach(6);
 pinMode(ls,INPUT);
 pinMode(cs,INPUT); 
 pinMode(rs,INPUT);
 pinMode(bls,INPUT);
 pinMode(brs,INPUT);
 pinMode(dfl,INPUT);
 pinMode(dfr,INPUT);
 pinMode(dbl,INPUT);
 pinMode(dbr,INPUT);
 Serial.begin(9600); 
}
  void loop()
{
 lsv=digitalRead(ls);
 csv=digitalRead(cs);
 rsv=digitalRead(rs);
 blsv=digitalRead(bls);
 brsv=digitalRead(brs);
 dflv=digitalRead(dfl);
 dfrv=digitalRead(dfr);
 dblv=digitalRead(dbl);
 dbrv=digitalRead(dbr);
 if(dflv == LOW && dfrv == LOW && dblv == LOW && dbrv == LOW)
{
 if(lsv == LOW && csv == LOW && rsv == LOW && blsv == LOW && brsv == LOW)  
{
 fwd();
}
 else if(lsv == LOW && csv == HIGH && rsv == LOW && blsv == LOW && brsv == LOW)
{
 fwd();
}
 else if(lsv == LOW && csv == HIGH && rsv == HIGH && blsv == LOW && brsv == LOW)
{
 right();
}
 else if(lsv == HIGH && csv == HIGH && rsv == LOW && blsv == LOW && brsv == LOW)
{
 left();
}
 else if(lsv == LOW && csv == LOW && rsv == HIGH && blsv == LOW && brsv == LOW)
{
 right();
} 
 else if(lsv == HIGH && csv == LOW && rsv == LOW && blsv == LOW && brsv == LOW)
{
 left();
} 
 else if(lsv == HIGH && csv == HIGH && rsv == HIGH && blsv == LOW && brsv == LOW)
{
 fwd();
}
 else if(lsv == LOW && csv == LOW && rsv == LOW && blsv == HIGH && brsv == LOW)
{
 left();
}
 else if(lsv == LOW && csv == LOW && rsv == LOW && blsv == LOW && brsv == HIGH)
{
 right();
}
 else if(lsv == LOW && csv == LOW && rsv == LOW && blsv == HIGH && brsv == HIGH)
{
 fwd();
 delay(200);
 left();
}
}
else if(dflv == HIGH && dfrv == HIGH && dblv == HIGH && dbrv == HIGH)
{
right();
}
else if(dflv == HIGH && dfrv == HIGH && dblv == LOW && dbrv == LOW)
{
back();
delay(500);
left();
}
else if(dflv == LOW && dfrv == LOW && dblv == HIGH && dbrv == HIGH)
{
 fwd(); 
}
else if(dflv == LOW && dfrv == HIGH && dblv == LOW && dbrv == LOW)
{
 back(); 
}
else if(dflv == HIGH && dfrv == LOW && dblv == LOW && dbrv == LOW)
{
 back(); 
}
else if(dflv == LOW && dfrv == LOW && dblv == HIGH && dbrv == LOW)
{
 fwd(); 
}
else if(dflv == LOW && dfrv == LOW && dblv == LOW && dbrv == HIGH)
{
 fwd(); 
}
else if(dflv == LOW && dfrv == HIGH && dblv == LOW && dbrv == HIGH)
{
 back(); 
}
else if(dflv == HIGH && dfrv == LOW && dblv == HIGH && dbrv == LOW)
{
 back(); 
}
}
  void fwd()
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
