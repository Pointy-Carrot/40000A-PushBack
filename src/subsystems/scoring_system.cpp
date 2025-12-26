#include "subsystems/scoring_system.h"
#include "subsystems/intake.h"
#include "subsystems/cata.h"
#include "initialization/controller_initialization.h"
#include "initialization/robot_init.h"
#include "initialization/sensor_initialization.h"


bool manual_cata_control = false;
bool slow_cata = false;
bool colorsort_on = true;

void intake_while_scoring_long(int time){
    intake.move(-80);
    pros::delay(125);
    intake.brake();
    cata.score_long(127);
    pros::delay(1250);
    intake.move(127);
    pros::delay(time);
    cata.score_long(127);
}

void intake_while_scoring_mid(int time){
    intake.move(-127);
    pros::delay(125);
    intake.brake();
	cata.score_mid(127);
    pros::delay(1000);
    intake.move(127);
    pros::delay(time);
    cata.score_mid(127);
}

void cata_controller(){ // main intake/cata command loop
    pros::Task cata_task([]{
        while(1){
        
        // cata controls
        if(!manual_cata_control){
        switch(cata_position){
            case LONGGOAL:
                cata.past_down = false;
                gate.extend();
                cata.move_to(cata.get_long_goal_position());
                if(cata.get_position() <= cata.get_long_goal_position() && driver_control){
                    cata.down(127);
                    prev_cata_position = DOWN;
                }
                break;
            case MIDGOAL:
                cata.past_down = false;
                gate.retract();
                cata.move_to(cata.get_midgoal_position());
                if(cata.get_position() <= cata.get_midgoal_position()){
                    cata.down(127);
                    prev_cata_position = DOWN;
                }
                break;
            case DOWN:
                gate.retract();

                if(cata.get_position() >= cata.get_down_position()){ // has it already reached down position
                    cata.past_down = true;
                }

                if(cata.past_down && !(cata.get_position() > cata.get_load_position()-50 && cata.get_position() < cata.get_load_position()+50)){ // go to loading position
                    // std::cout<<"LOAD"<<std::endl;
                    cata.voltage = 30;
                    cata.move_to(cata.get_load_position());
                } else if (!cata.past_down){ // go to down position
                    // std::cout<<"DOWN"<<std::endl;
                    cata.move_to(cata.get_down_position());
                } else{
                    cata.brake();
                }
                break;
            case HALF:
                cata.past_down = false;
                gate.retract();
                cata.move_to(cata.get_half_position());
                break;
        }
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
                if((cata.get_position() >= cata.get_load_position()-100) || !driver_control){ // make sure cata is down before intaking
                    if(!colorsort_on){
                        intake.sorting = false;
                    }
                    if(!intake.sorting){
                        intake.move_velo(intake.volts);
                    }
                    if(colorsort_on){
                        intake.sort(intake.get_alliance_color());
                    }
                } else{
                    intake.brake();
                }
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
    if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT)){
        if(intake.alliance_color == 1){
            intake.set_alliance_blue();
        } else{
            intake.set_alliance_red();
        }
    }
}

void driver_cata(){
    if(manual_cata_control){ // if manual cata control is enabled switch to raw R1 -> up / R2 -> down
        cata_position = HALF;
        prev_cata_position = HALF;
        if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){ // R1 -> cata up
            if(!cata.get_midgoal_status()){ // if midgoal is enabled set max cata height to midgoal position
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
            if(!cata.get_midgoal_status()){ // if midgoal enabled move cata to midgoal position
                if(prev_cata_position != MIDGOAL){
                    cata.score_mid(127);
                }
                prev_cata_position = MIDGOAL;
            } else{ // if midgoal not enabled move cata to long goal position
                if(prev_cata_position != LONGGOAL){
                    cata.score_long(127);
                }
                prev_cata_position = LONGGOAL;
            }
        } else if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R2)){ // R2 -> cata down
			if(prev_cata_position != DOWN){
                cata.down(127);
            }
            prev_cata_position = DOWN;
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
        cata.toggle_midgoal_mech();
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

void driver_odom_lift(){
    if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X)){ // X -> toggle odom lift up/down
        odom_lift.toggle();
    }
}

void score_many_low(){
    intake.move(-127);
    cata.down(30);
    pros::delay(1500);
    cata.down(127);
    intake.brake();
}