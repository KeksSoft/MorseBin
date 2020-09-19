#define pin 9
void setup() {
  // put your setup code here, to run once:
pinMode(pin,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(Resc(pin));
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
      if (t > 20) {
        buf += "0";
        }
        else {
          buf += "1";
          }        
    }
    return buf;
  }
