/*
* SPIRremote.h - Library for reading IR code.
* Created by SPRoboticWorks, March 1, 2013.
* http://www.sproboticworks.com/
*/

#ifndef SPIRremote_h
#define SPIRremote_h

#include "Arduino.h"
#include "IRremote.h"

class SPIRrecv
{
public:
	SPIRrecv(int);
	void enableIR();
	int getIRValue();
private:

	IRrecv *irrecv;
	decode_results *results;

};

#endif