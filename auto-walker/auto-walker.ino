#define LEFT_FRONT_PIN 8
#define LEFT_BACK_PIN 9
#define RIGHT_FRONT_PIN 10
#define RIGHT_BACK_PIN 11

#define PIN_TRIG 7
#define PIN_ECHO 6

long duration, cm;


#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>
void setup() {
  // put your setup code here, to run once:
  pinMode(LEFT_FRONT_PIN, OUTPUT);
  pinMode(LEFT_BACK_PIN, OUTPUT);
  pinMode(RIGHT_FRONT_PIN, OUTPUT);
  pinMode(RIGHT_BACK_PIN, OUTPUT);

  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);

  Serial.begin(9600);      // make sure your Serial Monitor is also set at this baud rate.
  Dabble.begin(9600);      //Enter baudrate of your bluetooth.Connect bluetooth on Bluetooth port present on evive.
}

void loop() {
  Dabble.processInput();

  Serial.println(checkDist());


  if(checkDist()<50){
  	goLeft();
  }
  else{
  	goBack();
  }



}


long checkDist(){

// Сначала генерируем короткий импульс длительностью 2-5 микросекунд.

  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(5);
  digitalWrite(PIN_TRIG, HIGH);

  // Выставив высокий уровень сигнала, ждем около 10 микросекунд. В этот момент датчик будет посылать сигналы с частотой 40 КГц.
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);

  //  Время задержки акустического сигнала на эхолокаторе.
  duration = pulseIn(PIN_ECHO, HIGH);

  // Теперь осталось преобразовать время в расстояние
  cm = (duration / 2) / 29.1;

  delay(150);
  return cm;

}

void goForward(){
	digitalWrite(LEFT_FRONT_PIN, HIGH);
    digitalWrite(RIGHT_FRONT_PIN, HIGH);
    digitalWrite(LEFT_BACK_PIN, LOW);
    digitalWrite(RIGHT_BACK_PIN, LOW);

}

void goBack(){
	digitalWrite(LEFT_BACK_PIN, HIGH);
    digitalWrite(RIGHT_BACK_PIN, HIGH);
    digitalWrite(LEFT_FRONT_PIN, LOW);
    digitalWrite(RIGHT_FRONT_PIN, LOW);
}

void goLeft(){
	digitalWrite(RIGHT_FRONT_PIN, HIGH);
    digitalWrite(LEFT_BACK_PIN, HIGH);
    digitalWrite(LEFT_FRONT_PIN, LOW);
    digitalWrite(RIGHT_BACK_PIN, LOW);
}

void goRight(){
	digitalWrite(LEFT_FRONT_PIN, HIGH);
    digitalWrite(RIGHT_BACK_PIN, HIGH);
    digitalWrite(RIGHT_FRONT_PIN, LOW);
    digitalWrite(LEFT_BACK_PIN, LOW);
}

void stop(){
	digitalWrite(LEFT_FRONT_PIN, LOW);
    digitalWrite(RIGHT_FRONT_PIN, LOW);
    digitalWrite(LEFT_BACK_PIN, LOW);
    digitalWrite(RIGHT_BACK_PIN, LOW);
}
