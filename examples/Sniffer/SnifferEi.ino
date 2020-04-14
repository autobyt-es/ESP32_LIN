  
/*  LIN Sniffer - Monitor traffic on LIN Bus
 *
 *  Written in September 2016 by Blaž Pongrac B.S., RoboSap, Institute of Technology, Ptuj (www.robosap-institut.eu) for Macchina LLC
 *
 *  To the extent possible under law, the author(s) have dedicated all copyright and related and neighboring rights to this software to the public domain worldwide. This software is distributed without any warranty.
 *
 *  You should have received a copy of the CC0 Public Domain Dedication along with this software. If not, see <http://creativecommons.org/publicdomain/zero/1.0/>. 
 *  
 *  Using LIN Stack v2.0 Library (https://github.com/macchina/LIN)
 *  
 *  Developed against Arduino IDE 1.6.9
 *
 *  Modified by @autobytes for use in ESP32
 */
 
// Including LIN Stack library
#include <lin_stack_esp32.h>
#include <HardwareSerial.h>

// Variables
const byte ident = 0; // Identification Byte
byte data_size=8; // length of byte array
byte data[8]; // byte array for received data

// Creating LIN Object
lin_stack_esp32 LIN1(2,ident); // 2 - channel (GPIO 16 & 17), ident - Identification Byte

void setup() {
  Serial.begin(9600); // Configure Serial for Serial Monitor
  LIN1.setSerial(); // Configure Serial for receiving
}

void loop() {
   // Checking LIN Bus periodicly
  byte a = LIN1.readStream(data, data_size);
  if(a == 1){ // If there was an event on LIN Bus, Traffic was detected. Print data to serial monitor
     Serial.println("Traffic detected!");
     Serial.print("Synch Byte: ");
     Serial.println(data[0], HEX);
     Serial.print("Ident Byte: ");
     Serial.println(data[1], HEX);
     Serial.print("Data Byte1: ");
     Serial.println(data[2]);
     Serial.print("Data Byte2: ");
     Serial.println(data[3]);
     Serial.print("Data Byte3: ");
     Serial.println(data[4]);
     Serial.print("Data Byte4: ");
     Serial.println(data[5]);
     Serial.print("Data Byte5: ");
     Serial.println(data[6]);
     Serial.print("Check Byte: ");
     Serial.println(data[7]);
     Serial.print("\n");
  } 
}
