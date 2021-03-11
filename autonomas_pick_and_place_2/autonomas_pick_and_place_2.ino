int a = 0;
#include <Servo.h>
Servo s1;
Servo s2;         // the motor pins are intiated as per ports in saber tooth
int RP_1=5;
int RP_2=3;
void setup()
{
 s1.attach(11);
 s2.attach(10);
  pinMode(A0, INPUT);        // sensor is initiated as input
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  Serial.begin(9600); 
}
void loop()
{
  int S1 = digitalRead(A0);  // data from all 5 sensors is read and stored
  int S2 = digitalRead(A1);
  int S3 = digitalRead(A2);
  int S4 = digitalRead(A3);
  int S5 = digitalRead(A4);
  if (S1 == HIGH && S5 == HIGH)  // value of last two sensors is first checked, if they are low then middle sensors are checked
  {
    if (S2 == HIGH && S3 == HIGH && S4 == HIGH) //the robot is perfectly on the line-centre sensor alone senses the line-the robot has to move front
    {
      stp();
      delay(1000);
      a=a+1;
    }
    if(a==3)
    {
      a=0;
    }
    switch(a)
    {
      case 1;
      up();
      fwd();
      break;
      case 2;
      down();
      fwd();
      break;
    }

    if (S2 == HIGH && S3 == HIGH && S4 == LOW) //the robot is not perfectly on the line; centre & left sensor senses the line - robot has to turn left
    {
      left();
    }

    if (S2 == LOW && S3 == HIGH && S4 == HIGH) //the robot is not perfectly on the line; centre & right sensor senses the line - robot has to turn right
    {
      rigt();
    }
  }

  else if (S1 == HIGH && S5 == LOW)          // the left most sensor alone senses line - without checking other sensors - robot turns left
  {
    left();
  }

  else if (S1 == LOW && S5 == HIGH)         // the right most sensor alone senses line - without checking other sensors - robot turns right
  {
    rigt();
  }

  else if (S1 == LOW && S5 == LOW)      // left proirity comes into play, hence robot has to turn left
  {
    if (S2 == LOW && S3 == LOW && S4 == LOW)
    {
      stp();
    }
  }
}
  void fwd()
{
 s1.write(180);
 s2.write(180);
}
    void left()
 {
 s1.write(1);
 s2.write(180);
 }
  void rigt()
{
 s1.write(180);
 s2.write(1);
}
 void back()
{
 s1.write(1);
 s2.write(1);
}
 void Stp()
{
 s1.write(94);
 s2.write(94);
}
void up()
{
  digitalWrite(RP_1, HIGH);      //robot turns right
  digitalWrite(RP_2, LOW);
}
void down()
{
  digitalWrite(RP_1, LOW);      //robot turns right
  digitalWrite(RP_2, HIGH);

}


