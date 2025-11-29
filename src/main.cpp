#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "pros/misc.h"
#include "pros/misc.hpp"
#include "initialization/controller_initialization.h"
#include "pros/motors.h"
#include "subsystems/chassis_config.h"
#include "subsystems/scoring_system.h"
#include "subsystems/intake.h"
#include "subsystems/cata.h"
#include "misc/autons.h"

void initialize() {
	pros::lcd::initialize();
	intake.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	cata.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	cata.setDownPosition(0); // TUNE
	cata.setHalfPosition(0); // TUNE
	cata.setLongGoalPosition(0); // TUNE
	cata.setMidgoalPosition(0); // TUNE

	scoring_system_controller(); // main control loop
}

void disabled() {}

void competition_initialize() {}

void autonomous() {
	full_sawp();
}

void opcontrol() {
	cata.midgoal_mech_up(); // midgoal mech raises at driver start

	while (true) {
		int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rightX = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
        chassis.arcade(leftY, rightX);
		driver_intake();
		driver_cata();
		driver_wing();
        // delay to save resources
        pros::delay(10);
	}
}