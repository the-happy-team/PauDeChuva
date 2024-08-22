#include "PauDeChuva.h"

PauDeChuva mPDC[3] = { { 4, 3, 2, 5 }, { 8, 7, 6, 9 }, { 12, 11, 10, 13 } };

void setup() {
  mPDC[0].addRotation(0, 2);
  mPDC[0].addRotation(180, 30);
  mPDC[0].addRotation(0, 20);
  mPDC[0].addRotation(0, 8);

  mPDC[1].addRotation(0, 2);
  mPDC[1].addRotation(90, 30);
  mPDC[1].addRotation(0, 15);
  mPDC[1].addRotation(90, 30);
  mPDC[1].addRotation(0, 20);
  mPDC[1].addRotation(0, 8);

  mPDC[2].addRotation(0, 2);
  mPDC[2].addRotation(45, 20);
  mPDC[2].addRotation(0, 10);
  mPDC[2].addRotation(45, 20);
  mPDC[2].addRotation(0, 10);
  mPDC[2].addRotation(45, 20);
  mPDC[2].addRotation(0, 10);
  mPDC[2].addRotation(45, 20);
  mPDC[2].addRotation(0, 20);
  mPDC[2].addRotation(0, 8);
}

void loop() {
  mPDC[0].update();
  mPDC[1].update();
  mPDC[2].update();
}
