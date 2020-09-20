// Include The MorseBin library
#include <MorseBin.h>
// define the pin, on which the data is going to
// be received.
#define MorseBinPin 9
// define the pin, on which the pwm-signal is going to
// be send
#define PwmPin 3
void setup() {
  // Set the data-pin as an Input
  pinMode(MorseBinPin,INPUT);
  // Set the PWM -pin as an Output.
  // Check if the Pin of your Arduino or
  // Arduino-compatabile board has PWM capabilities!
  pinMode(PwmPin,OUTPUT);
}

void loop() {
  // Receive the Data and Store it as a String
  String PWMString = MBReceive(MorseBinPin);
  // Checks, if it timed out
  if(PWMString !=""){
    // Convert The String into an Number and apply it
    // to the Pin.
    byte PWM = MBStringToNum(PWMString);
    analogWrite(PwmPin,PWM);
  }
}
