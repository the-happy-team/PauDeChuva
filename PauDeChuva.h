#include <AccelStepper.h>

#define MAX_ROTATIONS 16

class Rotation {
public:
  int16_t target;
  uint16_t speed;
  uint32_t millis;
  Rotation(int16_t target = 0, uint16_t speed = 0, uint32_t millis = 0)
    : target{ target }, speed{ speed }, millis{ millis } {}
};

class PauDeChuva {
private:
  AccelStepper mStepper;
  uint16_t stepsPerRevolution;
  Rotation rotations[MAX_ROTATIONS];
  uint8_t maxRotations;
  uint8_t nRotations;
  uint8_t cRotation;

  uint32_t nextChange;

public:
  // AccelStepper(AccelStepper::DRIVER, stepPin, directionPin);
  PauDeChuva(uint8_t stepPin, uint8_t directionPin,
             uint8_t enablePin, uint8_t referencePin,
             uint16_t stepsPerRevolution = 3200)
    : mStepper(AccelStepper::DRIVER, stepPin, directionPin),
      stepsPerRevolution{ stepsPerRevolution },
      maxRotations{ MAX_ROTATIONS },
      nRotations{ 0 },
      cRotation{ 0 } {

    pinMode(referencePin, OUTPUT);
    digitalWrite(referencePin, HIGH);
    mStepper.setEnablePin(enablePin);
    mStepper.setCurrentPosition(0);
    mStepper.setMaxSpeed(stepsPerRevolution / 2);
    mStepper.setAcceleration(stepsPerRevolution * 1000);
    mStepper.moveTo(0);
  }

  void addRotation(int16_t degrees, float seconds) {
    if (nRotations >= maxRotations) return;

    int16_t target = int16_t((degrees / 360.0f) * stepsPerRevolution);

    rotations[nRotations].target = target;
    rotations[nRotations].speed = uint16_t(abs(target) / seconds);
    rotations[nRotations].millis = uint16_t(1000 * seconds);

    nRotations += 1;
  }

  void update() {
    mStepper.run();

    if (nRotations < 1) return;

    // stepper.currentPosition() != TARGET
    int32_t timeToGo = nextChange - millis();

    if (mStepper.distanceToGo() == 0 && timeToGo <= 0) {
      cRotation = (cRotation + 1) % nRotations;

      int16_t cTarget = rotations[cRotation].target;
      uint16_t cSpeed = rotations[cRotation].speed;

      nextChange = millis() + rotations[cRotation].millis;

      if (cRotation == 0) {
        mStepper.enableOutputs();
      } else if (cRotation == (nRotations - 1) && cTarget == 0) {
        mStepper.disableOutputs();
      }

      mStepper.setMaxSpeed(cSpeed);
      mStepper.setAcceleration(2000 * cSpeed);
      mStepper.move(cTarget);
    }
  }
};
