#include <VarSpeedServo.h>
VarSpeedServo f3;
VarSpeedServo b3;
int n=90,l=10,m=20,b=30,x=150;
void setup()
{
  b3.attach(3);
  f3.attach(9);
  b3.slowmove(n,40);
  f3.slowmove(n,40);
  delay(1000);
}
void loop()
{
 f3.slowmove(n-l,40);
 delay(x);
 b3.slowmove(n-m,40);
 delay(x);
 
 b3.slowmove(n+b,40);
} 
