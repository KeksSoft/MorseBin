#include <Arduino.h>
#include <MorseBin.h>
String MBReceive(int respin){
  String buf;
 for (int i=0;i<8;i++){
 int timer = 0;
   while (digitalRead(respin)==LOW){
    timer++;
    delay(1);
    if(timer>=10000){
      timer = 0;
      return "";
	  }
    }
    int t = 0;
    while(digitalRead(respin)==HIGH) {
      t++;
      delay(10);
      }
      if (t > 2) {
        buf += "0";
        }
        else {
          buf += "1";
          }        
    }
    return buf;
  }
void MBSend0(int sendpin) {
 digitalWrite(sendpin,HIGH);
 delay(30);
 digitalWrite(sendpin,LOW);
 delay(10);
  }
void MBSend1(int sendpin) {
 digitalWrite(sendpin,HIGH);
 delay(10);
 digitalWrite(sendpin,LOW);
 delay(10);
  }
void MBSendByte(String input,int sendpin){
    //Serial.println("gotit");
    for (int i=0;i<8;i++){
    if (input.charAt(i)=='1'){
      MBSend1(sendpin);
      //Serial.println("gotit1");
      }
      if (input.charAt(i)=='0'){
      MBSend0(sendpin);
      //Serial.println("gotit0");
      }
    }
  }
  
