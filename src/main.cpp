#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "pros/misc.h"
#include "pros/misc.hpp"
#include "initialization/controller_initialization.h"
#include "subsystems/chassis_config.h"
#include "subsystems/scoring_system.h"
#include "subsystems/intake.h"
#include "subsystems/cata.h"
#include "initialization/pneumatics_initialization.h"
#include "initialization/sensor_initialization.h"
#include "autons.h"

void initialize() {
	pros::lcd::initialize();
	intake.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	scoring_system_controller();
}

void disabled() {}

void competition_initialize() {}

void autonomous() {
	full_sawp();
}

void opcontrol() {
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	cata.midgoal_mech_up();

	while (true) {
		int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rightX = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
        chassis.arcade(leftY, rightX);




		// cata controls
		if(driver_controlled_cata){
			if(slow_cata){
				if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1) && (cata_pot.get_value() < cata.get_up_position())){
					cata.move(90);
				} else{
					cata.brake();
				}
			} else{
				if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1) && (cata_pot.get_value() < cata.get_up_position())){
					cata.move(127);
				} else{
					cata.brake();
				}
			}
			if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2) && (cata_pot.get_value() > cata.get_down_position())){
				cata.move(-127);
			} else{
				cata.brake();
			}
		} else{
			if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1) && controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2) && !(cata_position == MIDGOAL)){
				cata.score_mid();
			} else if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R1)){
				if(intake_state == INTAKE){
					if(midgoal){
						intake_while_scoring_mid();
					} else{
						intake_while_scoring_long();
					}
				} else{

					cata.score_long();
				}
			} else if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R2)){
				cata.down();
			}
		}

		// intake controls
		if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1)){
			intake.move(127);
		} else if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2)){
			if(intake_state != STOP){
				intake.brake();
			} else{
				intake.move(-127);
			}
		}

		// midgoal switch
		if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)){
			if(midgoal){
				midgoal = false;
			} else{
				midgoal = true;
			}
		}

		// wing control
		if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y)){
			wing_piston.toggle();
		}

		// manual cata control switch
		if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)){
			if(driver_controlled_cata){
				driver_controlled_cata = false;
			} else{
				driver_controlled_cata = true;
			}
		}

		// slow cata switch
		if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)){
			if(slow_cata){
				slow_cata = false;
			} else{
				slow_cata = true;
			}
		}

		// colorsort switch
		if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP)){
			if(colorsort_on){
				colorsort_on = false;
			} else{
				colorsort_on = true;
			}
		}

        // delay to save resources
        pros::delay(10);
	}
}