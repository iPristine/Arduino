#include <Servo.h> 

int servoPin = 4; // открытие воды

int sensor = A1;
int power_sensor = 3;

Servo Servo1;


void setup() {
  // put your setup code here, to run once:
	Serial.begin(9600);
	analogWrite(power_sensor, 0);
  	Servo1.attach(servoPin);

  	Servo1.write(180);

}

void loop() {

	delay(1000);

	if(checkGidration()>400){
		Servo1.write(0);

		while(checkGidration()>300){
		    delay(500);
		}
		Servo1.write(180);
	}


}

int checkGidration() {
	analogWrite(power_sensor, 255);
	delay(1000);
	int gidration = analogRead(sensor);

	Serial.print("Gidration : ");
	Serial.println(gidration);
	analogWrite(power_sensor, 0);

	return gidration;
}



