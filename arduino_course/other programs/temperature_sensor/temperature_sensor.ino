float temp=0,t=0;
void setup()
{
  pinMode(A0,INPUT);
  Serial.begin(9600);
}
void loop()
{
  t=analogRead(A0);
  temp=t* 0.48828125;//5v=supply voltage//
  Serial.print("TEMPRATURE=");
  Serial.print(temp); //1000=toconvert voltage to millivolt//
  Serial.print("*c"); //1024=analog(0-1023)//
  delay(1000);   //10=10millivolt=1celcius//
}



