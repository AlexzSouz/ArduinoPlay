#include "VSPDE.h"

using namespace ArduinoConsoleStub;

namespace ArduinoDigital
{
	class DigitalTube
	{
		// PINs
		public: short onBoardLedPin;
				short digitalTubeBit[10][8] = {
					{ 1, 1, 1, 1, 1, 1, 0, 0 }, // 0
					{ 1, 1, 1, 1, 0, 1, 1, 1 }, // 9
					{ 1, 1, 1, 1, 1, 1, 1, 0 }, // 8
					{ 1, 1, 1, 0, 0, 0, 0, 1 }, // 7
					{ 1, 0, 1, 1, 1, 1, 1, 0 }, // 6
					{ 1, 0, 1, 1, 0, 1, 1, 1 }, // 5
					{ 0, 1, 1, 0, 0, 1, 1, 0 }, // 4
					{ 1, 1, 1, 1, 0, 0, 1, 1 }, // 3
					{ 1, 1, 0, 1, 1, 0, 1, 0 }, // 2
					{ 0, 1, 1, 0, 0, 0, 0, 1 } // 1
				};

		public: DigitalTube() {
			onBoardLedPin = 13;
		}

		public:void setDigitalPinsMode()
		{
			// 12, 11, 10, 9, 7, 6, 5, 4
			pinMode(12, OUTPUT);
			pinMode(11, OUTPUT);
			pinMode(10, OUTPUT);
			pinMode(9, OUTPUT);
			pinMode(7, OUTPUT);
			pinMode(6, OUTPUT);
			pinMode(5, OUTPUT);
			pinMode(4, OUTPUT);
		}

		public:void switchOffPins()
		{
			// 12, 11, 10, 9, 7, 6, 5, 4
			digitalWrite(12, LOW);
			digitalWrite(11, LOW);
			digitalWrite(10, LOW);
			digitalWrite(9, LOW);
			digitalWrite(7, LOW);
			digitalWrite(6, LOW);
			digitalWrite(5, LOW);
			digitalWrite(4, LOW);
		}

		public:void startDigitalWriteOnPins()
		{
			/* PINs Layout (Board Pin | 8 Segment Pin)
			04 -> 10
			05 -> 09
			06 -> 07
			07 -> 06
			12 -> 05 // DOT
			11 -> 04
			10 -> 02
			09 -> 01
			*/

			for (int i = 0; i < 10; i++)
			{
				digitalWrite(6, digitalTubeBit[i][0]); // A
				digitalWrite(7, digitalTubeBit[i][1]); // B
				digitalWrite(11, digitalTubeBit[i][2]); // C
				digitalWrite(10, digitalTubeBit[i][3]); // D

				digitalWrite(9, digitalTubeBit[i][4]); // E
				digitalWrite(5, digitalTubeBit[i][5]); // F
				digitalWrite(4, digitalTubeBit[i][6]); // G

				digitalWrite(12, digitalTubeBit[i][7]); // .
				
				//Serial.println("Change");
				printf("%s", "Pin: " + i);

				delay(1000);
			}
		}
	};
}+