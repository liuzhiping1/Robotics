void setup() 
{
  Serial.begin(9600);
  pinMode(A0,INPUT);
}

void loop() {
  int a;
  a=analogRead(A0);
  Serial.print("value=");
  Serial.println(a);
 delay(500);
}
