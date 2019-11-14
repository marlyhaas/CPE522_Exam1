/* A Simple GPIO application
* Written by Derek Molloy for the book "Exploring BeagleBone: Tools and
* Techniques for Building with Embedded Linux" by John Wiley & Sons, 2018
* ISBN 9781119533160. Please see the file README.md in the repository root
* directory for copyright and GNU GPLv3 license information.            */

#include<iostream>
#include<unistd.h> //for usleep
#include"GPIO.h"
#include"derek_LED.h"
using namespace exploringBB;
using namespace std;

#define LED_PATH "/sys/class/leds/beaglebone:green:usr"

int main(){
   GPIO outLED(49), buttonA(26), buttonB(46);

   outLED.setDirection(OUTPUT);
   buttonA.setDirection(INPUT);
   buttonB.setDirection(INPUT);

   if (buttonA.getValue() == 0){
	outLED.setValue(HIGH);
   }

   else if (buttonA.getValue() == 1){
	outLED.setValue(LOW);
   }

   if (buttonB.getValue() == 0){
	LED(3).turnOn();
   }

   else if (buttonB.getValue() == 1){
	LED(3).turnOff();
   }

   return 0;
}
