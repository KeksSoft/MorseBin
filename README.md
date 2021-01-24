# MorseBin
This library for the Arduino IDE provides an easy-to-use communications protocol which only uses 1 digital pin of your microcontroller!
# MBSendByte(String data,int pin);
  Sends the String "data" over the pin "pin". IMPORTANT: the String data needs special Formatting! e. g. it can be "00000000", or "11111111". It consists of 8 digits,    and each digit can be a 1 or a 0.
# MBReceive(int pin);
  Receives a MorseBin signal on the pin "pin". It also returns a MorseBin formatted String. It has a timeout of 10 seconds, after wich it returns "errTimeout".
# MBStringToNum(String input);
  Turns the String input, which should be MorseBin formatted for the function to work correctly, into a byte, which is a number from 0 to 255. Returns a byte.
# MBNumToString(byte input);
  Turns the byte input into a MorseBin formatted String. Returns a String.
