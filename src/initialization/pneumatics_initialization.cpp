#include "initialization/pneumatics_initialization.h"
#include "pros/adi.hpp"

pros::adi::Pneumatics gate_piston('A', false);
pros::adi::Pneumatics midgoal_piston('B', true);
pros::adi::Pneumatics loader_piston('C', false);
pros::adi::Pneumatics wing_piston('D', false);