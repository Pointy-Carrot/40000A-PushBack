#include "subsystems/cata.h"
#include "pros/adi.hpp"
#include "pros/motors.h"
#include "subsystems/pneumatics.h"

CataState cata_position = HALF;
CataState prev_cata_position = HALF;

CataSubsystem::CataSubsystem(pros::Motor* cata, pros::adi::Potentiometer* cata_pot, PneumaticsSubsystem* midgoal_switch) 
    : cata(cata), cata_pot(cata_pot), midgoal_switch(midgoal_switch) {};

void CataSubsystem::setDownPosition(float position){
    down_position = position;
    // std::cout<<down_position<<std::endl;
}

void CataSubsystem::setLongGoalPosition(float position){
    long_goal_position = position;
    // std::cout<<long_goal_position<<std::endl;
}

void CataSubsystem::setMidgoalPosition(float position){
    midgoal_position = position;
    // std::cout<<midgoal_position<<std::endl;
}

void CataSubsystem::setHalfPosition(float position){
    half_position = position;
    // std::cout<<half_position<<std::endl;
}

void CataSubsystem::setLoadPosition(float position){
    load_position = position;
    // std::cout<<load_position<<std::endl;
}

void CataSubsystem::score_long(int volts){
    cata_position = LONGGOAL;
    voltage = volts;
}

void CataSubsystem::score_mid(int volts){
    cata_position = MIDGOAL;
    voltage = volts;
}

void CataSubsystem::score_half(int volts){
    cata_position = HALF;
    voltage = volts;
}

void CataSubsystem::down(int volts){
    cata_position = DOWN;
    voltage = volts;
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
    if(cata_pot->get_value() <= half_position){
        return true;
    } else{
        return false;
    }
}

void CataSubsystem::move_to(float position){
    if(cata_position == DOWN){
    if(position < cata_pot->get_value()){
        cata->move(abs(voltage));
        // std::cout<<"UP"<<std::endl;
    } else if(position > cata_pot->get_value()){
        cata->move(-abs(voltage));
        // std::cout<<"DOWN"<<std::endl;
    } else{
        cata->brake();
    }
    } else{
        if(position < cata_pot->get_value()){
            cata->move(abs(voltage));
        } else{
            cata->brake();
        }
    }
}

void CataSubsystem::midgoal_mech_up(){
    midgoal_switch->extend();
}

void CataSubsystem::midgoal_mech_down(){
    midgoal_switch->retract();
}

void CataSubsystem::toggle_midgoal_mech(){
    midgoal_switch->toggle();
}

bool CataSubsystem::get_midgoal_status(){
    return midgoal_switch->is_extended();
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

float CataSubsystem::get_load_position(){
    return load_position;
}

float CataSubsystem::get_position(){
    return cata_pot->get_value();
}