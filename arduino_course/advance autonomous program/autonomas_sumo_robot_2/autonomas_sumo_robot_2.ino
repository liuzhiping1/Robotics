#include <Servo.h>
Servo s1;
Servo s2;
int ls=A0,cs=A1,rs=A2,bls=A3,brs=A4,df=7,db=8;
int lsv,csv,rsv,blsv,brsv,dfv,dbv;
void setup()
{
 s1.attach(5);
 s2.attach(6);
 pinMode(ls,INPUT);
 pinMode(cs,INPUT); 
 pinMode(rs,INPUT);
 pinMode(bls,INPUT);
 pinMode(brs,INPUT);
 pinMode(df,INPUT);
 pinMode(db,INPUT);
 Serial.begin(9600); 
}
  void loop()
{
 lsv=digitalRead(ls);
 csv=digitalRead(cs);
 rsv=digitalRead(rs);
 blsv=digitalRead(bls);
 brsv=digitalRead(brs);
 dfv=digitalRead(df);
 dbv=digitalRead(db);
 if(dfv == LOW && dbv == LOW )
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
else if(dfv == LOW && dbv == HIGH )
{
 fwd();
}
else if(dfv == HIGH && dbv == LOW )
{
  back();
 delay(500);  
 left();
 delay(1000);
 fwd();
}
else if(dfv == HIGH && dbv == HIGH )
{
 Stop(); 
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
