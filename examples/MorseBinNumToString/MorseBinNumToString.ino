//This example works graet with the MorseBin GPIO example!
// Include the MorseBin library
#include <MorseBin.h>
// Declare the pin, on which the data is send
#define pin 9

void setup() {
  //set the output pin as an ouput
  pinMode(pin, OUTPUT);
}

void loop() {
  // the for loop runs 255 times and MorseBin then converts
  // the variable i, which counts up from 0 to 255 to a
  // MorseBin String and sends it!
  for (byte i = 0; i <= 255; i++) {
    MBSendByte(MBNumToString(i), pin);
  }
}
