
#include <Pixy2.h>
#include <Servo.h>

Pixy2 pixy;
Servo myServo;

int servopwm = 3;

void setup() {
  pixy.init();
  myServo.attach(3);
  
}

void loop() {
  int i;
  pixy.ccc.getBlocks();
  if (pixy.ccc.numBlocks) {
    for (i = 0; i < pixy.ccc.numBlocks; i++) {
      if (pixy.ccc.blocks[i].m_signature == 1){
        myServo.write(0);
        delay(10000);
        myServo.write(90);
        delay(3000);
      }
    }
  }
}
