#ifndef MorseBin_h
#define MorseBin_h
#include <Arduino.h>

extern String MBReceive(int respin);
extern void MBSendByte(String input,int sendpin);
extern void MBSend0(int sendpin);
extern void MBSend1(int sendpin);
#endif