#include <VarSpeedServo.h>
VarSpeedServo bs;
VarSpeedServo s1;
VarSpeedServo s2;
VarSpeedServo s3;
VarSpeedServo rs;
VarSpeedServo gs;
void setup()
{
  bs.attach(2);
  s1.attach(3); 
  s2.attach(4);
  s3.attach(5);
  rs.attach(6);
  gs.attach(7);
  bs.slowmove(90,40);
  s1.slowmove(90,40);
  s2.slowmove(90,40); 
  s3.slowmove(90,40);
  rs.slowmove(90,40);
  gs.slowmove(60,40);
  delay(2000);
} 
void loop()
{
  bs.slowmove(180,40);
  delay(2000);

  gs.slowmove(0,40);
  delay(1000);
  gs.slowmove(60,40);
  delay(1000);

  bs.slowmove(0,40);
  delay(2000); 

  gs.slowmove(0,40);
  delay(1000);
  gs.slowmove(60,40);
  delay(1000);
}



