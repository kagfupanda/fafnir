<<<<<<< HEAD
#ifndef ROBOT_H
#define ROBOT_H

#include "Accumulator.h"
#include "AutonomousController.h"
#include "DriverStation.h"
#include "Shooter.h"

class Robot {
private:
   DriverStation driverStation;
   Shooter shooter;
   AutonomousController autonomousController;
   Accumulator accumulator;
public:
   void drive(int speed); //drive forward at speed
   void drive(int speed, int speed); // left, right motor set speeds
   void drive(int speed, int curvature); // drive at speed and curvature
   void accumulate(); // take care of sensing?
   void shoot(); // just shoot, no aiming
   void aim(int x, int y); // angle to aim
   void aim(RGBImage image); // image to aim at

   Robot();
};
#endif /* ROBOT_H */

=======
#ifndef ROBOT_H
#define ROBOT_H

#include "Constants.h"
#include "Accumulator.h"
#include "AutonomousController.h"
#include "DriverStation.h"
#include "Shooter.h"

class Robot {
private:
   DriverStation driverStation;
   Shooter shooter;
   AutonomousController autonomousController;
   Accumulator accumulator;
public:
   void drive(int speed); //drive forward at speed
   void drive(int speed, int speed); // left, right motor set speeds
   void drive(int speed, int curvature); // drive at speed and curvature
   void accumulate(); // take care of sensing?
   void shoot(); // just shoot, no aiming
   void aim(int x, int y); // angle to aim
   void aim(RGBImage image); // image to aim at
};
#endif /* ROBOT_H */
>>>>>>> 744eacfb4a25c00ca2f25a4cba009437e374c465
