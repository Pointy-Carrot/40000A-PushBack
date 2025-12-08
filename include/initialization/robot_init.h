#pragma once

#include "initialization/drive_initialization.h"
#include "subsystems/cata.h"
#include "lemlib/chassis/chassis.hpp"
#include "subsystems/intake.h"
#include "subsystems/pneumatics.h"
#include "subsystems/scoring_system.h"



// explicit drive init
extern DriveExplicit explicitchassis;

// cata init
extern CataSubsystem cata;
extern CataState cata_position;

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
