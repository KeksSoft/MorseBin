#define MorseBinPin 9
const int pins[8] = {3,4,5,6,7,8,10,11};
void setup() {
  // put your setup code here, to run once:
for (int i=0;i<8;i++){
  pinMode(pins[i],OUTPUT);
  }
  pinMode(MorseBinPin,INPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  String input = Resc(MorseBinPin);
  if(input.charAt(0)=='1'){digitalWrite(pins[0],HIGH);}
  else{digitalWrite(pins[0],LOW);}
  if(input.charAt(1)=='1'){digitalWrite(pins[1],HIGH);}
  else{digitalWrite(pins[1],LOW);}
  if(input.charAt(2)=='1'){digitalWrite(pins[2],HIGH);}
  else{digitalWrite(pins[2],LOW);}
  if(input.charAt(3)=='1'){digitalWrite(pins[3],HIGH);}
  else{digitalWrite(pins[3],LOW);}
  if(input.charAt(4)=='1'){digitalWrite(pins[4],HIGH);}
  else{digitalWrite(pins[4],LOW);}
  if(input.charAt(5)=='1'){digitalWrite(pins[5],HIGH);}
  else{digitalWrite(pins[5],LOW);}
  if(input.charAt(6)=='1'){digitalWrite(pins[6],HIGH);}
  else{digitalWrite(pins[6],LOW);}
  if(input.charAt(7)=='1'){digitalWrite(pins[7],HIGH);}
  else{digitalWrite(pins[7],LOW);}
}
String Resc(int respin){
  String buf;
 for (int i=0;i<8;i++){
   while (digitalRead(respin)==LOW);
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
