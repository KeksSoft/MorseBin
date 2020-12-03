#include <Arduino.h>
#include <MorseBin.h>
String MBReceive(int respin){
  	String buf;
  	int waitTimer =0;
	while(digitalRead(respin)==LOW);
	while(digitalRead(respin) == HIGH){
		waitTimer++;
		delay(1);
	}
 	if(waitTimer>50){
		delay(1);
	}
	else{
		return "";
	}
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
      	if (t > 2 && t < 5) {
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
	digitalWrite(sendpin,HIGH);
	delay(60);
	digitalWrite(sendpin,LOW);
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
  byte MBStringToNum(String input){
  byte output=0;
  if (input.charAt(7)=='1'){output += 128;}
  else {output += 0;}
  if (input.charAt(6)=='1'){output += 64;}
  else {output += 0;}
  if (input.charAt(5)=='1'){output += 32;}
  else {output += 0;}
  if (input.charAt(4)=='1'){output += 16;}
  else {output += 0;}
  if (input.charAt(3)=='1'){output += 8;}
  else {output += 0;}
  if (input.charAt(2)=='1'){output += 4;}
  else {output += 0;}
  if (input.charAt(1)=='1'){output += 2;}
  else {output += 0;}
  if (input.charAt(0)=='1'){output += 1;}
  else {output += 0;}
    return output;
  }
String MBNumToString(byte input){
  String output = "";
  String realoutput = "";
  if(input >= 128){
    output +="1";
    input -= 128;
    }
    else{output+="0";}
    
  if(input >= 64){
    output +="1";
    input -= 64;
    }
    else{output+="0";} 
       
  if(input >= 32){
    output +="1";
    input -= 32;
    }
    else{output+="0";}  
      
  if(input >= 16){
    output +="1";
    input -= 16;
    }
    else{output+="0";}   
    
  if(input >= 8){
    output +="1";
    input -= 8;
    }
    else{output+="0";}    
    
  if(input >= 4){
    output +="1";
    input -= 4;
    }
    else{output+="0";}    
    
  if(input >= 2){
    output +="1";
    input -= 2;
    }
    else{output+="0";}
    
  if(input >= 1){
    output +="1";
    input -= 1;
    }
    else{output+="0";}
    return output;
}
