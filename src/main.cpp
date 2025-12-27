#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "pros/misc.h"
#include "pros/misc.hpp"
#include "initialization/controller_initialization.h"
#include "pros/motors.h"
#include "initialization/robot_init.h"
#include "subsystems/scoring_system.h"
#include "subsystems/intake.h"
#include "subsystems/cata.h"
#include "misc/autons.h"
#include "initialization/sensor_initialization.h"


void initialize() {
	pros::lcd::initialize();
	chassis.calibrate();
	colorsort_optical.set_led_pwm(100);
	intake.get_alliance_pot_selection();
	intake.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	cata.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	cata.setDownPosition(3700); // TUNE
	cata.setHalfPosition(1800); // TUNE
	cata.setLongGoalPosition(700); // TUNE
	cata.setMidgoalPosition(500); // TUNE
	cata.setLoadPosition(3650); // TUNE
	cata_controller(); // cata control loop
	intake_controller(); // intake control loop

	pros::Task screenTask([]() {
        while (true) {
            // print robot location to the brain screen
            std::cout<<chassis.getPose().x<<std::endl;

            pros::delay(50);
        }
    });
}

void disabled() {}

void competition_initialize() {}

void autonomous() {
	tuning_prog();
}

void opcontrol() {
	driver_control = true;
	cata.midgoal_mech_up(); // midgoal mech raises at driver start
	cata.down(127);

	while (true) {
		int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rightX = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
        chassis.arcade(leftY, rightX);
		driver_intake();
		driver_cata();
		driver_wing();
		driver_loader();
		driver_odom_lift();
        // delay to save resources
        pros::delay(10);
	}
}
