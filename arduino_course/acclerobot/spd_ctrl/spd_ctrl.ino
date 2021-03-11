int lm1=3,lm2=5,rm1=11,rm2=6;
int x=A2,y=A3;
int xv,yv;
void setup()
{
 pinMode(lm1,OUTPUT);
 pinMode(lm2,OUTPUT);
 pinMode(rm1,OUTPUT);
 pinMode(rm2,OUTPUT); 
 pinMode(x,INPUT);
 pinMode(y,INPUT);
}
 void loop()
{
  xv=analogRead(x);
  yv=analogRead(y);
 if(xv>=320 && xv<=335 && yv>=320 && yv<=345)
  {
    analogWrite(lm1, 0);
    analogWrite(lm2, 0);  //stp
    analogWrite(rm1, 0);
    analogWrite(rm2, 0);
  }
     if(yv>=336 && yv<=395)
    {
      yv=map(yv,319,275,0,255);
    analogWrite(lm1,yv);
    analogWrite(lm2,0);  //stp
    analogWrite(rm1,yv);
    analogWrite(rm2,0);
    }
      if(yv>=319 && yv<=265) 
    {
      yv=map(yv,315,256,0,255);
    analogWrite(lm1,0);
    analogWrite(lm2,yv);  //stp
    analogWrite(rm1,0);
    analogWrite(rm2,yv);
    }  
    if(xv>=319 && xv<=265)
    {
      xv=map(xv,319,265,0,255);
    analogWrite(lm1,0);
    analogWrite(lm2,xv);  //stp
    analogWrite(rm1,xv);
    analogWrite(rm2,0);
    }
      
  if(xv>=346 && xv<=400)
    {
      xv=map(xv,340,400,0,255);
    analogWrite(lm1,xv);
    analogWrite(lm2,0);  //stp
    analogWrite(rm1,0);
    analogWrite(rm2,xv);
    }
}
