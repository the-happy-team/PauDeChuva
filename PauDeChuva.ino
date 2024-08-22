#include "PauDeChuva.h"

PauDeChuva mPDC(4, 3, 2, 5, 3200);

void setup() {
  mPDC.addRotation(0, 2);
  mPDC.addRotation(180, 30);
  mPDC.addRotation(0, 20);
  mPDC.addRotation(0, 8);
}

void loop() {
  mPDC.update();
}
