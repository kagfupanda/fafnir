#include "Shooter.h"

Shooter::Shooter() 
    :    elevationEncoder((UINT32)PORT_SHOOTER_ENC_1_A, (UINT32)PORT_SHOOTER_ENC_1_B)
    ,    speedEncoder((UINT32)PORT_SHOOTER_ENC_2_A, (UINT32)PORT_SHOOTER_ENC_2_B)
    ,    motor1(PORT_SHOOTER_VIC_1)
    ,    motor2(PORT_SHOOTER_VIC_2)
    ,    motor3(PORT_SHOOTER_VIC_3)
    ,    motorElevation(PORT_SHOOTER_VIC_ELEVATION)
    ,    sol1(PORT_SHOOTER_SOL_1)
    ,    sol2(PORT_SHOOTER_SOL_2)
    ,    elevationController(3.0f, 0.0f, -1.0f, &elevationError, &outputFiller) { // 3,0,-1 are pid constants
    setElevation(30.0); // constructor that will set the elevation as 30 (default)

    elevationEncoder.SetDistancePerPulse(SHOOTER_DEG_PER_PULSE);
    speedEncoder.SetDistancePerPulse(SHOOTER_ENC_FEET_PER_PULSE);
    
    motorPower = 0;
    elevationError.PIDWrite(0.0);

}

//Shooter:: Shooter(elevationY) {
//  setElevation(elevationY); // a constructor that will take an argument that will set the elevation of the shooter
//}
void Shooter::setElevation(float f) {
  // sets target elevation
  elevationTarget = f;
} 

void Shooter::setSpinSpeed(float sp) {
  motor1.Set(sp);
  motor2.Set(sp);
  motor3.Set(sp);
}

void Shooter::shoot() {
  setSpinSpeed(1.0); // is 100 a reasonable value?
  // push frisbee into shooter

  sol1.Set(true);
  sol1.Set(true);
}

void Shooter::update() {
  elevationError.PIDWrite(elevationEncoder.GetDistance() - elevationTarget);
  /* note that just because we updated the error doesn't mean the output
  changed b/c the PID loop updates in its own loop */
  motorPower = elevationController.Get();
  motorElevation.Set(motorPower); //not sure what the write set pwoer method is
}

