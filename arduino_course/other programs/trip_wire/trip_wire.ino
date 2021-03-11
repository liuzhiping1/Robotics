const int analogPin = A0; // pin that the sensor is attached to
const int SoundPin = 11; // pin that the speaker is attached to
const int Treshold = 150; // the minimum amount of light that the sensor can receive before being tripped
// change the threshold value to a value just below the one that is received when your laser is on

void setup()
{
  // initialize the soundpin as an output
 pinMode(11,OUTPUT);
 // initialize serial communication
 Serial.begin(9600);
}
 void loop()
{
  // read the value of the serial panel
 int analogValue = analogRead(A0);

// if the analog value is high enough, keep the speaker off
 if (analogValue < 150)
{
 digitalWrite(11,HIGH); //OFF
 delay(500);
}
 else
{
 digitalWrite(11,LOW); // if the value gets too low, the speaker will turn on
 delay(500); 
}
// print the analog value
 Serial.println(analogValue);
 delay(25); // delay in between reads for stability
}
