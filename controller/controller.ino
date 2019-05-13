#include <Arduino.h>

const int btnLeft = 2;
const int btnRight = 4;
const int btnUp = 7;
const int btnDown = 8;
const int btnA = 12;
const int btnB = 13;
/*
typedef struct {
	unsigned int bit0:1;
	unsigned int bitLeft:1;
	unsigned int bitRight:1;
	unsigned int bitUp:1;
	unsigned int bitDown:1;
	unsigned int bitA:1;
	unsigned int bitB:1;
	unsigned int bit7:1;
} creation;

union otherCreation {
	unsigned int packet;
	creation bits;
};

otherCreation buttons;
*/
byte buttons = 0;
int btnLeftLast = 0, btnRightLast = 0, btnUpLast = 0, btnDownLast = 0, btnALast = 0, btnBLast = 0;

void setup() {
	Serial.begin(9600); // Bluetooth baud rate
	// buttons.bits.bit7 = 1;
	bitWrite(buttons, 0, 1);
	pinMode(btnLeft,INPUT);
	pinMode(btnRight,INPUT);
	pinMode(btnUp,INPUT);
	pinMode(btnDown,INPUT);
	pinMode(btnA,INPUT);
	pinMode(btnB,INPUT);
	while (!Serial) {
		; // wait for serial port to connect. Needed for native USB
	}
	//Serial.write(27);
	//Serial.print("[2J");
	//Serial.write(27);
	//Serial.print("[H");
}
void loop() {
	if ((digitalRead(btnLeft) != btnLeftLast) || (digitalRead(btnRight) != btnRightLast) || (digitalRead(btnUp) != btnUpLast) || (digitalRead(btnDown) != btnDownLast) || (digitalRead(btnA) != btnALast) || (digitalRead(btnB) != btnBLast)){
		/*
		Serial.print(digitalRead(btnLeft));
		Serial.print(digitalRead(btnRight));
		Serial.print(digitalRead(btnUp));
		Serial.print(digitalRead(btnDown));
		Serial.print(digitalRead(btnA));
		Serial.println(digitalRead(btnB));
		*/
		/*
		btnUpLast = buttons.bits.bitUp = digitalRead(btnUp);
		btnDownLast = buttons.bits.bitDown = digitalRead(btnDown);
		btnLeftLast = buttons.bits.bitLeft = digitalRead(btnLeft);
		btnRightLast = buttons.bits.bitRight = digitalRead(btnRight);
		btnALast = buttons.bits.bitA = digitalRead(btnA);
		btnBLast = buttons.bits.bitB = digitalRead(btnB);

		Serial.print(buttons.packet);
		*/
	/*
		btnLeftLast = bitWrite(buttons, 1, digitalRead(btnLeft));
		btnRightLast = bitWrite(buttons, 2, digitalRead(btnRight));
		btnUpLast = bitWrite(buttons, 3, digitalRead(btnUp));
		btnDownLast = bitWrite(buttons, 4, digitalRead(btnDown));
		btnALast = bitWrite(buttons, 5, digitalRead(btnA));
		btnBLast = bitWrite(buttons, 6, digitalRead(btnB));
	*/	
		btnLeftLast = digitalRead(btnLeft);
		btnRightLast = digitalRead(btnRight);
		btnUpLast = digitalRead(btnUp);
		btnDownLast = digitalRead(btnDown);
		btnALast = digitalRead(btnA);
		btnBLast =  digitalRead(btnB);

		bitWrite(buttons, 1, btnLeftLast);
		bitWrite(buttons, 2, btnRightLast);
		bitWrite(buttons, 3, btnUpLast);
		bitWrite(buttons, 4, btnDownLast);
		bitWrite(buttons, 5, btnALast);
		bitWrite(buttons, 6, btnBLast);

		Serial.write(buttons);
		//Serial.println(buttons, BIN);

	}
}