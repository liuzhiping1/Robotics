int LMT1=5,LMT2 =3,RMT1 =11,RMT2 =6;
int LMS=A0,LS=A1,CS=A2,RS=A3,RMS=A4;
int lms,rms,ls,rs,cs,s;
int spd=70 ,turnspd=35;
void setup()
{
  pinMode(LS,INPUT);
  pinMode(CS,INPUT);
  pinMode(LMS,INPUT);
  pinMode(LS,INPUT);
  pinMode(RMS,INPUT);
  pinMode(LMT1,OUTPUT);
  pinMode(LMT2,OUTPUT);
  pinMode(RMT1,OUTPUT);
  pinMode(RMT2,OUTPUT);
}
void loop()
{ 
  lms=digitalRead(LMS);
  ls=digitalRead(LS);
  rms=digitalRead(RMS);
  cs=digitalRead(CS);
  rs=digitalRead(RS);
  if (lms==HIGH&&rms==HIGH)
  {
    fwd();
     if (ls==HIGH&&cs==HIGH&&rs==HIGH)
    {
      while(s==1)
      {
        right();
        ls=digitalRead(LS);
        cs=digitalRead(CS);
        rs=digitalRead(RS);
        if(rs==LOW || cs==LOW || ls==LOW)
        {
          s=0;
        }
      }
      s=1;


    }
   
    else if(ls==LOW&&cs==HIGH&&rs==LOW)
    {
      right();
    }
    else if(ls==HIGH&&cs==LOW&&rs==HIGH)
    {
      fwd();
    }
    else if(ls==HIGH&&cs==LOW&&rs==LOW)
    {
      slowright();
    }
    else if(ls==LOW&&cs==LOW&&rs==HIGH)
    {
      slowleft();
    }

    else if(ls==LOW&&cs==LOW&&rs==LOW)
    {
      right();

    }
    else if(ls==LOW&&cs==HIGH&&rs==HIGH)
    {
      stopleft();
    }
     else if(ls==HIGH&&cs==HIGH&&rs==LOW)
    {
      stopright();
    }
  }  
  else if (lms==LOW&&rms==HIGH)
  {
    fwd();
    delay(100);
    stp();
    ls=digitalRead(LS);
    cs=digitalRead(CS);
    rs=digitalRead(RS);
    if(rs==LOW || cs==LOW || ls==LOW)
    {
      fwd();
    }
    else
    {
      while(s==1)
      {
        left();
        ls=digitalRead(LS);
        cs=digitalRead(CS);
        rs=digitalRead(RS);
        if(rs==LOW || cs==LOW || ls==LOW)
        {
          s=0;
        }
      }
      s=1;

    }
  }
  else if (lms==HIGH&&rms==LOW)
  {
    while(s==1)
    {
      right();
      ls=digitalRead(LS);
      cs=digitalRead(CS);
      rs=digitalRead(RS);
      if(rs==LOW || cs==LOW || ls==LOW)
      {
        s=0;
      }
    }
    s=1;
  }
  else if (lms==LOW&&rms==LOW)
  {
    while(s==1)
    {
      right();
      ls=digitalRead(LS);
      cs=digitalRead(CS);
      rs=digitalRead(RS);
      if(rs==LOW || cs==LOW || ls==LOW)
      {
        s=0;
      }
    }
    s=1;
  }
}
void fwd()
{
  analogWrite(LMT1,spd);
  analogWrite(LMT2,0);
  analogWrite(RMT1,spd);
  analogWrite(RMT2,0);
}

void right()
{
  analogWrite(LMT1,0);
  analogWrite(LMT2,spd);
  analogWrite(RMT1,spd);
  analogWrite(RMT2,0);
}

void left()
{
  analogWrite(LMT1,spd);
  analogWrite(LMT2,0);
  analogWrite(RMT1,0);
  analogWrite(RMT2,spd);
}
void slowright()
{
  analogWrite(LMT1,spd);
  analogWrite(LMT2,0);
  analogWrite(RMT1,turnspd);
  analogWrite(RMT2,0);
}
void slowleft()
{
  analogWrite(LMT1,spd);
  analogWrite(LMT2,0);
  analogWrite(RMT1,turnspd);
  analogWrite(RMT2,0);
}
void stopright()
{
  analogWrite(LMT1, spd);
  analogWrite(LMT2, 0);
  analogWrite(RMT1, 0);
  analogWrite(RMT2, 0);
}
void stopleft()
{
  analogWrite(LMT1, 0);
  analogWrite(LMT2, 0);
  analogWrite(RMT1, spd);
  analogWrite(RMT2, 0);
}
void stp()
{
  analogWrite(LMT1, 0);
  analogWrite(LMT2, 0);
  analogWrite(RMT1, 0);
  analogWrite(RMT2, 0);
}
