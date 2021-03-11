String incomingdata ="";
String temp ="";
char var;

void setup()
{
 Serial.begin(9600);
 Serial.println("ready");
}

void loop()
{
 while(Serial.available())
{
 var=Serial.read();
 temp=String(var);
 incomingdata += temp;
} 
 Serial.println(incomingdata);
 delay(1000);
 
 if(incomingdata!="")
 {
   Serial.println(incomingdata);
   delay(1000);
  incomingdata="";
 }
} 
