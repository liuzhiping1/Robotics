int ledPin = 13; 
int state = 0;
int flag = 0; 

void setup()
{
pinMode(ledPin, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
digitalWrite(ledPin, LOW);
digitalWrite(5, LOW);
digitalWrite(6, LOW);
Serial.begin(9600);
}
void loop() 
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
