#include "subsystems/intake.h"
#include "pros/adi.hpp"
#include "pros/optical.hpp"
#include "subsystems/scoring_system.h"

IntakeState intake_state = STOP;

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

void IntakeSubsystem::sort(int alliance_color){
    // wait until object detected
    if(sort_sensor->get_proximity()<100){
    // optical sensors detect red better than blue, so we check for red detected and not
    // red detected instead of red detected and blue detected
    if(alliance_color == 1){
        // sort out blue
        // wait until color detected
        if((sort_sensor->get_hue() < 270) && (sort_sensor->get_hue() > 180)){ // if not red detected
            std::cout<<"BLUE DETECTED"<<std::endl;
            sorting = true;
            prev_volts = volts;
            move_velo(-127);
            // wait a bit
            pros::delay(625);
            // continue previous state
            move_velo(prev_volts);
            sorting = false;
        }
    } else if(alliance_color == 2){
        // sort out red
        // wait until color detected
        if((sort_sensor->get_hue()>300) || (sort_sensor->get_hue()<60)){ // if red detected
            std::cout<<"RED DETECTED"<<std::endl;
            sorting = true;
            prev_volts = volts;
            move_velo(-127);
            // wait a bit
            pros::delay(625);
            // continue previous state
            move_velo(volts);
            sorting = false;
        }
    }
}
}

void IntakeSubsystem::get_alliance_pot_selection(){
    if(alliance_pot->get_value()>900){
        alliance_color = 1; // RED
    } else{
        alliance_color = 2; // RED
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
