#include "subsystems/cata.h"
#include "initialization/motor_initialization.h"
#include "initialization/sensor_initialization.h"
#include "lemlib/pid.hpp"
#include "pros/adi.hpp"
#include "pros/motors.h"
#include "subsystems/pneumatics.h"


CataSubsystem::CataSubsystem(pros::Motor* cata, pros::adi::Potentiometer* cata_pot, PneumaticsSubsystem* gate, PneumaticsSubsystem* midgoal_switch, float kP, float kI, float kD) 
    : cata(cata), cata_pot(cata_pot), gate(gate), midgoal_switch(midgoal_switch), cata_pid(kP, kI, kD) {};

void CataSubsystem::setDownPosition(float position){
    down_position = position;
}

void CataSubsystem::setLongGoalPosition(float position){
    long_goal_position = position;
}

void CataSubsystem::setMidgoalPosition(float position){
    midgoal_position = position;
}

void CataSubsystem::setHalfPosition(float position){
    half_position = position;
}

void CataSubsystem::score_long(){
    cata_position = LONGGOAL;
}

void CataSubsystem::score_mid(){
    cata_position = MIDGOAL;
}

void CataSubsystem::score_half(){
    cata_position = HALF;
}

void CataSubsystem::down(){
    cata_position = DOWN;
}

void CataSubsystem::move(int voltage){
    cata->move(voltage);
}

void CataSubsystem::set_brake_mode(pros::motor_brake_mode_e brake_mode){
    cata->set_brake_mode(brake_mode);
}

void CataSubsystem::brake(){
    cata->brake();
}

bool CataSubsystem::is_halfway_up(){
    if(cata_pot->get_value() >= half_position){
        return true;
    } else{
        return false;
    }
}

void CataSubsystem::move_to(float position){
    cata->move(cata_pid.update(position - cata_pot->get_value()));
}

void CataSubsystem::midgoal_mech_up(){
    midgoal_switch->extend();
}

void CataSubsystem::midgoal_mech_down(){
    midgoal_switch->retract();
}

float CataSubsystem::get_long_goal_position(){
    return long_goal_position;
}

float CataSubsystem::get_down_position(){
    return down_position;
}

float CataSubsystem::get_midgoal_position(){
    return midgoal_position;
}

float CataSubsystem::get_half_position(){
    return half_position;
}
