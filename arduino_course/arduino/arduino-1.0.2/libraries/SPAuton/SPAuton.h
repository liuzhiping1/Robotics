/*
  * SPAuton.h - Library for flashing SPAuton code.
  * Created by SPRoboticWorks, June 21, 2012.
  * http://www.sproboticworks.com/
*/
#ifndef SPAuton_h
#define SPAuton_h

#include "Arduino.h"

class SPAuton
{
public:
	SPAuton(void);
	void begin(uint16_t);
	int digitalRead(int);
	int analogRead(int);
	void digitalWrite(int,int);
	void analogWrite(int,int);
	void manualControl();
	int read();
private:
	int p[21],lspeed,rspeed;
	boolean manual;
	String message;
	char temp;
	void print(int,int);
	void manualLoop();
	int readString();

};

#endif