/*
  * SPGSM.h - Library for flashing SPGSM code.
  * Created by SPRoboticWorks, June 12, 2014.
  * http://www.sproboticworks.com/
*/
#ifndef SPGSM_h
#define SPGSM_h

#include "Arduino.h"

class SPGSM
{
public:
	SPGSM(void);
	void begin(uint16_t);
	void call(char[], long);
	void sms(char[], int);
	void sms(char[], char[]);
};

#endif