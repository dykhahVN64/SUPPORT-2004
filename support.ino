#include"support.h"
Button nut(0);
LedArray led(8,19,10,11,1,4,14,15);
void setup() {
  // put your setup code here, to run once:
  
}

void loop() {
  int mode = nut.nhannut();
  if(mode==1)
  {
  led.tatdantrongrangoai();
  }
  if(mode==2)
  {
  led.tatdanngoaivaotrong();
  }
}
