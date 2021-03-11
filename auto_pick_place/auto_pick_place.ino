#include <Servo.h>
int WA_1 = 6;
int WA_2 = 5;
int c = 0, n;
Servo s1;
Servo s2;
void setup()
{
  s1.attach(11);
  s2.attach(10);
  pinMode(WA_1, OUTPUT);
  pinMode(WA_2, OUTPUT);
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



  if (S1 == LOW && S5 == LOW)  // value of last two sensors is first checked, if they are low then middle sensors are checked
  {
    if (S2 == LOW && S3 == HIGH && S4 == LOW) //the robot is perfectly on the line-centre sensor alone senses the line-the robot has to move front
    {
      fwd();
      Serial.println("fwd");
    }

    if (S2 == HIGH && S3 == HIGH && S4 == LOW) //the robot is not perfectly on the line; centre & left sensor senses the line - robot has to turn left
    {
      left();
    }

    if (S2 == LOW && S3 == HIGH && S4 == HIGH) //the robot is not perfectly on the line; centre & right sensor senses the line - robot has to turn right
    {
      right();
    }
    if (S2 == HIGH && S3 == HIGH && S4 == HIGH) //the robot is not perfectly on the line; centre & right sensor senses the line - robot has to turn right
    {
      fwd();
    }
  }

  else if (S1 == HIGH && S5 == LOW)          // the left most sensor alone senses line - without checking other sensors - robot turns left
  {
    left();
  }

  else if (S1 == LOW && S5 == HIGH)         // the right most sensor alone senses line - without checking other sensors - robot turns right
  {
    right();
  }

  else if (S1 == HIGH && S5 == HIGH)      // left proirity comes into play, hence robot has to turn left
  {
    if (S2 == HIGH && S3 == HIGH && S4 == HIGH)
    {
      Stp();
      Serial.println("HIGH ALL");
      c = c + 1;
      n = c % 2;
      switch (n)
      {
        case 1:
          walldown();
          delay(3000);
          break;
        case 0:
          wallup();
          delay(3000);
          break;
      }
      fwd();
      delay(99);
    }
  }
}
void fwd()
{
  s1.write(145);
  s2.write(145);
}
void left()
{
  s1.write(45);
  s2.write(145);
}
void right()
{
  s1.write(145);
  s2.write(45);
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
void wallup()
{
  digitalWrite(WA_1, 255);      //robot turns right
  digitalWrite(WA_2, 0);
}
void walldown()
{
  digitalWrite(WA_1, 0);      //robot turns right
  digitalWrite(WA_2, 255);
}
