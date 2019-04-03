//#include <Servo.h>
//const int pin_Servo = 6;              // to assign a pin to a Servo.

// for the DC motor terminals
const int motorL1 = 2;                    // to assign a pin to the INA of a motor.
const int motorL2 = 3;                    // to assign a pin to the INB of the motor.

const int motorR1 = 4;                    // to assign a pin to the INA of a motor.
const int motorR2 = 5;                    // to assign a pin to the INB of the motor.

//Servo servo;
/*
int forward = 0;
int reverse = 0;
int left = 0;
int right = 0;
int btnA = 0;
int btnB = 0;
*/

int direction;

void setup() {
	Serial.begin(9600);
	Serial1.begin(9600);
	  
	pinMode (motorL1, OUTPUT);           // to make the Left motor an actuator.
	pinMode (motorL2, OUTPUT);           // to make the Left motor an actuator.
	pinMode (motorR1, OUTPUT);           // to make the Right motor an actuator.
	pinMode (motorR2, OUTPUT);           // to make the Right motor an actuator.

	//servo.attach(pin_Servo);
}

void loop() {
	int dataReceive[6];
	if (Serial1.available()) {
		for (int i = 0; i < 6; i++){
			dataReceive[i] = Serial1.read();
		}
		if (dataReceive[0] == 1){
			Serial.println("Forward");
			direction = 1;
			moveForward();				// to call the forward function below.				
		}
		if (dataReceive[1] == 1){
			Serial.println("Reverse");
			direction = 2;
			moveBackwards();			// to call the reverse function below.				
		}
		if (dataReceive[2] == 1){
			Serial.println("Left");
			direction = 3;
			turnLeft();					// to call the left function below.				
		}
		if (dataReceive[3] == 1){
			Serial.println("Right");
			direction = 4;
			turnRight();				// to call the right function below.				
		}
		if (dataReceive[4] == 1){
			Serial.println("Button A");
		}
		if (dataReceive[5] == 1){
			Serial.println("Button B");
		}
		if ((dataReceive[0] == 0) && (dataReceive[1] == 0)){
			stop();
		}
	//move();
	}
}
void move(){
	switch (direction){
		case 1: //Forward
			digitalWrite(motorL1,HIGH);
			digitalWrite(motorL2,LOW);
			digitalWrite(motorR1,HIGH);
			digitalWrite(motorR2,LOW);
			break;
		case 2: //Reverse
			digitalWrite(motorL1,LOW);
			digitalWrite(motorL2,HIGH);
			digitalWrite(motorR1,LOW);
			digitalWrite(motorR2,HIGH);
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
			break;
		
	}
}

void moveForward(){
	digitalWrite(motorL1,HIGH);
	digitalWrite(motorL2,LOW);
	digitalWrite(motorR1,HIGH);
	digitalWrite(motorR2,LOW);
}
void moveBackwards(){
	digitalWrite(motorL1,LOW);
	digitalWrite(motorL2,HIGH);
	digitalWrite(motorR1,LOW);
	digitalWrite(motorR2,HIGH);
}
void turnLeft(){
	digitalWrite(motorL1,LOW);
	digitalWrite(motorL2,HIGH);
	digitalWrite(motorR1,HIGH);
	digitalWrite(motorR2,LOW);
}
void turnRight(){
	digitalWrite(motorL1,HIGH);
	digitalWrite(motorL2,LOW);
	digitalWrite(motorR1,LOW);
	digitalWrite(motorR2,HIGH);
}
void stop(){
	digitalWrite(motorL1,LOW);
	digitalWrite(motorL2,LOW);
	digitalWrite(motorR1,LOW);
	digitalWrite(motorR2,LOW);
	delay(500);
}
