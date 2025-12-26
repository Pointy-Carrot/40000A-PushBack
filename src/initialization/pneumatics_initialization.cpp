#include "initialization/pneumatics_initialization.h"
#include "pros/adi.hpp"

pros::adi::Pneumatics midgoal_piston('A', true);
pros::adi::Pneumatics loader_piston('H', false);
pros::adi::Pneumatics wing_piston('C', false);
pros::adi::Pneumatics odom_lift_piston('F', false);
pros::adi::Pneumatics gate_piston('G', false);