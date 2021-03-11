 #include <Servo.h>
Servo s1;
int i;
void setup()
{
 s1.attach(9);
}
void loop()
{
  for(i=45;i<=135;i=i++)
{
 s1.write(i);
 delay(50);
}
  for(i=135;i>=45;i=i--)
{
 s1.write(i);
 delay(50);
}
}
