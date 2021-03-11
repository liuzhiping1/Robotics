int LM_1 = 6;         // the motor pins are intiated as per ports in Auton shield
int LM_2 = 5;
int RM_1 = 10;
int RM_2 = 11;
int spd = 255;
#include <SoftwareSerial.h>

SoftwareSerial mySerial(9, 10);//RX,TX
#define sensor A0
#include<LiquidCrystal.h>
LiquidCrystal Lcd(13,12,8,7,4,2);
int x=A1,y=A2;
int xv,yv;
void setup() {
  // put your setup code here, to run once:
  mySerial.begin(9600);
Serial.begin(9600);
delay(100);
 Lcd.begin(16,2);
 pinMode(LM_1, OUTPUT);     // motor is initiated as output
  pinMode(LM_2, OUTPUT);
  pinMode(RM_1, OUTPUT);
  pinMode(RM_2, OUTPUT);
  pinMode(x,INPUT);
 pinMode(y,INPUT);
  fwd();
}

void loop() {
  // put your main code here, to run repeatedly:
  xv=analogRead(x);
 float volts = analogRead(sensor)*0.0048828125;  // value from sensor * (5/1024)
  int distance = 13*pow(volts, -1); // worked out from datasheet graph
  delay(1000); // slow down serial port 
 // Serial.println("distance="); 
  //Serial.println(distance);
  Lcd.clear();
  Lcd.print("distance=");
  Lcd.print(distance);
  
  if (distance <= 5){
      
    stp();
}
  if (distance >= 5){
    
    fwd();
}
  if(xv<=280 && xv<=375 )
   SendMessage();
  if (mySerial.available()>0)
   Serial.write(mySerial.read());
}
void fwd()
{
  analogWrite(LM_1, spd);
  analogWrite(LM_2, 0);
  analogWrite(RM_1, spd);
  analogWrite(RM_2, 0);
}
void stp()
{
  analogWrite(LM_1, 0);
  analogWrite(LM_2, 0);
  analogWrite(RM_1, 0);
  analogWrite(RM_2, 0);
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
