int LM_1 = 3;         // the motor pins are intiated as per ports in Auton shield
int LM_2 = 5;
int RM_1 = 11;
int RM_2 = 6;


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

  else if (S1 == HIGH && S5 == HIGH)      // left proirity comes into play, hence robot has to turn left
  {
    if (S2 == HIGH && S3 == HIGH && S4 == HIGH)
    {
      left();
    }
  }
}
void fwd()
{
  digitalWrite(LM_1, HIGH);      // robot moves forward
  digitalWrite(LM_2, LOW);
  digitalWrite(RM_1, HIGH);
  digitalWrite(RM_2, LOW);
}
void stp()
{
  digitalWrite(LM_1, LOW);      // robot moves forward
  digitalWrite(LM_2, LOW);
  digitalWrite(RM_1, LOW);
  digitalWrite(RM_2, LOW);

}
void back()
{
  digitalWrite(LM_1, LOW);      // robot moves BACK
  digitalWrite(LM_2, HIGH);
  digitalWrite(RM_1, LOW);
  digitalWrite(RM_2, HIGH);
}
void left()
{
  digitalWrite(LM_1, LOW);       // robot turns left
  digitalWrite(LM_2, HIGH);
  digitalWrite(RM_1, HIGH);
  digitalWrite(RM_2, LOW);
}
void rigt()
{
  digitalWrite(LM_1, HIGH);      //robot turns right
  digitalWrite(LM_2, LOW);
  digitalWrite(RM_1, LOW);
  digitalWrite(RM_2, HIGH);
}
