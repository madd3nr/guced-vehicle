#include <Arduino.h>
#include <HardwareSerial.h>

const int btnLeft = 8;
const int btnRight = 7;
const int btnUp = 6;
const int btnDown = 5;
const int btnA = 4;
const int btnB = 3;

int btnLeftLast = 0, btnRightLast = 0, btnUpLast = 0, btnDownLast = 0, btnALast = 0, btnBLast = 0;

void setup() {
	Serial1.begin(9600); // Bluetooth baud rate
	pinMode(btnLeft,INPUT);
	pinMode(btnRight,INPUT);
	pinMode(btnUp,INPUT);
	pinMode(btnDown,INPUT);
	pinMode(btnA,INPUT);
	pinMode(btnB,INPUT);
	while (!Serial1) {
		; // wait for serial port to connect. Needed for native USB
	}
	Serial1.write(27);
	Serial1.print("[2J");
	Serial1.write(27);
	Serial1.print("[H");
}
void loop() {
	if ((digitalRead(btnLeft) != btnLeftLast) || (digitalRead(btnRight) != btnRightLast) || (digitalRead(btnUp) != btnUpLast) || (digitalRead(btnDown) != btnDownLast) || (digitalRead(btnA) != btnALast) || (digitalRead(btnB) != btnBLast)){
		Serial1.print(digitalRead(btnLeft));
		Serial1.print(digitalRead(btnRight));
		Serial1.print(digitalRead(btnUp));
		Serial1.print(digitalRead(btnDown));
		Serial1.print(digitalRead(btnA));
		Serial1.println(digitalRead(btnB));
			
		btnLeftLast = digitalRead(btnLeft);
		btnRightLast = digitalRead(btnRight);
		btnUpLast = digitalRead(btnUp);
		btnDownLast = digitalRead(btnDown);
		btnALast = digitalRead(btnA);
		btnBLast = digitalRead(btnB);
	}
}