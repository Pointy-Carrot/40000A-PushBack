#include "subsystems/scoring_system.h"
#include "initialization/motor_initialization.h"
#include "initialization/pneumatics_initialization.h"
#include "subsystems/intake.h"
#include "subsystems/cata.h"

bool midgoal = false;
bool driver_controlled_cata = false;
bool slow_cata = false;
bool colorsort_on = true;

void intake_while_scoring_long(){
    cata.score_long();
    while(!cata.is_halfway_up()){
        intake.brake();
        pros::delay(10);
    }
    intake.move(127);
}

void intake_while_scoring_mid(){
    cata.score_mid();
    while(!cata.is_halfway_up()){
        intake.brake();
        pros::delay(10);
    }
    intake.move(127);
}




void scoring_system_controller(){
    pros::Task scoring_system_task([]{
        // all scoring subsystem controls
        switch(intake_state){
            case INTAKE:
                intake_motor.move(intake.volts);
                colorsort_motor.move(intake.volts);
                if(colorsort_on){
                    intake.sort(intake.get_alliance_color());
                }
                break;
            case OUTTAKE:
                intake_motor.move(intake.volts);
                colorsort_motor.move(intake.volts);
                break;
            case SORT:
                intake_motor.move(127);
                colorsort_motor.move(-127);
                break;
            case STOP:
                intake_motor.brake();
                colorsort_motor.brake();
                break;
        }
        
        // cata controls
        switch(cata_position){
            case UP:
                cata.move_to(cata.get_up_position());
                gate_piston.extend();
                break;
            case MIDGOAL:
                cata.move_to(cata.get_midgoal_position());
                gate_piston.extend();
                break;
            case DOWN:
                cata.move_to(cata.get_down_position());
                gate_piston.retract();
                break;
            case HALF:
                cata.move_to(cata.get_half_position());
                gate_piston.extend();
                break;
        }

        // delay to save resources
        pros::delay(10);
    });
}