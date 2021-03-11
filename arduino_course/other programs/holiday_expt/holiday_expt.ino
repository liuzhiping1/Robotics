 int ls=A0;
 int cs=A1;
 int rs=A2;
 int lsv;
 int csv;
 int rsv;
 float temp=0,t=0;
 int a;
 float val = 0;
 float RH = 0;
 int ps=A0;
void setup()
 {
 pinMode(A0,INPUT);
 Serial.begin(9600);
 pinMode(ls,INPUT);
 pinMode(cs,INPUT); 
 pinMode(rs,INPUT);
 }
 void loop()
 {
 lsv=digitalRead(ls);
 csv=digitalRead(cs);
 rsv=digitalRead(rs);
 if(lsv==HIGH&&csv==LOW&&rsv==LOW)
 {
  t=analogRead(A0);
  temp=t* 0.48828125;//5v=supply voltage//
  Serial.print("TEMPRATURE=");
  Serial.print(temp); //1000=toconvert voltage to millivolt//
  Serial.print("*c"); //1024=analog(0-1023)//
  delay(2000);   //10=10millivolt=1celcius//
 }
 else if(lsv==LOW&&csv==HIGH&&rsv==LOW)
 {
  val = analogRead(A4);
  delay(500);
  Serial.println(val);   //Serial.println(RH);
  RH = ((((val/1023)*5)-0.8)/3.1)*100;//RH = ((0,0004*20 + 0,149)*val)-(0,0617*20 + 24,436);
  Serial.print("humidity="); 
  Serial.println(RH);
  delay(500); 
 }
 else if(lsv==LOW&&csv==LOW&&rsv==HIGH)
 {
   // Read the input on analog pin 0:
  ps = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = ps * (5.0 / 1023.0);
  Serial.print("preassure=");
  // Print out the value you read:
  Serial.println(voltage);
  // Wait 100 milliseconds
  delay(1000); 
 }
 } 
 
