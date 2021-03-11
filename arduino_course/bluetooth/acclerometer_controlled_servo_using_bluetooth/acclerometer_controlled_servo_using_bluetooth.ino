#include <Servo.h>
Servo servo;
int y;
void setup()
{
 Serial.begin(9600);
 Serial.setTimeout(5);
 servo.attach(9);
}
 void loop()
{
 if(Serial.available()>0)
{
 y=Serial.parseInt();
 if (y>-95 && y<95)
{
 y=map(y,-95,95,0,180);
servo.write(y);
}
}
}

