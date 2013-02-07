#include "Shooter.h"

//int main() {
//  Shooter target1(28.3928); // just a test
//}

Shooter::Shooter() 
    :    elevationEncoder((UINT32)PORT_SHOOTER_ENC_1_A, (UINT32)PORT_SHOOTER_ENC_1_B) 
    ,    motor1(PORT_SHOOTER_VIC_1)
    ,    motor2(PORT_SHOOTER_VIC_2)
    ,    motor3(PORT_SHOOTER_VIC_3)
    ,    motorElevation(PORT_SHOOTER_VIC_ELEVATION)
    ,    elevationController(3,0,-1,elevationError,outputFiller) { // 3,0,-1 are pid constants
    setElevation(30.0); // constructor that will set the elevation as 30 (default)

    motorPower = 0;
    elevationError.writePID(0.0);
}

//Shooter:: Shooter(elevationY) {
//  setElevation(elevationY); // a constructor that will take an argument that will set the elevation of the shooter
//}
void Shooter::setElevation(float f) {
  // sets target elevation
  targetElevation = f;
} 

void Shooter::setSpinSpeed(float sp) {
  motor1.setPower(sp);
  motor2.setPower(sp);
  motor3.setPower(sp);
}

void Shooter::update() {
  elevationError.writePID(elevationEncoder.getAngle() - f);
  /* note that just because we updated the error doesn't mean the output
  changed b/c the PID loop updates in its own loop */
  motorPower = elevationController.get();
  motorElevation.setPower(motorPower); //not sure what the write set pwoer method is
}
