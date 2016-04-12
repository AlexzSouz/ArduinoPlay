#include "VSPDE.h"
#include "ArduinoDigital.cpp.h"

using namespace ArduinoConsoleStub;
using namespace ArduinoDigital;

/**
# 1 Digit 8 Segment Tube

Used Resources:
1) Arduino UNO
2) Breadboard
3) 12 colorful BREAKBOARD cables
4) 8 220? (Ohm) Resistors plug
5) 1 Digit 8 Segment Tube

*/

// Fields
int delayMs = 500;
DigitalTube _digitalTube;

bool _kbhit()
{
	return true;
}

void updateDelayMs(int& ms) // Parameter as a reference
{
	ms += 500;
}

void setOnBoardPin()
{
	digitalWrite(_digitalTube.onBoardLedPin, HIGH);
	delay(delayMs);

	digitalWrite(_digitalTube.onBoardLedPin, LOW);
	delay(delayMs);
}

void setup()
{
	Serial.begin(57600);
	pinMode(_digitalTube.onBoardLedPin, OUTPUT);

	_digitalTube.setDigitalPinsMode();
	_digitalTube.switchOffPins();
}

void loop()
{
	//setOnBoardPin();
	//updateDelayMs(delayMs);

	_digitalTube.startDigitalWriteOnPins();
	Serial.println("Looping...");
}