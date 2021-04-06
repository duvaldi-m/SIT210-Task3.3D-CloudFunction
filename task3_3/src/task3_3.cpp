/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/duvaldi/Desktop/Blink_subscribe/task3_3/src/task3_3.ino"
/*
 * Project task3_3
 * Description: respond to particle event 
 * Author: Duvaldi Marneweck
 */
void setup();
void loop();
void ledOn(int del_time);
void myHandler(const char *event, const char *data);
#line 6 "/Users/duvaldi/Desktop/Blink_subscribe/task3_3/src/task3_3.ino"
int led = D3;
int boardLed = D7;

// setup() runs once, when the device is first turned on.
void setup() {

  pinMode(led, OUTPUT);	   // LED pin is output 
	pinMode(boardLed, OUTPUT); // Our on-board LED output

	Particle.subscribe("Photon_Buddy", myHandler);
  Serial.begin(9600);

  digitalWrite(boardLed, LOW);
  digitalWrite(led, LOW);

}

void loop() {
  //nothing needed here for this task
}
void ledOn(int del_time)
{
  for(int i = 0; i < 3; i++)
  {
    Serial.write("LED now turning on \n ");
    digitalWrite(boardLed, HIGH);
    digitalWrite(led, HIGH);
    delay(del_time);
    digitalWrite(boardLed, LOW);
    digitalWrite(led, LOW); 
    delay(del_time);
  }
}
void myHandler(const char *event, const char *data)
{

	if (strcmp(data, "pat") == 0)
	{
		//event data is pat ,turn your board LED on X6
		ledOn(500);
    ledOn(500);
	}
	else if (strcmp(data, "wave") == 0)
	{
		//event data is wave, turn board LED on 3X
    ledOn(1000);
	}
	
  else
	{
		//data is something else, don't do anything.
	}
}
