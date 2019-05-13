#include <Arduino.h>
// for the DC motor terminals
const int motorL1 = 49;			// to assign a pin to the INA of a motor.
const int motorL2 = 48;			// to assign a pin to the INB of the motor.
const int motorLSpeed = 11;

const int motorR1 = 46;			// to assign a pin to the INA of a motor.
const int motorR2 = 47;			// to assign a pin to the INB of the motor.
const int motorRSpeed = 10;

int direction;

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
void setup() {
	Serial.begin(9600);
	Serial3.begin(9600);
//	buttons.packet = 0;
	pinMode(motorL1, OUTPUT);           // to make the Left motor an actuator.
	pinMode(motorL2, OUTPUT);           // to make the Left motor an actuator.
	pinMode(motorR1, OUTPUT);           // to make the Right motor an actuator.
	pinMode(motorR2, OUTPUT);           // to make the Right motor an actuator.
	pinMode(motorLSpeed, OUTPUT);           // to make the Right motor an actuator.
	pinMode(motorRSpeed, OUTPUT);           // to make the Right motor an actuator.
}
void loop() {
	int pass = 1;
	if (Serial3.available()) {
	// if (Serial.available()) {
		delay(100);
		while(pass) {
			buttons = Serial3.read();
			// buttons = Serial.read();
			//Serial.println(buttons, BIN);
			//buttons.packet = Serial.read();
			//Serial3.println(buttons.packet);
			if (bitRead(buttons, 0) == 1) {
			//if (buttons.bits.bit7 == 1) {
				pass = 0;
			}
		}
	
/*
		if (buttons.bits.bitUp == 1){
			Serial3.println("Forward");
			// direction = 1;
			moveForward();				// to call the forward function below.				
		}
		if (buttons.bits.bitDown == 1){
			Serial3.println("Reverse");
			// direction = 2;
			moveBackwards();			// to call the reverse function below.				
		}
		if (buttons.bits.bitLeft == 1){
			Serial3.println("Left");
			// direction = 3;
			turnLeft();					// to call the left function below.				
		}
		if (buttons.bits.bitRight == 1){
			Serial3.println("Right");
			// direction = 4;
			turnRight();				// to call the right function below.				
		}
		if (buttons.bits.bitA == 1){
			Serial3.println("Button A");
		}
		if (buttons.bits.bitB == 1){
			Serial3.println("Button B");
		}
		if ((buttons.bits.bitUp == 0) && (buttons.bits.bitDown == 0) && (buttons.bits.bitLeft == 0) && (buttons.bits.bitRight == 0)){
			Serial3.println("Stop");
			stop();
		}
*/
		if (bitRead(buttons, 1) == 1){
			//Serial.println("Left");
			// direction = 3;
			turnLeft();					// to call the left function below.				
		}
		if (bitRead(buttons, 2) == 1){
			//Serial.println("Right");
			// direction = 4;
			turnRight();				// to call the right function below.				
		}
		if (bitRead(buttons, 3) == 1){
			//Serial.println("Forward");
			// direction = 1;
			moveForward();				// to call the forward function below.				
		}
		if (bitRead(buttons, 4) == 1){
			//Serial.println("Reverse");
			// direction = 2;
			moveBackwards();			// to call the reverse function below.				
		}
		if (bitRead(buttons, 5) == 1){
			// Serial.println("Button A");
		}
		if (bitRead(buttons, 6) == 1){
			// Serial.println("Button B");
		}
		if ((bitRead(buttons, 1) == 0) && (bitRead(buttons, 2) == 0) && (bitRead(buttons, 3) == 0) && (bitRead(buttons, 4) == 0)){
			//Serial.println("Stop");
			stop();
		}
	}
	//move();
}
/*
void move(){
	switch (direction){
		case 1: //Forward
			digitalWrite(motorL1,HIGH);
			digitalWrite(motorL2,LOW);
			digitalWrite(motorR1,HIGH);
			digitalWrite(motorR2,LOW);
			digitalWrite(motorLSpeed, HIGH);
			digitalWrite(motorRSpeed, HIGH);
			Serial.println("forward");
			break;
		case 2: //Reverse
			digitalWrite(motorL1,LOW);
			digitalWrite(motorL2,HIGH);
			digitalWrite(motorR1,LOW);
			digitalWrite(motorR2,HIGH);
			digitalWrite(motorLSpeed, HIGH);
			digitalWrite(motorRSpeed, HIGH);
			break;
		case 3: //Left
			digitalWrite(motorL1,LOW);
			digitalWrite(motorL2,HIGH);
			digitalWrite(motorR1,HIGH);
			digitalWrite(motorR2,LOW);
			break;
		case 4: //Right
			digitalWrite(motorL1,HIGH);
			digitalWrite(motorL2,LOW);
			digitalWrite(motorR1,LOW);
			digitalWrite(motorR2,HIGH);
			break;
		default:
			digitalWrite(motorL1,LOW);
			digitalWrite(motorL2,LOW);
			digitalWrite(motorR1,LOW);
			digitalWrite(motorR2,LOW);
			digitalWrite(motorLSpeed, LOW);
			digitalWrite(motorRSpeed, LOW);

			break;
		
	}
}*/
void moveForward() {
	digitalWrite(motorL1, HIGH);
	digitalWrite(motorL2, LOW);
	digitalWrite(motorR1, HIGH);
	digitalWrite(motorR2, LOW);
	digitalWrite(motorLSpeed, HIGH);
	digitalWrite(motorRSpeed, HIGH);
}
void moveBackwards() {
	digitalWrite(motorL1, LOW);
	digitalWrite(motorL2, HIGH);
	digitalWrite(motorR1, LOW);
	digitalWrite(motorR2, HIGH);
	digitalWrite(motorLSpeed, HIGH);
	digitalWrite(motorRSpeed, HIGH);
}
void turnLeft() {
	digitalWrite(motorL1, LOW);
	digitalWrite(motorL2, HIGH);
	digitalWrite(motorR1, HIGH);
	digitalWrite(motorR2, LOW);
	digitalWrite(motorLSpeed, HIGH);
	digitalWrite(motorRSpeed, HIGH);
}
void turnRight() {
	digitalWrite(motorL1, HIGH);
	digitalWrite(motorL2, LOW);
	digitalWrite(motorR1, LOW);
	digitalWrite(motorR2, HIGH);
	digitalWrite(motorLSpeed, HIGH);
	digitalWrite(motorRSpeed, HIGH);
}
void stop() {
	digitalWrite(motorL1, LOW);
	digitalWrite(motorL2, LOW);
	digitalWrite(motorR1, LOW);
	digitalWrite(motorR2, LOW);
	digitalWrite(motorLSpeed, LOW);
	digitalWrite(motorRSpeed, LOW);
	delay(500);
}