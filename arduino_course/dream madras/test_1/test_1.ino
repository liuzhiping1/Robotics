int LM_1 = 6;         // the motor pins are intiated as per ports in Auton shield
int LM_2 = 5;
int RM_1 = 10;
int RM_2 = 11;
int spd = 255;
#define sensor A0
#include<LiquidCrystal.h>
LiquidCrystal Lcd(13,12,8,7,4,2);
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
 Lcd.begin(16,2);
 pinMode(LM_1, OUTPUT);     // motor is initiated as output
  pinMode(LM_2, OUTPUT);
  pinMode(RM_1, OUTPUT);
  pinMode(RM_2, OUTPUT);
  fwd();
}

void loop() {
  // put your main code here, to run repeatedly:
 float volts = analogRead(sensor)*0.0048828125;  // value from sensor * (5/1024)
  int distance = 13*pow(volts, -1); // worked out from datasheet graph
  delay(1000); // slow down serial port 
  Serial.println("distance="); 
  Serial.println(distance);
  Lcd.clear();
  Lcd.print("distance=");
  Lcd.print(distance);
  
  if (distance <= 5){
      
    stp();
}
  if (distance >= 5){
    
    fwd();
}
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
