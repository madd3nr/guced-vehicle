const int btnLeft = 3;
const int btnRight = 4;
const int btnUp = 5;
const int btnDown = 6;
const int btnA = 7;
const int btnB = 8;

int btnLeftLast = 0;
int btnRightLast = 0;
int btnUpLast = 0;
int btnDownLast = 0;
int btnALast = 0;
int btnBLast = 0;
int var = 0;


void setup() {
	Serial1.begin(9600); // Bluetooth baud rate
	// Serial.begin(9600); // Default baud rate
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
		var++;
		Serial1.println(var);
		/* Old code to print digital reads
			Serial1.print(digitalRead(btnLeft));
			Serial1.print(digitalRead(btnRight));
			Serial1.print(digitalRead(btnUp));
			Serial1.print(digitalRead(btnDown));
			Serial1.print(digitalRead(btnA));
			Serial1.println(digitalRead(btnB));
			*/
		Serial1.println(digitalRead(btnLeft) + digitalRead(btnRight) + digitalRead(btnUp) + digitalRead(btnDown) + digitalRead(btnA) + digitalRead(btnB));

		btnLeftLast = digitalRead(btnLeft);
		btnRightLast = digitalRead(btnRight);
		btnUpLast = digitalRead(btnUp);
		btnDownLast = digitalRead(btnDown);
		btnALast = digitalRead(btnA);
		btnBLast = digitalRead(btnB);
	}
	delay(10);
}