#include <Arduino.h>
// for the DC motor terminals
const int motorL1 = 49;                    // to assign a pin to the INA of a motor.
const int motorL2 = 48;                    // to assign a pin to the INB of the motor.
const int motorLSpeed = 11;

const int motorR1 = 47;                    // to assign a pin to the INA of a motor.
const int motorR2 = 46;                    // to assign a pin to the INB of the motor.
const int motorRSpeed = 10;

int direction;

void setup() {
	Serial.begin(9600);
	  
	pinMode(motorL1, OUTPUT);           // to make the Left motor an actuator.
	pinMode(motorL2, OUTPUT);           // to make the Left motor an actuator.
	pinMode(motorR1, OUTPUT);           // to make the Right motor an actuator.
	pinMode(motorR2, OUTPUT);           // to make the Right motor an actuator.
	pinMode(motorLSpeed, OUTPUT);           // to make the Right motor an actuator.
	pinMode(motorRSpeed, OUTPUT);           // to make the Right motor an actuator.
}
void loop() {
	int dataReceive[6];
	if (Serial.available()) {
		delay(10);
		for (int i = 0; i < 6; i++){
			dataReceive[i] = Serial.read() - '0';
			Serial.print(dataReceive[i]);
		}
		Serial.print(" - ");

		if (dataReceive[0] == 1){
			Serial.println("Forward");
			// direction = 1;
			moveForward();				// to call the forward function below.				
		}
		if (dataReceive[1] == 1){
			Serial.println("Reverse");
			// direction = 2;
			moveBackwards();			// to call the reverse function below.				
		}
		if (dataReceive[2] == 1){
			Serial.println("Left");
			// direction = 3;
			turnLeft();					// to call the left function below.				
		}
		if (dataReceive[3] == 1){
			Serial.println("Right");
			// direction = 4;
			turnRight();				// to call the right function below.				
		}
		if (dataReceive[4] == 1){
			Serial.println("Button A");
		}
		if (dataReceive[5] == 1){
			Serial.println("Button B");
		}
		if ((dataReceive[0] == 0) && (dataReceive[1] == 0) && (dataReceive[2] == 0) && (dataReceive[3] == 0)){
			Serial.println("Stop");
			stop();
		}
	//move();
	}
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
