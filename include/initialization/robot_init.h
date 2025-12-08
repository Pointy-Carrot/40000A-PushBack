#pragma once

#include "initialization/drive_initialization.h"
#include "subsystems/cata.h"
#include "lemlib/chassis/chassis.hpp"
#include "subsystems/intake.h"
#include "subsystems/pneumatics.h"
#include "subsystems/scoring_system.h"
#include "mist/distance_reset.h"
#include "ramsete/trajectory.h"
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
extern IntakeState intake_state;
extern PreviousIntakeState prev_intake_state;

// pneumatics init
extern PneumaticsSubsystem wing;
extern PneumaticsSubsystem loader;
extern PneumaticsSubsystem gate;
extern PneumaticsSubsystem midgoal_switch;

// scoring system init
extern Color alliance_color;

// dist reset init
extern DistanceReset dist_reset;

// cata init
extern CataSubsystem cata; // after gate and midgoal switch
extern CataState cata_position;

// trajectory init
extern Trajectory load_trajectory_from_asset(const char* path_data);
extern Trajectory path_one;
extern Trajectory path_two;

// ramsete init
extern Ramsete ramchassis; // after chassis
