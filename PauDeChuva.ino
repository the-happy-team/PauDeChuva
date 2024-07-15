#include "PauDeChuva.h"

PauDeChuva mPDC(4, 3, 3200);

void setup() {
  Serial.begin(9600);
  mPDC.addRotation(0, 1);
  mPDC.addRotation(180, 1);
  mPDC.addRotation(0, 1);
  mPDC.addRotation(-180, 1);
}


void loop() {
  mPDC.update();
}
