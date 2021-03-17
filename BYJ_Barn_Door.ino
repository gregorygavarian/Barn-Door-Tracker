#include <AccelStepper.h>
#define HALFSTEP 8

// Motor pin definitions
#define motorPin1  8     // IN1 on the ULN2003 driver 1
#define motorPin2  9     // IN2 on the ULN2003 driver 1
#define motorPin3  10    // IN3 on the ULN2003 driver 1
#define motorPin4  11    // IN4 on the ULN2003 driver 1

// Initialize with pin sequence IN1-IN3-IN2-IN4 for using the AccelStepper with 28BYJ-48
AccelStepper motor(HALFSTEP, motorPin1, motorPin3, motorPin2, motorPin4);
float stepsPerRevolution = 4076, stepsPerSecond, time, dist=11.46, tpi=20;

void setup()
{
  motor.setMaxSpeed(1000.0);
}

void loop() {
  time = millis()/1000;
  stepsPerSecond = stepsPerRevolution*tpi*dist*tan(0.0000727*time)/time;
  motor.setSpeed(stepsPerSecond);
  motor.runSpeed();
}


