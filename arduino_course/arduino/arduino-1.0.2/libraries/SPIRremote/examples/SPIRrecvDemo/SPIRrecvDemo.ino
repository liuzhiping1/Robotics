/*
 * SPIRremote: SPIRrecvDemo - demonstrates receiving IR codes with SPIRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Developed by SPRoboticWorks, March 1, 2013.
 * Released into the public domain.

 */

#include <SPIRremote.h>

const int RECV_PIN = 9;

SPIRrecv sprecv(RECV_PIN);

void setup()
{
  Serial.begin(9600);
  sprecv.enableIR();
}

void loop()
{
  int irValue = sprecv.getIRValue();
  if(irValue!=-1) {
    Serial.print("IR Code received:");
    Serial.println(irValue);
  }
}
