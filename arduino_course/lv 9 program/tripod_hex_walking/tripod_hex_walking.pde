#include <VarSpeedServo.h>
VarSpeedServo b1;
VarSpeedServo b2;
VarSpeedServo b3;
VarSpeedServo b4;
VarSpeedServo b5;
VarSpeedServo b6;
VarSpeedServo f1;
VarSpeedServo f2;
VarSpeedServo f3;
VarSpeedServo f4;
VarSpeedServo f5;
VarSpeedServo f6;
int n=90,l=10,m=20,b=30,x=150;
void setup()
{
 b1.attach(1); 
 b2.attach(2);
 b3.attach(3);
 b4.attach(4);
 b5.attach(5);
 b6.attach(6);
 f1.attach(7);
 f2.attach(8);
 f3.attach(9);
 f4.attach(10);
 f5.attach(11);
 f6.attach(12);
 b1.slowmove(n,40);
 b2.slowmove(n,40);
 b3.slowmove(n,40);
 b4.slowmove(n,40);
 b5.slowmove(n,40);
 b6.slowmove(n,40);
 f1.slowmove(n,40);
 f2.slowmove(n,40);
 f3.slowmove(n,40);
 f4.slowmove(n,40);
 f5.slowmove(n,40);
 f6.slowmove(n,40);
 delay(1000);
}
void loop()
{
 f1.slowmove(n-l,40);
 f5.slowmove(n+l,40);
 f3.slowmove(n-l,40);
 delay(x);
 
 b1.slowmove(n-m,40);
 b5.slowmove(n+m,40);
 b3.slowmove(n-m,40);
 delay(x);

 f6.slowmove(n,40);
 f2.slowmove(n,40);
 f4.slowmove(n,40);
 delay(x);
 
 b6.slowmove(n+m,40);
 b2.slowmove(n-m,40);
 b4.slowmove(n+m,40);
 delay(x);
   
 f1.slowmove(n+l,40);
 f5.slowmove(n-l,40);
 f3.slowmove(n+l,40);
 delay(x);
 
 b1.slowmove(n+m,40);
 b5.slowmove(n-m,40);
 b3.slowmove(n+m,40);
 delay(x);

 f6.slowmove(n,40);
 f2.slowmove(n,40);
 f4.slowmove(n,40);
 delay(x);
 
 b6.slowmove(n-m,40);
 b2.slowmove(n+m,40);
 b4.slowmove(n-m,40);
 delay(x);

}
