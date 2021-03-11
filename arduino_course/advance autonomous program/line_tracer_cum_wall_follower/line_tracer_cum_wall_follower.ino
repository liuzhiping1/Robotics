int LM_1 = 5;         // the motor pins are intiated as per ports in Auton shield
int LM_2 = 3;
int RM_1 = 6;
int RM_2 = 11;
int s = 75, ts = 50;

void setup()
{
  pinMode(LM_1, OUTPUT);     // motor is initiated as output
  pinMode(LM_2, OUTPUT);
  pinMode(RM_1, OUTPUT);
  pinMode(RM_2, OUTPUT);
  pinMode(A0, INPUT);        // sensor is initiated as input
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(12, INPUT);
  pinMode(13, INPUT);
}

void loop()
{
  int S1 = digitalRead(A0);  // data from all 5 sensors is read and stored
  int S2 = digitalRead(A1);
  int S3 = digitalRead(A2);
  int S4 = digitalRead(A3);
  int S5 = digitalRead(A4);
  int WL = digitalRead(12);
  int WR = digitalRead(13);

  if (WL == LOW && WR == LOW)//value from wall sensors
  {
    if (S1 == LOW && S5 == LOW)  // value of last two sensors is first checked, if they are low then middle sensors are checked
    {
      if (S2 == LOW && S3 == LOW && S4 == LOW) //the robot is perfectly on the line-centre sensor alone senses the line-the robot has to move front
      {
        left();
      }
            if (S2 == HIGH && S3 == LOW && S4 == LOW) //the robot is perfectly on the line-centre sensor alone senses the line-the robot has to move front
      {
        left();
      }
            if (S2 == LOW && S3 == LOW && S4 == HIGH) //the robot is perfectly on the line-centre sensor alone senses the line-the robot has to move front
      {
        rigt();
      }
      else  if (S2 == LOW && S3 == HIGH && S4 == LOW) //the robot is not perfectly on the line; centre & left sensor senses the line - robot has to turn left
      {
        fwd();
      }
      else  if (S2 == HIGH && S3 == HIGH && S4 == LOW) //the robot is not perfectly on the line; centre & left sensor senses the line - robot has to turn left
      {
        slow_left();
      }

      else if (S2 == LOW && S3 == HIGH && S4 == HIGH) //the robot is not perfectly on the line; centre & right sensor senses the line - robot has to turn right
      {
        slow_right();
      }
    }

    else if (S1 == HIGH && S5 == LOW)          // the left most sensor alone senses line - without checking other sensors - robot turns left
    {
      stop_left();
    }

    else if (S1 == LOW && S5 == HIGH)         // the right most sensor alone senses line - without checking other sensors - robot turns right
    {
      stop_rigt();
    }

    else if (S1 == HIGH && S5 == HIGH)
    {
      if (S2 == HIGH && S3 == HIGH && S4 == HIGH)
      {
        stp();
      }
    }
  }

  ////////////////////////////////////////////
  else if (WL == HIGH)
  {
    fwd();
  }
  else if (WR == HIGH)
  {
    fwd();
  }
  else if (WL == HIGH && WR == HIGH)
  {
    fwd();
  }
  ////////////////////////////////////////////
}
void fwd()
{
  analogWrite(LM_1, s);
  analogWrite(LM_2, 0);
  analogWrite(RM_1, s);
  analogWrite(RM_2, 0);
}
void rigt()
{
  analogWrite(LM_1, 0);
  analogWrite(LM_2, ts);
  analogWrite(RM_1, ts);
  analogWrite(RM_2, 0);
}
void left()
{
  analogWrite(LM_1, ts);
  analogWrite(LM_2, 0);
  analogWrite(RM_1, 0);
  analogWrite(RM_2, ts);
}
void stop_left()
{
  analogWrite(LM_1, 0);
  analogWrite(LM_2, 0);
  analogWrite(RM_1, ts);
  analogWrite(RM_2, 0);
}
void stop_rigt()
{
  analogWrite(LM_1, ts);
  analogWrite(LM_2, 0);
  analogWrite(RM_1, 0);
  analogWrite(RM_2, 0);
}
void slow_left()
{
  analogWrite(LM_1, ts);
  analogWrite(LM_2, 0);
  analogWrite(RM_1, s);
  analogWrite(RM_2, 0);
}
void slow_right()
{
  analogWrite(LM_1, s);
  analogWrite(LM_2, 0);
  analogWrite(RM_1, ts);
  analogWrite(RM_2, 0);
}
void stp()
{
  analogWrite(LM_1, 0);
  analogWrite(LM_2, 0);
  analogWrite(RM_1, 0);
  analogWrite(RM_2, 0);

}

