int i;
void setup()
{
  Serial.begin(9600);
  pinMode(8,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
}
  void loop()
  {
    
  i=Serial.read();
  switch(i)
  {
   case'9' :
 Serial.println("9");
 digitalWrite(8,LOW); 
 digitalWrite(2,LOW); 
 digitalWrite(3,LOW);
 digitalWrite(4,LOW);
 digitalWrite(5,LOW);
 digitalWrite(6,LOW);
 digitalWrite(7,HIGH);
 break;
 case '8':
 Serial.println("8");
 digitalWrite(8,LOW);
 digitalWrite(2,LOW);
 digitalWrite(3,LOW);
 digitalWrite(4,LOW);
 digitalWrite(5,LOW);
 digitalWrite(6,LOW);
 digitalWrite(7,LOW);
 break;
 case '7':
 Serial.println("7");
 digitalWrite(8,HIGH);
 digitalWrite(2,HIGH);
 digitalWrite(3,LOW);
 digitalWrite(4,LOW);
 digitalWrite(5,LOW);
 digitalWrite(6,HIGH);
 digitalWrite(7,HIGH);
 break;
 case '6':
 Serial.println("6");
 digitalWrite(8,LOW);
 digitalWrite(2,LOW);
 digitalWrite(3,LOW);
 digitalWrite(4,HIGH);
 digitalWrite(5,LOW);
 digitalWrite(6,LOW);
 digitalWrite(7,LOW);
 break;
 case '5':
 Serial.println("5");
 digitalWrite(8,LOW);
 digitalWrite(2,LOW);
 digitalWrite(3,LOW);
 digitalWrite(4,HIGH);
 digitalWrite(5,LOW);
 digitalWrite(6,LOW);
 digitalWrite(7,HIGH);
 break;
 case '4':
 Serial.println("4");
 digitalWrite(8,LOW);
 digitalWrite(2,LOW);
 digitalWrite(3,HIGH);
 digitalWrite(4,LOW);
 digitalWrite(5,LOW);
 digitalWrite(6,HIGH);
 digitalWrite(7,HIGH);
 break;
 case '3':
 Serial.println("3");
 digitalWrite(8,LOW);
 digitalWrite(2,HIGH);
 digitalWrite(3,LOW);
 digitalWrite(4,LOW);
 digitalWrite(5,LOW);
 digitalWrite(6,LOW);
 digitalWrite(7,HIGH);
 break;
 case '2':
 Serial.println("2");
 digitalWrite(8,LOW);
 digitalWrite(2,HIGH);
 digitalWrite(3,LOW);
 digitalWrite(4,LOW);
 digitalWrite(5,HIGH);
 digitalWrite(6,LOW);
 digitalWrite(7,LOW);
 break;
 case '1':
 Serial.println("1");
 digitalWrite(8,HIGH);
 digitalWrite(2,LOW);
 digitalWrite(3,HIGH);
 digitalWrite(4,HIGH);
 digitalWrite(5,HIGH);
 digitalWrite(6,HIGH);
 digitalWrite(7,LOW);
 break;
 case'0':
 Serial.println("0");
 digitalWrite(8,HIGH);
 digitalWrite(2,LOW);
 digitalWrite(3,LOW);
 digitalWrite(4,LOW);
 digitalWrite(5,LOW);
 digitalWrite(6,LOW);
 digitalWrite(7,LOW);
 break;
  }
  }
