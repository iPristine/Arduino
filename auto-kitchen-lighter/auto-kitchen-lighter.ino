//auto-kitchen-lighter.ino

int led = 4;
int sensorPin = 3;

bool sensorStatus = false;

long lightningTime = 10; // second

long restTime = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);

}

void loop() {

	delay(1000);

	sensorStatus = sensorCheck();

    Serial.println(sensorStatus);

    if(sensorStatus){
    	digitalWrite(led, HIGH);
    	restTime = lightningTime;
    }

    if(restTime>0){
    	restTime = restTime-1;
    }
    else {
    	digitalWrite(led, LOW);
    }

}

bool sensorCheck() {
	int check1 = digitalRead(sensorPin);
	delay(100);
	int check2 = digitalRead(sensorPin);
	delay(100);
	int check3 = digitalRead(sensorPin);

	return check1 * check2 * check3;


}
