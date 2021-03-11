#include <SoftwareSerial.h>

SoftwareSerial mySerial(9, 10);//RX,TX
int x=A1,y=A2;
int xv,yv;
void setup()
{
  mySerial.begin(9600);   // Setting the baud rate of GSM Module  
  Serial.begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)
  delay(100);
 pinMode(x,INPUT);
 pinMode(y,INPUT);
}
 void loop()
{
  xv=analogRead(x);
  if(xv<=280 && xv<=375 )
   SendMessage();
  if (mySerial.available()>0)
   Serial.write(mySerial.read()); 
 }
void SendMessage()
{
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+919600001628\"\r"); // Replace x with mobile number
  delay(1000);
  mySerial.println("car toppled");// The SMS text you want to send
  delay(100);
   mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}
