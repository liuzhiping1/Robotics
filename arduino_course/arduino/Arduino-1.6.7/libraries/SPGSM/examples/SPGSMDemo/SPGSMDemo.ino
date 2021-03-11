/*
 * SPGSM: SPGSM - Performs GSM functions 
 * Developed by SPRoboticWorks, June 12, 2014.
 * Released into the public domain. 
 */
#include <SPGSM.h>

SPGSM spgsm;

void setup() {
  spgsm.begin(9600);
  // Calls to the number "123456789" with the ring time 5000
  spgsm.call("123456789", 5000);
  delay(2000);
  // Sends the message "This is a demo message" to the number "123456789"
  spgsm.sms("123456789", "This is a demo message");
}

void loop() {
}
