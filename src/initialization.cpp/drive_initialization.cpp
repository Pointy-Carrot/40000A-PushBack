#include "initialization/drive_initialization.h"
#include "pros/abstract_motor.hpp"

pros::MotorGroup DL({1, 2, 3}, pros::MotorGearset::blue);
pros::MotorGroup DR({4, 5, 6}, pros::MotorGearset::blue);