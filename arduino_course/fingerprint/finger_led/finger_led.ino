
#include "FPS_GT511C3.h"
#include "SoftwareSerial.h"
FPS_GT511C3 fps(4, 5);

void setup()
{
  Serial.begin(9600);
  delay(100);
  fps.Open();
  fps.SetLED(true);
  pinMode(13, OUTPUT);
}
void loop()
{
  if (fps.IsPressFinger())
  {
    fps.CaptureFinger(false);
    int id = fps.Identify1_N();
    if (id < 200)
    {
      if (id == 0)
      {
      Serial.print("Verified ID:");
      Serial.println(id);
      Serial.println("sarvesh");
     digitalWrite(13,HIGH);
      }
      if (id == 1)
      {
       Serial.print("Verified ID:");
       Serial.println(id);
       Serial.println("vidhya sagar");
      digitalWrite(13,HIGH);delay(1000);
      digitalWrite(13,LOW);delay(1000);
      }
    }
    else
    {
      Serial.println("Finger not found");
    }
  }
  else
  {
    Serial.println("Please press finger");
  }
  delay(1000);
}

