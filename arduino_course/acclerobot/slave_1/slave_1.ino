#include <Servo.h>
#include <SoftwareSerial.h>
SoftwareSerial s(10, 11); //RX,TX
int lm1 = 3, lm2 = 5, rm1 = 6, rm2 = 11;
int y,x,f;
Servo servo;
void setup() {
  pinMode(lm1, OUTPUT);
  pinMode(lm2, OUTPUT);
  pinMode(rm1, OUTPUT);
  pinMode(rm2, OUTPUT);
  s.begin(9600);
  s.setTimeout(5);
 servo.attach(9);
}

void loop() {
  while(s.available())
// if(s.available()>0)
 {
 //x=s.parseInt();
 //y=s.parseInt();
   if (x >= 315 && x <= 330 && y >= 315 && y <= 335)
  {
    analogRead(lm1,0);
    analogRead(lm2,0);
    analogRead(rm1,0);
    analogRead(rm2,0);
    
  }
  // y=s.parseInt();
  else if(y >= 336 && y <= 349)
  {
     y=map(y,336,391,0,255);
    analogRead(3,y);

  }
 }
}

