int ledPin = 13; 
int state = 0;
int flag = 0; 
int v,brit=A3;
int temp_cont=A0;
float TEMP=0;
float spd=225;
int LMT1=5;
int LMT2=6;
void setup()
{
pinMode(ledPin, OUTPUT);
digitalWrite(ledPin, LOW);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
digitalWrite(ledPin, LOW);
digitalWrite(5, LOW);
digitalWrite(6, LOW);
Serial.begin(9600);
 pinMode(temp_cont,INPUT);
 pinMode(5,OUTPUT);
 pinMode(6,OUTPUT);
 analogWrite(6,0);
 pinMode(brit,INPUT);   
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  digitalWrite(4,LOW);
}
void loop() 
{
  {
    
  v=analogRead(brit);
  Serial.println(v);
  int x=map(v,0,1023,0,255);
  if(x>20)
  {
    analogWrite(3,55);
  }
  
  if(x>120)
  {
    digitalWrite(3,LOW);
  }
  
  if(x<20)
  {
    analogWrite(3,255);
  }
  }
  {
    TEMP = analogRead(temp_cont);
  spd = map(TEMP, 60, 72, 0, 255);
  analogWrite(5,spd);
  }
  {
    if(Serial.available() > 0)
{
state = Serial.read();
flag=0;
}
if (state == 'a') 
{
digitalWrite(ledPin,HIGH);
if(flag == 0)
{
Serial.println("LED: on");
flag = 1;
}
}
else if (state == 'b')
{
digitalWrite(ledPin,LOW);
if(flag == 0)
{
Serial.println("LED: off");
flag = 1;
}
}
else if (state == 'c')
{
digitalWrite(5,HIGH);
digitalWrite(6,LOW);
if(flag == 0)
{
Serial.println("FAN: on");
flag = 1;
}
}
else if (state == 'd')
{
digitalWrite(5,LOW);
digitalWrite(6,LOW);
if(flag == 0)
{
Serial.println("FAN: off");
flag = 1;
}
}
  }
  }
