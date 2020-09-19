#define pin 9
#include <MorseBin.h>
void setup() {
  // Set your Pin as an output
  pinMode(pin,OUTPUT);
  // Start the serial communication with 9600 baud
  Serial.begin(9600);
}

void loop() {
	// Check if something is in the buffer
      if(Serial.available()){
		  // Send the Data
        MBSendByte(Serial.readString(),pin);
        delay(1000);
        }
}
