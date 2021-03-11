void setup() {
  pinMode(A0,INPUT);
pinMode(13,OUTPUT);
Serial.begin(9600);
}

void loop() {
int s1=analogRead/*digitalRead*/(A0);
/*if(s1==HIGH)
{
  digitalWrite(13,LOW);
}
else 
digitalWrite(13,HIGH);
}*/
Serial.println(s1);
delay(500);
}
