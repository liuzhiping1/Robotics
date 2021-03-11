#include <SoftwareSerial.h>
SoftwareSerial s(10, 11); //RX,TX
int lm1 = 3, lm2 = 5, rm1 = 11, rm2 = 6;
void setup() {
  pinMode(lm1, OUTPUT);
  pinMode(lm2, OUTPUT);
  pinMode(rm1, OUTPUT);
  pinMode(rm2, OUTPUT);
  s.begin(9600);

}

void loop()
{
  int z = s.read();
  if (z == 'a')
  {
    analogWrite(lm1, 0);
    analogWrite(lm1, 0);  //stp
    analogWrite(lm1, 0);
    analogWrite(lm1, 0);
  }
  /////////////////////////////////////////////////////////////////
  if (z == 'b')
  {
    analogWrite(lm1, 63.75);
    analogWrite(lm1, 0);
    analogWrite(lm1, 63.75);
    analogWrite(lm1, 0);
  }
  if (z == 'c')
  {
    analogWrite(lm1, 127.5);
    analogWrite(lm1, 0);
    analogWrite(lm1, 127.5);
    analogWrite(lm1, 0);
  }
  if (z == 'd')
  {
    analogWrite(lm1, 191.25);
    analogWrite(lm1, 0);
    analogWrite(lm1, 191.25); //fwd
    analogWrite(lm1, 0);
  }
  if (z == 'e')
  {
    analogWrite(lm1, 255);
    analogWrite(lm1, 0);
    analogWrite(lm1, 255);
    analogWrite(lm1, 0);
  }
  ///////////////////////////////////////////////////////////////
  if (z == 'f')
  {
    analogWrite(lm1, 0);
    analogWrite(lm1, 63.75);
    analogWrite(lm1, 0);
    analogWrite(lm1, 63.75);
  }
  if (z == 'g')
  {
    analogWrite(lm1, 0);
    analogWrite(lm1, 127.5);
    analogWrite(lm1, 0);
    analogWrite(lm1, 127.5);
  }
  if (z == 'h')
  {
    analogWrite(lm1, 0);
    analogWrite(lm1, 191.25);  //back
    analogWrite(lm1, 0);
    analogWrite(lm1, 191.25);
  }
  if (z == 'i')
  {
    analogWrite(lm1, 0);
    analogWrite(lm1, 255);
    analogWrite(lm1, 0);
    analogWrite(lm1, 255);
  }
  /////////////////////////////////////////////////////////////////
  if (z == 'j')
  {
    analogWrite(lm1, 0);
    analogWrite(lm1, 63.75);
    analogWrite(lm1, 63.75);
    analogWrite(lm1, 0);
  }
  if (z == 'k')
  {
    analogWrite(lm1, 0);
    analogWrite(lm1, 127.5);
    analogWrite(lm1, 127.5);
    analogWrite(lm1, 0);
  }
  if (z == 'l')
  {
    analogWrite(lm1, 0);
    analogWrite(lm1, 191.25);  //left
    analogWrite(lm1, 191.25);
    analogWrite(lm1, 0);
  }
  if (z == 'm')
  {
    analogWrite(lm1, 0);
    analogWrite(lm1, 255);
    analogWrite(lm1, 255);
    analogWrite(lm1, 0);
  }
  ///////////////////////////////////////////////////////////////
  if (z == 'n')
  {
    analogWrite(lm1, 63.75);
    analogWrite(lm1, 0);
    analogWrite(lm1, 0);
    analogWrite(lm1, 63.75);
  }
  if (z == 'o')
  {
    analogWrite(lm1, 127.5);
    analogWrite(lm1, 0);
    analogWrite(lm1, 0);
    analogWrite(lm1, 127.5);      //right
  }
  if (z == 'p')
  {
    analogWrite(lm1, 191.25);
    analogWrite(lm1, 0);
    analogWrite(lm1, 0);
    analogWrite(lm1, 191.25);
  }
  if (z == 'q')
  {
    analogWrite(lm1, 255);
    analogWrite(lm1, 0);
    analogWrite(lm1, 0);
    analogWrite(lm1, 255);
  }
//////////////////////////////////////////////////////////////
}

