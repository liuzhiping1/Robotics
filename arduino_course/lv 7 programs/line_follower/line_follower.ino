int LMT1 = 5, LMT2 = 3, RMT1 = 11, RMT2 = 6;
int LMSV, LSV, CSV, RSV, RMSV;
int spd=200 , turnspd=150 ;

void setup()
{
  pinMode(LMT1, OUTPUT);
  pinMode(LMT2, OUTPUT);
  pinMode(RMT1, OUTPUT);
  pinMode(RMT2, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
}

void loop()
{
  LMSV = digitalRead(A0);
  LSV = digitalRead(A1);
  CSV = digitalRead(A2);
  RSV = digitalRead(A3);
  RMSV = digitalRead(A4);

  if (LMSV == LOW && RMSV == LOW)
  {
    if (LSV == LOW && CSV == LOW && RSV == LOW)
    {
      left();
    }
    else if (LSV == HIGH && CSV == LOW && RSV == LOW)
    {
      slow_left();
    }
    else if (LSV = LOW && CSV == HIGH && RSV == LOW)
    {
      fwd();
    }
    else if (LSV == LOW && CSV == LOW && RSV == HIGH)
    {
      slow_right();
    }
    else if (LSV == HIGH && CSV == HIGH && RSV == LOW)
    {
      slow_left();
    }
    else if (LSV == LOW && CSV == HIGH && RSV == HIGH)
    {
      slow_right();
    }
    else if (LSV == HIGH && CSV == LOW && RSV == HIGH)
    {
      fwd();
    }
    else if (LSV == HIGH && CSV == HIGH && RSV == HIGH)
    {
      fwd();
    }
    }
  else if (LMSV == LOW && RMSV == HIGH)
  {
    right();
  }
  else if (LMSV == HIGH && RMSV == LOW)
  {
    left();
  }
  else if (LMSV == HIGH && RMSV == HIGH)
  {
    left();
  }
}


void fwd()
{
  analogWrite(LMT1, spd);
  analogWrite(LMT2, 0);
  analogWrite(RMT1, spd);
  analogWrite(RMT2, 0);
}
void right()
{
  analogWrite(LMT1, 0);
  analogWrite(LMT2, turnspd);
  analogWrite(RMT1, turnspd);
  analogWrite(RMT2, 0);
}
void left()
{
  analogWrite(LMT1, turnspd);
  analogWrite(LMT2, 0);
  analogWrite(RMT1, 0);
  analogWrite(RMT2, turnspd);
}
void stop_left()
{
  analogWrite(LMT1, 0);
  analogWrite(LMT2, 0);
  analogWrite(RMT1, turnspd);
  analogWrite(RMT2, 0);
}
void stop_right()
{
  analogWrite(LMT1, turnspd);
  analogWrite(LMT2, 0);
  analogWrite(RMT1, 0);
  analogWrite(RMT2, 0);
}
void slow_left()
{
  analogWrite(LMT1, turnspd);
  analogWrite(LMT2, 0);
  analogWrite(RMT1, spd);
  analogWrite(RMT2, 0);
}
void slow_right()
{
  analogWrite(LMT1, spd);
  analogWrite(LMT2, 0);
  analogWrite(RMT1, turnspd);
  analogWrite(RMT2, 0);
}


