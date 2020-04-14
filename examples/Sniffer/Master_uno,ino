/*  LIN Slave - Code for Master
 *
 *  Written in July 2016 by Blaž Pongrac B.S., RoboSap, Institute of Technology, Ptuj (www.robosap-institut.eu) for Macchina LLC
 *
 *  To the extent possible under law, the author(s) have dedicated all copyright and related and neighboring rights to this software to the public domain worldwide. This software is distributed without any warranty.
 *
 *  You should have received a copy of the CC0 Public Domain Dedication along with this software. If not, see <http://creativecommons.org/publicdomain/zero/1.0/>. 
 *  
 *  Using LIN Stack v2.0 Library (https://github.com/macchina/LIN)
 *  
 *  Developed against Arduino IDE 1.6.9
 *
 *  *****  MODIFIED BY @autobytes FOR USE IN ARDUINO UNO  *****
 */

// Include LIN Stack library
#include <lin_stack_uno.h>

// LIN Object
lin_stack_uno LIN2(2);

void setup() {
}

void loop() {
  // Create Data Package
  byte packageON[] = {128, 128}; // LEDs ON
  LIN2.write(0x11, packageON, 2);
  delay(2000);
  byte packageOFF[] = {10, 10}; // LEDs OFF
  LIN2.write(0x11, packageOFF, 2);
  delay(2000);
}
