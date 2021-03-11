/*
  SPGSM.cpp - Library for flashing SPGSM code.
  Created by SPRoboticWorks, June 12, 2014.
  Released into the public domain.
*/

#include "Arduino.h"
#include "SPGSM.h"


SPGSM::SPGSM(void)
{

}

void SPGSM::begin(uint16_t rate)
{
	Serial.begin(rate);
}

/**
 * Calls the given phone number for the given ring time.
 */
void SPGSM::call(char phoneNumber[], long ringTime) {
	Serial.println("AT"); 
	Serial.print("ATD"); //Dial the phone number using ATD command
	Serial.print(phoneNumber);
	Serial.println(";"); 
	delay(ringTime);
	Serial.println("ATH"); 
}

/**
 * Sends sms to the given phone number
 */
void SPGSM::sms(char phoneNumber[], int message) {
	String messageString;  //declaring string
	messageString=String(message); //converting integer into a string
	char finalMessage[messageString.length()+1];   //declaring character array
	messageString.toCharArray(finalMessage,messageString.length()+1);
	sms(phoneNumber, finalMessage);
}

/**
 * Sends sms to the given phone number
 */
void SPGSM::sms(char phoneNumber[], char message[]) {
	Serial.println("AT+CMGF=1"); // Sets to Text Mode
	delay(100);
	Serial.print("AT+CMGS=\""); // Set the Mobile number to which the message to be sent
	Serial.print(phoneNumber); 
	Serial.println("\"");
	while (Serial.read()!='>');
	{
		Serial.print(message);  //SMS body
		delay(500);
		Serial.write(0x1A);  // sends ctrl+z end of message
		Serial.write(0x0D);  // Carriage Return in Hex
		Serial.write(0x0A);  // Line feed in Hex
		//The 0D0A pair of characters is the signal for the end of a line and beginning of another.
		delay(1000);
	}
}