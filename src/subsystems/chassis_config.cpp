#include "subsystems/chassis_config.h"
#include "initialization/sensor_initialization.h"
#include "lemlib/chassis/chassis.hpp"
#include "initialization/drive_initialization.h"
#include "lemlib/chassis/trackingWheel.hpp"

lemlib::TrackingWheel vertical_tracking_wheel(&vert_tracker, lemlib::Omniwheel::NEW_2, -2.631);

lemlib::TrackingWheel horizontal_tracking_wheel(&horiz_tracker, lemlib::Omniwheel::NEW_2, .589);

lemlib::Drivetrain drivetrain(&DL, // left drive motors
                              &DR, // right drive motors
                              10.724, // track width
                              lemlib::Omniwheel::NEW_275, // wheel size
                              600, // rpm
                              2 // horizontal drift
);

lemlib::ControllerSettings lateral_controller(6, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              22, // derivative gain (kD)
                                              0, // anti windup
                                              1, // small error range, in inches
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in inches
                                              1000, // large error range timeout, in milliseconds
                                              20// maximum acceleration (slew)
);

lemlib::ControllerSettings angular_controller(2.5, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              27, // derivative gain (kD)
                                              0, // anti windup
                                              1, // small error range, in degrees
                                              1000, // small error range timeout, in milliseconds
                                              3, // large error range, in degrees
                                              500, // large error range timeout, in milliseconds
                                              0// maximum acceleration (slew)
);

lemlib::OdomSensors sensors(&vertical_tracking_wheel, // vertical tracking wheel
                            nullptr, // vertical tracking wheel 2, set to nullptr as we don't have a second one
                            &horizontal_tracking_wheel, // horizontal tracking wheel
                            nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
                            &imu // inertial sensor
);
