#include "initialization/drive_initialization.h"
#include "pros/abstract_motor.hpp"
#include "pros/motor_group.hpp"

pros::MotorGroup DL({1, 2, 3}, pros::MotorGearset::blue);
pros::MotorGroup DR({4, 5, 6}, pros::MotorGearset::blue);


DriveExplicit::DriveExplicit(pros::MotorGroup* DL, pros::MotorGroup* DR)
    : DL(DL), DR(DR) {};


void DriveExplicit::move_drive(double DL_rpm, double DR_rpm){
    DL->move(DL_rpm);
    DR->move(DR_rpm);
}

DriveExplicit explicitchassis(&DL, &DR);