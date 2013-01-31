#ifndef ROBOT_H
#define ROBOT_H

#include "WPILib.h"
#include "Constants.h"
#include "Accumulator.h"
#include "DriverStation.h"
#include "Shooter.h"
#include "DriveTrain.h"

/*! \brief controls all the robot's functions
 *
 * \internal We can't include things that include Robot.h because it would cause really bad behavior
 *
 * This class provides a top-level interface for controlling the robot's functions
 * It also does the aiming for the robot */

class Robot {
 private:
  /*! The drive train of the robot */
  DriveTrain driveTrain;
  /*! The accumulator of the robot */
  Accumulator accumulator;
  /*! The shooter of the robot */
  Shooter shooter;

  /*! The robot's camera */
  AxisCamera &camera;
  /*! The robot's compressor */
  Compressor compressor;

  /*! Whether the robot is aimed at its target */
  bool isAimed;
  
 public:
  /*! \brief Default constructor */
  Robot();
  /*! \brief Accumulates frisbees
   * \internal may take care of sensing*/
  void accumulate();
  /*! \brief Fires a frisbee in the current direction of the robot */
  void shoot();
  /*! \brief Aims at a certain point
   * \param yaw The yaw to aim at
   * \param pitch The pitch to aim at */
  void aim(float yaw, float pitch);
  /*! \brief Aims at a target using the camera */
  void aim();
  /*! \brief Climbs the pyramid */
  void climb();
  void update();
};
#endif /* ROBOT_H */