int LM_1 = 5;         // the motor pins are intiated as per ports in Auton shield
int LM_2 = 3;
int RM_1 = 6;
int RM_2 = 11;
int LMS = A0, LS = A1, CS = A2, RS = A3, RMS = A4;
int lms, rms, ls, rs, cs, s;
int spd = 50, tspd = 25;
void setup()
{
  pinMode(LS, INPUT);
  pinMode(CS, INPUT);
  pinMode(LMS, INPUT);
  pinMode(LS, INPUT);
  pinMode(RMS, INPUT);
  pinMode(LM_1, OUTPUT);     // motor is initiated as output
  pinMode(LM_2, OUTPUT);
  pinMode(RM_1, OUTPUT);
  pinMode(RM_2, OUTPUT);
}
void loop()
{
  lms = digitalRead(LMS);
  ls = digitalRead(LS);
  rms = digitalRead(RMS);
  cs = digitalRead(CS);
  rs = digitalRead(RS);
  if (lms == LOW && rms == LOW)
  {
    if (ls == LOW && cs == LOW && rs == LOW)
    {
      while (s == 0)
      {
        right();
        ls = digitalRead(LS);
        cs = digitalRead(CS);
        rs = digitalRead(RS);
        if (rs == HIGH || cs == HIGH || ls == HIGH)
        {
          s = 1;
        }
      }
      s = 0;


    }

//    else if (ls == HIGH && cs == LOW && rs == HIGH)
//    {
//      right();
//    }
    else if (ls == LOW && cs == HIGH && rs == LOW)
    {
      fwd();
    }
    else if (ls == LOW && cs == HIGH && rs == HIGH)
    {
      fwd();// slowright();
    }
    else if (ls == HIGH && cs == HIGH && rs == LOW)
    {
      fwd();// slowleft();
    }

    else if (ls == HIGH && cs == HIGH && rs == HIGH)
    {
      fwd();
      delay(100);

    }
    else if (ls == HIGH && cs == LOW && rs == LOW)
    {
      slowleft();
    }
    else if (ls == LOW && cs == LOW && rs == HIGH)
    {
      slowright();// stopright();
    }
  }
  else if (lms == HIGH && rms == LOW)
  {
    fwd();
    delay(50);
//    stp();
    ls = digitalRead(LS);
    cs = digitalRead(CS);
    rs = digitalRead(RS);
    if (rs == HIGH || cs == HIGH || ls == HIGH)
    {
      fwd();
      delay(50);
    }
    else
    {
      while (s == 0)
      {
        stopleft();
        ls = digitalRead(LS);
        cs = digitalRead(CS);
        rs = digitalRead(RS);
        if (rs == HIGH || cs == HIGH || ls == HIGH)
        {
          s = 1;
        }
      }
      s = 0;

    }
  }
  else if (lms == LOW && rms == HIGH)
  {
    while (s == 0)
    {
      stopright();
      ls = digitalRead(LS);
      cs = digitalRead(CS);
      rs = digitalRead(RS);
      if (rs == HIGH || cs == HIGH || ls == HIGH)
      {
        s = 1;
      }
    }
    s = 0;
  }
  else if (lms == HIGH && rms == HIGH)
  {
    if (ls == HIGH && cs == HIGH && rs == HIGH)
    {
      while (s == 0)
      {
        fwd();
        ls = digitalRead(LS);
        cs = digitalRead(CS);
        rs = digitalRead(RS);
        if (rs == HIGH || cs == HIGH || ls == HIGH)
        {
          s = 1;
        }
      }
      s = 0;
    }
  }
}
void fwd()
{
  analogWrite(LM_1, spd);
  analogWrite(LM_2, 0);
  analogWrite(RM_1, spd);
  analogWrite(RM_2, 0);
}
void backward()
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
void stopleft()
{
  analogWrite(LM_1, 0);
  analogWrite(LM_2, 0);
  analogWrite(RM_1, tspd);
  analogWrite(RM_2, 0);
}
void stopright()
{
  analogWrite(LM_1, tspd);
  analogWrite(LM_2, 0);
  analogWrite(RM_1, 0);
  analogWrite(RM_2, 0);
}
void slowleft()
{
  analogWrite(LM_1, tspd);
  analogWrite(LM_2, 0);
  analogWrite(RM_1, spd);
  analogWrite(RM_2, 0);
}
void slowright()
{
  analogWrite(LM_1, spd);
  analogWrite(LM_2, 0);
  analogWrite(RM_1, tspd);
  analogWrite(RM_2, 0);
}
//void stp()
//{
//  analogWrite(LM_1, tspd);
//  analogWrite(LM_2, tspd);
//  analogWrite(RM_1, 0);
//  analogWrite(RM_2, 0);
//}



