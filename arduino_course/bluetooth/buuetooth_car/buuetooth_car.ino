int lmt1=5,lmt2=6,rmt1=10,rmt2=11;    //variables for motor terminals is declared
char value;
void setup()
{
  Serial.begin(9600);    //Serial communication starts
  
     //Declaring motor terminals as output
  pinMode(lmt1,OUTPUT);
  pinMode(lmt2,OUTPUT);
  pinMode(rmt1,OUTPUT);
  pinMode(rmt2,OUTPUT);
}
void loop()
{
 value=Serial.read();    //Reading serial value
 switch(value)           //Switch case starts
{
   case'W':              //First case
   forward();
   Serial.println("Robot Moving Forward");
   break;
   case'S':              //Second case
   backward();
   Serial.println("Robot Moving Backward");
   break;
   case'A':              //Third case
   right();
   Serial.println("Robot Moving Right");
   break;
   case'D':             //Fourth case
   left();
   Serial.println("Robot Moving Left");
   break;
   case'X':             //Fifth case
   Stop();
   Serial.println("Robot Stopped");
   break;
   
  }
 
}
void forward()          //Forward function
{
  digitalWrite(lmt1,HIGH);
  digitalWrite(lmt2,LOW);
  digitalWrite(rmt1,HIGH);
  digitalWrite(rmt2,LOW);
}
void backward()         //Backward function
{
  digitalWrite(lmt1,LOW);
  digitalWrite(lmt2,HIGH);
  digitalWrite(rmt1,LOW);
  digitalWrite(rmt2,HIGH);
}
void right()            //Right function
{
  digitalWrite(lmt1,HIGH);
  digitalWrite(lmt2,LOW);
  digitalWrite(rmt1,LOW);
  digitalWrite(rmt2,HIGH);
}
void left()              //Left function
{
  digitalWrite(lmt1,LOW);
  digitalWrite(lmt2,HIGH);
  digitalWrite(rmt1,HIGH);
  digitalWrite(rmt2,LOW);
}
void Stop()              //Stop function
{
  digitalWrite(lmt1,LOW);
  digitalWrite(lmt2,LOW);
  digitalWrite(rmt1,LOW);
  digitalWrite(rmt2,LOW);
}
