#include "subsystems/intake.h"
#include "pros/adi.hpp"
#include "pros/optical.hpp"
#include "subsystems/scoring_system.h"

IntakeState intake_state = STOP;
IntakeState prev_intake_state = STOP;

IntakeSubsystem::IntakeSubsystem(pros::Motor* intake, pros::Optical* sort_sensor, pros::adi::Potentiometer* alliance_pot)
    : intake(intake), sort_sensor(sort_sensor), alliance_pot(alliance_pot) {};

void IntakeSubsystem::move(int voltage){
    volts = voltage;
    if(voltage > 0){
        intake_state = INTAKE;
    } else if(voltage < 0){
        intake_state = OUTTAKE;
    } else {
        intake_state = STOP;
    }
}

void IntakeSubsystem::move_velo(int volts){
    intake->move(volts);
}

void IntakeSubsystem::set_brake_mode(pros::motor_brake_mode_e brake_mode){
    intake->set_brake_mode(brake_mode);
}

void IntakeSubsystem::brake(){
    intake_state = STOP;
    intake->brake();
}

void IntakeSubsystem::store_current_intake_state(){
    switch(intake_state){
        case INTAKE:
            prev_intake_state = INTAKE;
            break;
        case OUTTAKE:
            prev_intake_state = OUTTAKE;
            break;
        case SORT:
            prev_intake_state = SORT;
            break;
        case STOP:
            prev_intake_state = STOP;
            break;
    }
}

void IntakeSubsystem::retrieve_previous_intake_state(){
    switch(prev_intake_state){
        case INTAKE:
            intake_state = INTAKE;
            break;
        case OUTTAKE:
            intake_state = OUTTAKE;
            break;
        case SORT:
            intake_state = SORT;
            break;
        case STOP:
            intake_state = STOP;
            break;
    }
}


void IntakeSubsystem::sort(int alliance_color){
    // wait until object detected
    while(sort_sensor->get_proximity()<100){
        pros::delay(10);
    }
    // optical sensors detect red better than blue, so we check for red detected and not
    // red detected instead of red detected and blue detected
    if(alliance_color == 1){
        // sort out blue
        // wait until color detected
        if(!(sort_sensor->get_hue()>300) || (sort_sensor->get_hue()<60)){ // if not red detected
            store_current_intake_state();
            intake_state = SORT;
            // wait a bit
            pros::delay(250);
            // continue previous state
            retrieve_previous_intake_state();
        }
    } else if(alliance_color == 2){
        // sort out red
        // wait until color detected
        if((sort_sensor->get_hue()>300) || (sort_sensor->get_hue()<60)){ // if red detected
            store_current_intake_state();
            intake_state = SORT;
            // wait a bit
            pros::delay(250);
            // continue previous state
            retrieve_previous_intake_state();
        }
    }
}

void IntakeSubsystem::get_alliance_pot_selection(){
    if(alliance_pot->get_value()>2000){
        alliance_color = 1; // RED
    } else{
        alliance_color = 2; // BLUE
    }
}

void IntakeSubsystem::sort_on(){
    colorsort_on = true;
}

void IntakeSubsystem::sort_off(){
    colorsort_on = false;
}

void IntakeSubsystem::set_alliance_red(){
    alliance_color = 1;
}

void IntakeSubsystem::set_alliance_blue(){
    alliance_color = 2;
}

int IntakeSubsystem::get_alliance_color(){
    return alliance_color;
}
