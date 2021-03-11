int i;
void setup()
{
 pinMode(3,OUTPUT);
}
void loop()
{ 
 for(i=0;i<=255;i=i+1)
{
 analogWrite(3,i);
delay(10);
}
for(i=255;i>=0;i=i-1)
{
 analogWrite(3,i);
delay(10); 
}
}
