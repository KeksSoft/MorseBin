#define pin 9
void setup() {
  // put your setup code here, to run once:
  pinMode(pin,OUTPUT);
  Serial.begin(9600);
}

void loop() {
      if(Serial.available()){
        sendByte(Serial.readString(),pin);
        delay(1000);
        }
}
void Send0(int sendpin) {
 digitalWrite(sendpin,HIGH);
 delay(30);
 digitalWrite(sendpin,LOW);
 delay(10);
  }
  void Send1(int sendpin) {
 digitalWrite(sendpin,HIGH);
 delay(10);
 digitalWrite(sendpin,LOW);
 delay(10);
  }
  void sendByte(String input,int sendpin){
    //Serial.println("gotit");
    for (int i=0;i<8;i++){
    if (input.charAt(i)=='1'){
      Send1(sendpin);
      //Serial.println("gotit1");
      }
      if (input.charAt(i)=='0'){
      Send0(sendpin);
      //Serial.println("gotit0");
      }
    }
  }
