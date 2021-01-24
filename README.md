# MorseBin
This library for the Arduino IDE provides an easy-to-use communications protocol which only uses 1 digital pin of your microcontroller!
# MBSendByte(String data,int pin);
  Sends the String "data" over the pin "pin". IMPORTANT: the String data needs special Formatting! e. g. it can be "00000000", or "11111111". It consists of 8 digits, and each digit can be a 1 or a 0.
# MBReceive(int pin);
  receives a MorseBin signal on the pin "pin". It also returns a MorseBin formatted String. It has a timeout of 10 seconds, after wich it returns "errTimeout".
