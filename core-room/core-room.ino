
#define CUSTOM_SETTINGS
#define INCLUDE_TERMINAL_MODULE
#include <Dabble.h>

int motorPin = 12;
int sprayPin = 11;

String stringFromTerminal = "";

void setup() {
	pinMode(motorPin, OUTPUT);
	pinMode(sprayPin, OUTPUT);

 	Serial.begin(9600);       
  	Dabble.begin(57600);
}

void loop() {
  Dabble.processInput();

  String currentTerminalMsg = readFromTerminal();

  if(currentTerminalMsg != ""){
  	commandsParser(currentTerminalMsg);	
  }
  




  stringFromTerminal = "";
}

String readFromTerminal(){
	if(Terminal.available())
	  {
	    while (Terminal.available() != 0)
	    {
	    	stringFromTerminal += String(Terminal.read());
	    }
	    Serial.println(stringFromTerminal);
	    Terminal.print("OK boss");
	  }
	return stringFromTerminal;
}

void commandsParser(String command){
	if(command == "motorOn"){
		setMotorStatus(true);
	}
	else if(command == "motorOff"){
		setMotorStatus(false);
	}
	else if(command == "sprayOn"){
		setSprayStatus(true);
	}
	else if(command == "sprayOff"){
		setSprayStatus(false);
	}
	else if(command == "spray"){
		singleSpray();
	}
	else {
		Terminal.print("command not found");
	}
}

void setMotorStatus(bool active) {
	if(active){
		digitalWrite(motorPin, HIGH);
	} else {
		digitalWrite(motorPin, LOW);

	}
}

void setSprayStatus(bool active) {
	if(active){
		digitalWrite(sprayPin, HIGH);
	} else {
		digitalWrite(sprayPin, LOW);

	}
}

void singleSpray(){
	digitalWrite(motorPin, HIGH);
	delay(200);
	digitalWrite(motorPin, LOW);
}

