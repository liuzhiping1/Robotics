#include <Servo.h>
Servo s1;
int d1,d2,d3,t1,t2,t3;
int lmt1=5,lmt2=6,rmt1=11,rmt2=10;
void setup()
{
 s1.attach(8); 
 Serial.begin(9600);
 pinMode(lmt1,OUTPUT);
 pinMode(lmt2,OUTPUT);
 pinMode(rmt1,OUTPUT);
 pinMode(rmt2,OUTPUT); 
}
 void loop()
{
 s1.write(45);
 delay(500);
 pinMode(9,OUTPUT);
 digitalWrite(9,LOW); 
 delayMicroseconds(2);
 digitalWrite(9,HIGH);
 delayMicroseconds(5);
 digitalWrite(9,LOW);
 delayMicroseconds(2);  
 
 pinMode(9,INPUT);
 t1=pulseIn(9,HIGH);
 d1=(t1/29)/2;
 Serial.print("D1:");
 Serial.println(d1);
 delay(100);
 
 s1.write(90);
 delay(500);
 pinMode(9,OUTPUT);
 digitalWrite(9,LOW); 
 delayMicroseconds(2);
 digitalWrite(9,HIGH);
 delayMicroseconds(5);
 digitalWrite(9,LOW);
 delayMicroseconds(2);
 
 pinMode(9,INPUT);
 t2=pulseIn(9,HIGH);
 d2=(t2/29)/2;
 Serial.print("D2:");
 Serial.println(d2);
 delay(100);
 
 s1.write(135);
 delay(500);
 pinMode(9,OUTPUT);
 digitalWrite(9,LOW); 
 delayMicroseconds(2);
 digitalWrite(9,HIGH);
 delayMicroseconds(5);
 digitalWrite(9,LOW);
 delayMicroseconds(2);
 
  pinMode(9,INPUT);
 t3=pulseIn(9,HIGH);
 d3=(t3/29)/2;
 Serial.print("D3:");
 Serial.println(d3);
 delay(100);
 
 forward();
 
 if(d1<d2 && d1<d3)
 {
  right();
 }
 else if(d2<d1 && d2<d3)
 {
  back(); 
  delay(1000); 
  left();
 } 
  if(d3<d1 && d3<d2)
 {
  left();
 }
  delay(500);
  Stop(); 
 }
 
  void forward()
 {
 digitalWrite(lmt1,HIGH);
 digitalWrite(lmt2,LOW);
 digitalWrite(rmt1,HIGH);
 digitalWrite(rmt2,LOW);
 Serial.print("forward"); 
 }
   void back()
 {
 digitalWrite(lmt1,LOW);
 digitalWrite(lmt2,HIGH);
 digitalWrite(rmt1,LOW);
 digitalWrite(rmt2,HIGH);
 Serial.print("back"); 
 }
 void left()
 {
 digitalWrite(lmt1,LOW);
 digitalWrite(lmt2,HIGH);
 digitalWrite(rmt1,HIGH);
 digitalWrite(rmt2,LOW);
 Serial.print("left");
 }
  void right()
{
 digitalWrite(lmt1,HIGH);
 digitalWrite(lmt2,LOW);
 digitalWrite(rmt1,LOW);
 digitalWrite(rmt2,HIGH);
 Serial.print("right");
}
  void Stop()
{
 digitalWrite(lmt1,LOW);
 digitalWrite(lmt2,LOW);
 digitalWrite(rmt1,HIGH);
 digitalWrite(rmt2,HIGH);
 Serial.print("stop");
}
