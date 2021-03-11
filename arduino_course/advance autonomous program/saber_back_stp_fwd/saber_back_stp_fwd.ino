 #include <Servo.h>
Servo s1;
Servo s2;
void setup()
{
 s1.attach(5);
 s2.attach(6);
 Serial.begin(9600);
}
void loop()
{
 s1.write(1);
 s2.write(1);
 delay(1000);
 s1.write(94);
 s2.write(94);
 delay(1000);
 s1.write(180);
 s2.write(180);
 delay(1000);
 s1.write(1);
 s2.write(180);
 delay(1000);
 s1.write(180);
 s2.write(1);
 delay(1000);
}

