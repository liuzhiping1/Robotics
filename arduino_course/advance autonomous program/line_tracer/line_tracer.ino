int LM_1 = 6;         // the motor pins are intiated as per ports in Auton shield
int LM_2 = 5;
int RM_1 = 10;
int RM_2 = 11;
int spd = 75, tspd = 50;

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
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
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
    if (S2 == LOW && S3 == LOW && S4 == LOW) //the robot is perfectly on the line-centre sensor alone senses the line-the robot has to move front
    {
      left();
    }
    if (S2 == LOW && S3 == HIGH && S4 == LOW)
    {
      fwd();
    }
    if (S2 == HIGH && S3 == LOW && S4 == LOW)
    {
      left();

    }
    if (S2 == LOW && S3 == LOW && S4 == HIGH)
    {
      right();

    }
    if (S2 == HIGH && S3 == HIGH && S4 == LOW)
    {
      fwd();//Slow_left();
      
    }
    if (S2 == LOW && S3 == HIGH && S4 == HIGH)
    {
      fwd();// Slow_right();
      
    }
    if (S2 == HIGH && S3 == HIGH && S4 == HIGH)
    {
      fwd();
    }
  }

  else if (S1 == HIGH && S5 == LOW)          // the left most sensor alone senses line - without checking other sensors - robot turns left
  {
    stp_left();
  }

  else if (S1 == LOW && S5 == HIGH)         // the right most sensor alone senses line - without checking other sensors - robot turns right
  {
   stp_right();
  }

  else if (S1 == HIGH && S5 == HIGH)      // left proirity comes into play, hence robot has to turn left
  {
    if (S2 == HIGH && S3 == HIGH && S4 == HIGH)
    {
     fwd();
      digitalWrite(13,HIGH);
      digitalWrite(12,LOW);
      delay(200);
      digitalWrite(13,LOW);
      digitalWrite(12,LOW); 
    }
  }
 /* if(S1 == HIGH && S2 == HIGH)
  {
    stp_left();
  }
  else if (S4 == HIGH && S5 == HIGH)
  {
    stp_right();
  }*/
  
}
void fwd()
{
  analogWrite(LM_1, spd);
  analogWrite(LM_2, 0);
  analogWrite(RM_1, spd);
  analogWrite(RM_2, 0);
}
void back()
{
  analogWrite(LM_1, 0);
  analogWrite(LM_2, spd);
  analogWrite(RM_1, 0);
  analogWrite(RM_2, spd);
}
void right()
{
  analogWrite(LM_1, spd);
  analogWrite(LM_2, 0);
  analogWrite(RM_1, 0);
  analogWrite(RM_2, spd);
}
void left()
{
  analogWrite(LM_1, 0);
  analogWrite(LM_2, spd);
  analogWrite(RM_1, spd);
  analogWrite(RM_2, 0);
}
void stp_left()
{
  analogWrite(LM_1, 0);
  analogWrite(LM_2, 0);
  analogWrite(RM_1, tspd);
  analogWrite(RM_2, 0);
}
void stp_right()
{
  analogWrite(LM_1, tspd);
  analogWrite(LM_2, 0);
  analogWrite(RM_1, 0);
  analogWrite(RM_2, 0);
}
void Slow_left()
{
    analogWrite(LM_1,tspd);
  analogWrite(LM_2, 0);
  analogWrite(RM_1, spd);
  analogWrite(RM_2, 0);
//  analogWrite(LM_1, 0);
//  analogWrite(LM_2, tspd);
//  analogWrite(RM_1, tspd);
//  analogWrite(RM_2, 0);
}
void Slow_right()
{
     analogWrite(LM_1,spd);
  analogWrite(LM_2, 0);
  analogWrite(RM_1, tspd);
  analogWrite(RM_2, 0);
//  analogWrite(LM_1, tspd);
//  analogWrite(LM_2, 0);
//  analogWrite(RM_1, 0);
//  analogWrite(RM_2, tspd);
}
