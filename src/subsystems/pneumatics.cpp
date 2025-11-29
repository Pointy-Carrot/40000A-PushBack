#include "subsystems/pneumatics.h"
#include "initialization/pneumatics_initialization.h"
#include "pros/adi.hpp"

PneumaticsSubsystem::PneumaticsSubsystem(pros::adi::Pneumatics* piston) 
    : piston(piston) {};

void PneumaticsSubsystem::extend(){
    piston->extend();
}

void PneumaticsSubsystem::retract(){
    piston->retract();
}

void PneumaticsSubsystem::toggle(){
    piston->toggle();
}

bool PneumaticsSubsystem::is_extended(){
    return piston->is_extended();
}

void PneumaticsSubsystem::set_value(int value){
    piston->set_value(value);
}


PneumaticsSubsystem wing(&wing_piston);
PneumaticsSubsystem loader(&loader_piston);
PneumaticsSubsystem gate(&gate_piston);
PneumaticsSubsystem midgoal_switch(&midgoal_piston);