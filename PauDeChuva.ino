#include "PauDeChuva.h"

PauDeChuva mPDC[3] = { { 4, 3, 2, 5, 6400 }, { 8, 7, 6, 9, 6400 }, { 12, 11, 10, 13, 6400 } };

void setup() {
  mPDC[0].addRotation(0, 0);
  mPDC[0].addRotation(0, 2);
  mPDC[0].addRotation(180, 45);
  mPDC[0].addRotation(0, 5);
  mPDC[0].addRotation(0, 53);

  mPDC[1].addRotation(0, 0);
  mPDC[1].addRotation(0, 11);
  mPDC[1].addRotation(180, 45);
  mPDC[1].addRotation(0, 5);
  mPDC[1].addRotation(0, 44);

  mPDC[2].addRotation(0, 0);
  mPDC[2].addRotation(0, 20);
  mPDC[2].addRotation(180, 45);
  mPDC[2].addRotation(0, 5);
  mPDC[2].addRotation(0, 35);
}

void loop() {
  mPDC[0].update();
  mPDC[1].update();
  mPDC[2].update();
}
