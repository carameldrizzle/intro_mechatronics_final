
#define sensor A1 // Sharp IR GP2Y0A41SK0F (4-30cm, analog)

void setup() {
  Serial.begin(9600); // start the serial port
}

void loop() {
  
  // 5v
  //float volts = analogRead(sensor)*0.0048828125;  // value from sensor * (5/1024)
  float distance = -.0006 * analogRead(1) + .4295;
  float cm = distance * 100;
  //delay(1000); // slow down serial port 
  
  delay(1000);
  Serial.println(cm); // print the distance

}
