int i,a,v,g;
void setup()
{
 Serial.begin(9600);
}
  void loop()
 {                                                                                                                            
  i=Serial.read();
    switch(i)
 {
  case 'a':
  Serial.println(12+12);
  delay(100);
  break;
  case 'b':
  Serial.println(87-54);
  delay(100);
  break;
  case 'c':
  Serial.println(32*54);
  delay(100);
  break; 
  case 'd':
  Serial.println(88/44);
  delay(100);
  break; 
 }
 }
 
 
