int i;
void setup()
{
Serial.begin(9600);
pinMode(13,HIGH);
}
void loop()
{
  i=Serial.read();
  if (i=='H')
  {
   digitalWrite(13,HIGH );
  Serial.println("HIGH");  
}
 if(i=='L')
{
 digitalWrite(13,LOW );
  Serial.println("LOW"); 
}
}
