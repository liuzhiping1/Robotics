int distance,time;
void setup()
{
 Serial.begin(9600);
}
 void loop()
{
 pinMode(9,OUTPUT);
 digitalWrite(9,LOW); 
 delayMicroseconds(2);
 digitalWrite(9,HIGH);
 delayMicroseconds(5);
 digitalWrite(9,LOW);
 delayMicroseconds(2);
 
 pinMode(9,INPUT);
 time=pulseIn(9,HIGH);
 distance=(time/29)/2;
 Serial.print("Distance:");
 Serial.println(distance); 
 delay(100);
}
