 #include <Servo.h>
Servo s1;
void setup()
{
 s1.attach(9);
}
void loop()
{
 s1.write(45);
 delay(1000);
 s1.write(90);
 delay(1000);
 s1.write(135);
 delay(1000);
}

