/*
    PololuDriver.h - Library voor de DRV8825 Stepper Driver
    Gemaakt door Brecht Ooms
*/

#ifndef _POLOLUDRIVER_h
#define _POLOLUDRIVER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class PololuStepper
{
	//public variabelen en functies (die men kan gebruiken)
	public:
		//Constructor
		PololuStepper(int _stepPin, int _dirPin, int _enablePin);

		//Bepaal Draairichting
		void setDir(short _dir);

		//Step Handmatig
		//(stepOff moet daarna komen)
		bool stepOn();

		//Concludeer Stap handmatig
		//(Moet na StepOn komen)
		void stepOff();

		//Beweeg een aantal stappen. (aantal kan negatief zijn)
		void autoStep(long amount, int _delay);

		//Beweeg naar doelpositie met gegegeven delay (in microseconden)
		void moveTo(long targetPos, int _delay);

		//Positie
		long position = 0;

	//private variabelen en functies (die men niet kan gebruiken)
	private:
		//Draairichting
		short dir = 1;
		//controlevariabele om fouten te voorkomen
		bool stepped = false;

		//aansluitingen
		int stepPin;
		int dirPin;
		int enablePin;
};

#endif
