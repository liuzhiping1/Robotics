int x,y,z;
void setup()
{
 Serial.begin(9600);
 pinMode(A0,INPUT);
 pinMode(A2,INPUT);
 pinMode(A3,INPUT);
}
void loop()
{
 x=analogRead(A0);
 y=analogRead(A1);
 z=analogRead(A2);
 Serial.print("x=");
 Serial.print(x);
 Serial.print("y=");
 Serial.print(y);
 Serial.print("z=");
 Serial.println(z);
 delay(600);
}
