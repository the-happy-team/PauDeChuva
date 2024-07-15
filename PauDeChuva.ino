#include "PauDeChuva.h"

PauDeChuva mPDC(4, 3, 3200);

void setup() {
  Serial.begin(9600);

  mPDC.addRotation(0, 10);
  for (int i = 0; i < 4; i++) {
    mPDC.addRotation(45, 10);
    mPDC.addRotation(0, 0.1f);
  }

  mPDC.addRotation(0, 10);
  for (int i = 0; i < 4; i++) {
    mPDC.addRotation(-45, 10);
    mPDC.addRotation(0, 0.1f);
  }
}


void loop() {
  mPDC.update();
}
