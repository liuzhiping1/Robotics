int i;
void setup()
{
 Serial.begin(9600);
 Serial.println ("press 1 to know your balance");
 Serial.println("press 2 to know youroffer");
 Serial.println("press 3 to know yourmenu");
 Serial.println("press 4 to exit");
}
void loop()
{
  i=Serial.read();
  switch(i)
{
 case '1':
 Serial.println ("your balance is 25.87");
 break;
  case '2':
  Serial.println("10% off");
 break;
  case '3':
  Serial.println("press 1 to know your balance");
  Serial.println("press 2 to know your offer");
  Serial.println("press 3 to know your menu");
  Serial.println("press 4 to exit");
 break;
  case '4':
  Serial.println("thank you");
  break;
}
}
