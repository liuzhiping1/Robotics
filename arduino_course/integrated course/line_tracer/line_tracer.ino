int pid=0,e=0,pe=0,kp=0.8/*(-)1*/,ki=0.5/*0.5to1(+0.01)*/,kd=1/*1(+1)*/,p=0,i=0,d=0; 
int lmsp=0,rmsp=0,plmsp=100,prmsp=100;
int lmt1=5,lmt2=6,rmt1=10,rmt2=11;

int lms=A0;
int ls=A1;
int cs=A2;
int rs=A3;
int rms=A4;

int s1;
int s2;
int s3;
int s4;
int s5;
void setup()
{
  pinMode(lmt1,OUTPUT);
  pinMode(lmt2,OUTPUT);
  pinMode(rmt1,OUTPUT);
  pinMode(rmt2,OUTPUT);  
}
void loop()
{
 error();
 PID();
 motor();
}
 void error()
 {
 s1=digitalRead(lms);
 s2=digitalRead(ls);
 s3=digitalRead(cs);
 s4=digitalRead(rs);
 s5=digitalRead(rms);
 if(s1==0 && s2==0 && s3==0 && s4==0 && s5==0) 
 {
 e=3;
 }
  if(s1==1 && s2==0 && s3==0 && s4==0 && s5==0) 
 {
 e=2;
 }
 if(s1==0 && s2==1 && s3==0 && s4==0 && s5==0) 
 {

   e=1;
 }
 if(s1==0 && s2==0 && s3==1 && s4==0 && s5==0) 
 {
 e=0;
 }
 if(s1==0 && s2==0 && s3==0 && s4==1 && s5==0) 
 {
 e=-1;
 }
  if(s1==0 && s2==0 && s3==0 && s4==0 && s5==1) 
 {
 e=-2;
 }
  if(s1==0 && s2==0 && s3==0 && s4==0 && s5==0) 
 {
 e=-3;
 } 
 }
 void PID()
 {
 p=e;
 i=i+e;
 d=e-pe;
 pid=(p*kp)+(i*ki)+(d*kd);
 pe=e;
 }
 void motor()
{
 lmsp=plmsp-pid;
 rmsp=prmsp-pid;
 if(lmsp > 255)
{
 lmsp=255;
}
 if(lmsp < 0)
{
 lmsp=0 ;
}
 if(rmsp>255)
{
 rmsp=255;
}
 if(rmsp=0)
{
 rmsp=0 ;

 analogWrite(lmt1,lmsp);
 analogWrite(lmt2,0);
 analogWrite(rmt1,rmsp);
 analogWrite(rmt2,0);
 plmsp=lmsp;
 prmsp=rmsp;
} 
}   
