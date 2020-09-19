// Include The MorseBin library
#include <MorseBin.h>
void setup() {
  // Open the Serial Port @ 9600 baud
Serial.begin(9600);
}

void loop() {
  // Check if theres something in the buffer
if (Serial.available()){
  // Reads the String from the Buffer and converts it
  // into an byte which hold a value from 0-255.
  // Then, the Byte gets convertet again, but this time
  // into an Ascii charakter acording to its value,
  // e.g. 10000010 gets converted to 65 and then into
  //  an "A", because the ASCII value of "A" is 65.
  char test = MBStringToNum(Serial.readString());
  Serial.println(test);
}
}
