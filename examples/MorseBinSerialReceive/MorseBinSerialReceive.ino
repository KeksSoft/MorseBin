#define pin 9
#include <MorseBin.h>
void setup() {
  // Set your pin to an input, but not to an "INPUT_PULLUP", it needs a pulldown-resistor!
pinMode(pin,INPUT);
//Start the Serial communication.
Serial.begin(9600);
}

void loop() {
  // you can just print the data to the Serial Monitor, but it will time out after ca. 10 seconds, thus printing an empty line.
Serial.println(MBReceive(pin));
}
