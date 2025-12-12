#include "subsystems/scoring_system.h"
#include "initialization/motor_initialization.h"
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
	pros::Task intake_while_scoring_long_task([]{
    	cata.score_long();
    	while(!cata.is_halfway_up()){ // wait until cata is halfway up before continuing intake
    	    intake.brake();
    	    pros::delay(10);
    	}
    	intake.move(127);
	});
}

void intake_while_scoring_mid(){
	pros::Task intake_while_scoring_mid_task([]{
    	cata.score_mid();
    	while(!cata.is_halfway_up()){ // wait until cata is halfway up before continuing intake
        	intake.brake();
        	pros::delay(10);
    	}
    	intake.move(127);
	});
}

void scoring_system_controller(){ // main intake/cata command loop
    pros::Task scoring_system_task([]{
        // all scoring subsystem controls
        switch(intake_state){
            case INTAKE:
                intake_motor.move(intake.volts);
                if(colorsort_on){
                    intake.sort(intake.get_alliance_color());
                }
                break;
            case OUTTAKE:
                intake_motor.move(intake.volts);
                break;
            case SORT:
                intake_motor.move(-127);
                break;
            case STOP:
                intake_motor.brake();
                break;
        }
        
        // cata controls
        switch(cata_position){
            case LONGGOAL:
                gate.extend();
                cata.move_to(cata.get_long_goal_position());
                break;
            case MIDGOAL:
                gate.extend();
                cata.move_to(cata.get_midgoal_position());
                break;
            case DOWN:
                gate.retract();
                cata.move_to(cata.get_down_position());
                break;
            case HALF:
                gate.extend();
                cata.move_to(cata.get_half_position());
                break;
        }

        // delay to save resources
        pros::delay(10);
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
                if(cata_pot.get_value() < cata.get_midgoal_position()){ // check to see if cata has reached max height
                    if(slow_cata){ // if slow cata enabled lower cata speed
                        cata.move(90);
                    } else{ // if slow cata not enabled run cata at full speed
                        cata.move(127);
                    }
                } else{ // if cata at max height stop cata
                    cata.brake();
                }
            } else { // if midgoal not enabled set max cata height to long goal position
                if(cata_pot.get_value() < cata.get_long_goal_position()){ // check to see if cata has reached max height
                    if(slow_cata){ // if slow cata enabled lower cata speed
                        cata.move(90);
                    } else{ // if slow cata not enabled run cata at full speed
                        cata.move(127);
                    }
                } else{ // if cata at max height stop cata
                    cata.brake();
                }
            }
	    }

		if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2) && (cata_pot.get_value() > cata.get_down_position())){ // R2 -> cata down
			cata.move(-127);
		} else{
			cata.brake();
		}

	} else{ // if manual cata control not enabled
        if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R1)){ // R1 -> cata up
            if(midgoal){ // if midgoal enabled move cata to midgoal position
                    if(intake_state == INTAKE){ // if intaking run macro to score while intaking
                        intake_while_scoring_mid();
                    } else{ // if not intaking just score
                        cata.score_mid();
                    }
                } else{ // if midgoal not enabled move cata to long goal position
                    if(intake_state == INTAKE){ // if intaking run macro to score while intaking
                        intake_while_scoring_long();
                    } else{ // if not intaking just score
                        cata.score_long();
                    }
            }
        } else if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R2)){ // R2 -> cata down
			cata.down();
		}
	}

    // manual cata control switch
	if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)){ // B -> toggle manual cata control on/off
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
    if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X)){
        loader.toggle();
    }
}
