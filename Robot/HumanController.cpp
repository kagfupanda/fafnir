#include "HumanController.h"

HumanController::HumanController(Robot *robot)
  :    speedStick(PORT_JS_SPEED)
  ,    turnStick(PORT_JS_TURN)
  ,    operatorStick(PORT_JS_OPERATOR) {
  this->robot = robot;
}

AutonomousMode HumanController::getAutonomousMode() {
  return DEFAULT;
}


void HumanController::update() {
  //check current state of joysticks
  //calculate what to do based on joysticks and robot state (e.g. drive speed for certain gear)
  //gear ranges should look something like:
  //low gear: 0 ft/sec – 5.5 ft/sec
  //high gear: 5 ft/sec – max speed (probably 16 ft/sec)

  /* begin drive forward/backward */
  robot->setSpeed(speedStick.getX());
  /* end drive forward/backward */
  
  /* begin Gearshifter changing */
  if(turnStick.GetRawButton(JS_TURN_MODE_TOGGLE)) {
    if(!buttShifterMode) {
      if(robot->getShifterMode() == AUTO) {
	robot->setShifterMode(MANUAL);
      }
      else {
	robot->setShifterMode(AUTO);
      }
    }
  }
  else if(turnStick.GetRawButton(JS_TURN_POSITION_LOW)) {
    robot->setShifterPosition(LOW_GEAR);
  }
  else if(turnStick.GetRawButton(JS_TURN_POSITION_HIGH)) {
    robot->setShifterPosition(HIGH_GEAR);
  }
  buttShifterMode = turnStick.GetRawButton(JS_TURN_MODE_TOGGLE);
  /* end Gearshifter changing */

  /* begin operator commands */


  

}
