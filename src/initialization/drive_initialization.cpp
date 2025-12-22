#include "initialization/drive_initialization.h"
#include "pros/abstract_motor.hpp"
#include "pros/motor_group.hpp"

pros::MotorGroup DL({-10, 6, -5}, pros::MotorGearset::blue);
pros::MotorGroup DR({-9, 8, 7}, pros::MotorGearset::blue);


DriveExplicit::DriveExplicit(pros::MotorGroup* DL, pros::MotorGroup* DR)
    : DL(DL), DR(DR) {};


void DriveExplicit::move_drive(double DL_rpm, double DR_rpm){
    DL->move(DL_rpm);
    DR->move(DR_rpm);
}
