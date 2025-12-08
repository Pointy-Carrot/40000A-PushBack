#include "subsystems/intake.h"
#include "initialization/motor_initialization.h"
#include "initialization/sensor_initialization.h"
#include "pros/adi.hpp"
#include "pros/optical.hpp"
#include "subsystems/scoring_system.h"



IntakeSubsystem::IntakeSubsystem(pros::Motor* intake, pros::Motor* sorter, pros::Optical* sort_sensor, pros::adi::Potentiometer* alliance_pot)
    : intake(intake), sorter(sorter), sort_sensor(sort_sensor), alliance_pot(alliance_pot) {};

void IntakeSubsystem::move(int voltage){
    volts = voltage;
    if(volts > 0){ // if voltage positive, intake
        intake_state = INTAKE;
    } else if(volts < 0){ // if voltage negative, outtake
        intake_state = OUTTAKE;
    } else if(volts == 0){ // if voltage equals zero, stop
        intake_state = STOP;
    }
}

void IntakeSubsystem::set_brake_mode(pros::motor_brake_mode_e brake_mode){
    intake->set_brake_mode(brake_mode);
    sorter->set_brake_mode(brake_mode);
}

void IntakeSubsystem::brake(){
    intake_state = STOP;
}

void IntakeSubsystem::store_current_intake_state(){
    switch(intake_state){
        case INTAKE:
            prev_intake_state = INTAKING;
            break;
        case OUTTAKE:
            prev_intake_state = OUTTAKING;
            break;
        case SORT:
            prev_intake_state = SORTING;
            break;
        case STOP:
            prev_intake_state = STOPPED;
            break;
    }
}

void IntakeSubsystem::retrieve_previous_intake_state(){
    switch(prev_intake_state){
        case INTAKING:
            intake_state = INTAKE;
            break;
        case OUTTAKING:
            intake_state = OUTTAKE;
            break;
        case SORTING:
            intake_state = SORT;
            break;
        case STOPPED:
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
