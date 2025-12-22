#include "subsystems/scoring_system.h"
#include "subsystems/intake.h"
#include "subsystems/cata.h"
#include "initialization/controller_initialization.h"
#include "initialization/robot_init.h"
#include "initialization/sensor_initialization.h"


bool midgoal = false;
bool manual_cata_control = false;
bool slow_cata = false;
bool colorsort_on = true;

void intake_while_scoring_long(){
	cata.score_long();
    pros::delay(500);
    cata.down();
    pros::delay(500);
    intake.move(127);
    pros::delay(500);
    cata.score_long();
}

void intake_while_scoring_mid(){
	cata.score_mid();
    pros::delay(500);
    cata.down();
    pros::delay(500);
    intake.move(127);
    pros::delay(500);
    cata.score_mid();
}

void cata_controller(){ // main intake/cata command loop
    pros::Task cata_task([]{
        while(1){
        // cata controls
        switch(cata_position){
            case LONGGOAL:
                gate.extend();
                if(prev_cata_position != LONGGOAL){
                    cata.move_to(cata.get_long_goal_position());
                }
                prev_cata_position = LONGGOAL;
                break;
            case MIDGOAL:
                gate.extend();
                if(prev_cata_position != MIDGOAL){
                    cata.move_to(cata.get_midgoal_position());
                }
                prev_cata_position = MIDGOAL;
                break;
            case DOWN:
                gate.retract();
                if(prev_cata_position != DOWN){
                    cata.move_to(cata.get_down_position());
                }
                prev_cata_position = DOWN;
                break;
            case HALF:
                gate.extend();
                if(prev_cata_position != HALF){
                    cata.move_to(cata.get_half_position());
                }
                prev_cata_position = HALF;
                break;
        }

        // delay to save resources
        pros::delay(20);
    }
    });
}

void intake_controller(){
    pros::Task intake_task([]{
        while(1){
        // intake controls
        switch(intake_state){
            case INTAKE:
                intake.move_velo(intake.volts);
                // IS BREAKING THINGS
                // if(colorsort_on){ 
                //     intake.sort(intake.get_alliance_color());
                // }
                break;
            case OUTTAKE:
                intake.move_velo(intake.volts);
                break;
            case SORT:
                intake.move_velo(-127);
                break;
            case STOP:
                intake.brake();
                break;
        }
    }
    });
}

void driver_intake(){
    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)){ // L1 -> intake
		intake.move(127);
	} else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){ // L2 -> if stopped then reverse, if moving then stop
		intake.move(-127);
	} else {
		intake.brake();
	}

    // colorsort switch
	if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP)){ // UP -> toggle color sort on/off
		if(colorsort_on){
			intake.sort_off();
		} else{
			intake.sort_on();
		}
	}
}

void driver_cata(){
    if(manual_cata_control){ // if manual cata control is enabled switch to raw R1 -> up / R2 -> down
        if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){ // R1 -> cata up
            if(midgoal){ // if midgoal is enabled set max cata height to midgoal position
                if(cata_pot.get_value() > cata.get_midgoal_position()){ // check to see if cata has reached max height
                    if(slow_cata){ // if slow cata enabled lower cata speed
                        cata.move(90);
                    } else{ // if slow cata not enabled run cata at full speed
                        cata.move(127);
                    }
                } else{ // if cata at max height stop cata
                    cata.brake();
                }
            } else { // if midgoal not enabled set max cata height to long goal position
                if(cata_pot.get_value() > cata.get_long_goal_position()){ // check to see if cata has reached max height
                    if(slow_cata){ // if slow cata enabled lower cata speed
                        cata.move(90);
                    } else{ // if slow cata not enabled run cata at full speed
                        cata.move(127);
                    }
                } else{ // if cata at max height stop cata
                    cata.brake();
                }
            }
	    } else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2) && (cata_pot.get_value() < cata.get_down_position())){ // R2 -> cata down
			cata.move(-127);
		} else{
			cata.brake();
		}

	} else{ // if manual cata control not enabled
        if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R1)){ // R1 -> cata up
            if(midgoal){ // if midgoal enabled move cata to midgoal position
                    cata.score_mid();
                } else{ // if midgoal not enabled move cata to long goal position
                    cata.score_long();
            }
        } else if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R2)){ // R2 -> cata down
			cata.down();
		}
	}

    // manual cata control switch
	if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)){ // A -> toggle manual cata control on/off
		if(manual_cata_control){ 
			manual_cata_control = false;
		} else{
			manual_cata_control = true;
		}
	}

    // slow cata switch
	if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)){ // DOWN -> toggle slower cata on/off
		if(slow_cata){
			slow_cata = false;
		} else{
			slow_cata = true;
		}
	}

    if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)){ // RIGHT -> toggle midgoal scoring on/off
		if(midgoal){
			midgoal = false;
		} else{
			midgoal = true;
		}
	}
}

void driver_wing(){
    if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y)){ // Y -> toggle wing up/down
		wing.toggle();
	}
}

void driver_loader(){
    if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)){ // B -> toggle loader up/down
        loader.toggle();
    }
}
