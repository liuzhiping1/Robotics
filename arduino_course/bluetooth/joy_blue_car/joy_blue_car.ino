int lmt1=5,lmt2=6,rmt1=11,rmt2=10;
int w =0;
int s =1;
int a =2;
int d =3;
int x =4;
int flag = 0; 

void setup()
{
 
 Serial.begin(9600);
 pinMode(lmt1,OUTPUT);
 pinMode(lmt2,OUTPUT);
 pinMode(rmt1,OUTPUT);
 pinMode(rmt2,OUTPUT);
 Stop();
}
void loop() 
{
if(Serial.available() > 4)
{
 w = Serial.read();
 s = Serial.read();
 a = Serial.read();
 d = Serial.read();
 x = Serial.read();
flag=0;
}
if (w ==HIGH ) 
{
forward();
if(flag == 0)
{
Serial.println("forward");
flag = 1;
}
}
else if (s ==HIGH )
{
back();
if(flag == 0)
{
Serial.println("back");
flag = 1;
}
}
 else if (a ==HIGH ) 
{
left();
if(flag == 0)
{
Serial.println("left");
flag = 1;
}
}
else if (d ==HIGH )
{
right();
if(flag == 0)
{
Serial.println("right");
flag = 1;
}
}
else if (x ==HIGH )
{
Stop();
if(flag == 0)
{
Serial.println("stop");
flag = 1;
}
}
}
 void forward()
{
 digitalWrite(lmt1,HIGH);
 digitalWrite(lmt2,LOW);
 digitalWrite(rmt1,HIGH);
 digitalWrite(rmt2,LOW); 
}
 void back()
{
 digitalWrite(lmt1,LOW);
 digitalWrite(lmt2,HIGH);
 digitalWrite(rmt1,LOW);
 digitalWrite(rmt2,HIGH);
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
  void Stop()
{
 digitalWrite(lmt1,LOW);
 digitalWrite(lmt2,LOW);
 digitalWrite(rmt1,HIGH);
 digitalWrite(rmt2,HIGH);
}
