#pragma once

#include "pros/motor_group.hpp"



extern pros::MotorGroup DL;
extern pros::MotorGroup DR;

class DriveExplicit {
    public:

        pros::MotorGroup* DL;
        pros::MotorGroup* DR;

        /**
         * @brief explicit drivetrain controller constructor
         * 
         * @param DL drive left side motors
         * @param DR drive right side motors
         */
        DriveExplicit(pros::MotorGroup* DL, pros::MotorGroup* DR);

        /**
         * @brief each side of the drivetrain at a specified rpm
         * 
         * @param DL_rpm rpm for the left drive motors
         * @param DR_rpm rpm for the right drive motors
         */
        void move_drive(double DL_rpm, double DR_rpm);
};

extern DriveExplicit explicitchassis;