//include the MorseBin library
#include <MorseBin.h>
// define the pin, on which the data is received
#define MorseBinPin 9
// In this array are the digital I/O pins stored,
// which later can be controlled with the MorseBin protocol
// you can use it with the MorseBinSerialSend example to controll the Pins over Serial.
const int pins[8] = {3,4,5,6,7,8,10,11};
void setup() {
  // Set the pins as an output
for (int i=0;i<8;i++){
  pinMode(pins[i],OUTPUT);
  }
  //set the receive pin of the MorseBin protocol as an output
  pinMode(MorseBinPin,INPUT);
}
void loop() {
  // Receive the Data
  String input = MBReceive(MorseBinPin);
// Checks if it timed Out and stes The pins according to teh received Data.
// e.g. "11111111" will turn on all pins
// and "00000000" will turn off all lights.
  if(input != ""){
  if(input.charAt(0)=='1'){digitalWrite(pins[0],HIGH);}
  else{digitalWrite(pins[0],LOW);}
  if(input.charAt(1)=='1'){digitalWrite(pins[1],HIGH);}
  else{digitalWrite(pins[1],LOW);}
  if(input.charAt(2)=='1'){digitalWrite(pins[2],HIGH);}
  else{digitalWrite(pins[2],LOW);}
  if(input.charAt(3)=='1'){digitalWrite(pins[3],HIGH);}
  else{digitalWrite(pins[3],LOW);}
  if(input.charAt(4)=='1'){digitalWrite(pins[4],HIGH);}
  else{digitalWrite(pins[4],LOW);}
  if(input.charAt(5)=='1'){digitalWrite(pins[5],HIGH);}
  else{digitalWrite(pins[5],LOW);}
  if(input.charAt(6)=='1'){digitalWrite(pins[6],HIGH);}
  else{digitalWrite(pins[6],LOW);}
  if(input.charAt(7)=='1'){digitalWrite(pins[7],HIGH);}
  else{digitalWrite(pins[7],LOW);}
}
