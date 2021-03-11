/*
* SPIRremote.h - Library for reading IR code.
* Created by SPRoboticWorks, March 1, 2013.
* http://www.sproboticworks.com/
*/

#include "Arduino.h"
#include "SPIRremote.h"
#include <IRremote.h>

SPIRrecv::SPIRrecv(int pin) {
	irrecv = new IRrecv(pin);
	results = new decode_results();
}


void SPIRrecv::enableIR() {
	irrecv->enableIRIn();
}

int SPIRrecv::getIRValue() {
	if (irrecv->decode(&(*results))) {
		irrecv->resume();
		//Serial.println(results->value, HEX);
		if(results->value==33480735)
			return 0;
		else if(results->value==33444015)
			return 1;
		else if(results->value==33478695)
			return 2;
		else if(results->value==33486855)
			return 3;
		else if(results->value==33435855)
			return 4;
		else if(results->value==33468495)
			return 5;
		else if(results->value==33452175)
			return 6;
		else if(results->value==33423615)
			return 7;
		else if(results->value==33484815)
			return 8;
		else if(results->value==33462375)
			return 9;
		else if(results->value==33441975)
			return 10;
		else if(results->value==33446055)
			return 11;
		else if(results->value==33454215)
			return 12;
		else if(results->value==33456255)
			return 13;
		else if(results->value==33439935)
			return 14;
		else if(results->value==33472575)
			return 15;
		else if(results->value==33431775)
			return 16;
		else if(results->value==33464415)
			return 17;
		else if(results->value==33448095)
			return 18;
		else if(results->value==33427695)
			return 19;
		else if(results->value==33460335)
			return 20;
		else if(results->value==4294967295)
			return 21;
		else if(results->value==1253111735)
			return 22;
	}
	return -1;
}
