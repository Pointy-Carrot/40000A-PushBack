#pragma once

#include "initialization/drive_initialization.h"
#include "subsystems/cata.h"
#include "lemlib/chassis/chassis.hpp"
#include "subsystems/intake.h"
#include "subsystems/pneumatics.h"
#include "misc/distance_reset.h"
#include "ramsete/ramsete.h"


// explicit drive init
extern DriveExplicit explicitchassis;

// chassis init
extern lemlib::Drivetrain drivetrain;
extern lemlib::ControllerSettings lateral_controller;
extern lemlib::ControllerSettings angular_controller;
extern lemlib::OdomSensors sensors;
extern lemlib::TrackingWheel vertical_tracking_wheel;
extern lemlib::TrackingWheel horizontal_tracking_wheel;
extern lemlib::Chassis chassis;

// intake init
extern IntakeSubsystem intake;

// pneumatics init
extern PneumaticsSubsystem wing;
extern PneumaticsSubsystem loader;
extern PneumaticsSubsystem gate;
extern PneumaticsSubsystem midgoal_switch;

// dist reset init
extern DistanceReset dist_reset;

// cata init
extern CataSubsystem cata; // after gate and midgoal switch

// ramsete init
extern Ramsete ramchassis; // after chassis
