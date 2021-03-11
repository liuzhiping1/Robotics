/*
  SPAuton.cpp - Library for flashing SPAuton code.
  Created by SPRoboticWorks, June 21, 2012.
  Released into the public domain.
*/

#include "Arduino.h"
#include "SPAuton.h"


SPAuton::SPAuton(void)
{
	int i;
	for(i=0;i<21;i++)
		p[i]=9999;
	lspeed=0;
	rspeed=0;
	pinMode(5,OUTPUT);
	pinMode(6,OUTPUT);
	pinMode(10,OUTPUT);
	pinMode(11,OUTPUT);
	message= String("");
	temp='\0';
}

void SPAuton::begin(uint16_t rate)
{
	Serial.begin(rate);
}

int SPAuton::digitalRead(int dpin)
{
	int v;
	v=Arduino_h::digitalRead(dpin);
	print(dpin,v);
	return v;
}

int SPAuton::analogRead(int sensor)
{
	int v;
	v=Arduino_h::analogRead(sensor);
	print(sensor,v);
	return v;
}

void SPAuton::digitalWrite(int dpin,int state)
{
	Arduino_h::digitalWrite(dpin,state);
	print(dpin,state);
}

void SPAuton::analogWrite(int sensor,int value)
{
	Arduino_h::analogWrite(sensor,value);
	print(sensor,value);
}

void SPAuton::manualControl()
{
	if(readString())
		if(message.equals("Manual:1"))			
			manualLoop();
}

void SPAuton::manualLoop()
{
	while(true)
	{
		if(readString())
		{
			if(message.equals("Manual:0"))
				break;
			if(message.startsWith("Motor"))
			{
				Serial.println(message);
				analogWrite(5,message.charAt(6)=='1'?lspeed:0);
				analogWrite(6,message.charAt(8)=='1'?lspeed:0);
				analogWrite(10,message.charAt(10)=='1'?rspeed:0);
				analogWrite(11,message.charAt(12)=='1'?rspeed:0);
				
			}
			else if(message.startsWith("Speed"))
			{
				char ch[4];
				int t;
				String s;
				if(message.charAt(6)=='L')
				{
					s=message.substring(8);
					s.toCharArray(ch,sizeof(ch));
					t=atoi(ch);
					if(t>=0 && t<=255)
					lspeed=t;
				}
				else
				{
					s=message.substring(8);
					s.toCharArray(ch,sizeof(ch));
					t=atoi(ch);
					if(t>=0 && t<=255)
					rspeed=t;
				}
				Serial.println(message);
			}
		}
	}
}

int SPAuton::read()
{
	int c,ch;
	if(temp!='\0')
	{
		ch=temp;
		temp='\0';
		return ch;
	}
	c=readString();	
	if(c==1)
	{
		ch=temp;
		temp='\0';
		return ch;

	}
	else if(c>1)
	{
		if(message.equals("Manual:1"))			
			manualLoop();
		return -1;
	}
	else
		return -1;
}

void SPAuton::print(int pin,int val)
{
	if(p[pin]==val)
	{
		Serial.print("same value:");
		Serial.print(pin);
		Serial.print(":");
		Serial.println(val);
		return;
	}
	if(pin>13)
	{
		Serial.print("sensor:");
		Serial.print(pin-14);
	}
	else
	{
		Serial.print("pin:");
		Serial.print(pin);
	}
	Serial.print(":");
	Serial.println(val);
	p[pin]=val;
}

int SPAuton::readString()
{
char ch;
int i;
char string[100];
if (Serial.available() > 0) 
	{
    		i=0;
      		if((ch=Serial.read())=='<')
       		{
       			do{
        		while(!Serial.available());
        		if((ch=Serial.read())!='>')
          			string[i++]=ch;
        		else
          			break;
        		}while(true);
			string[i]='\0';
			if(i==1)
				temp=string[0];
			else
				message=String(string);
			return i;
       		}
      	
	}
	return 0;
}