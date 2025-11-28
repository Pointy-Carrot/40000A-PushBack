#pragma once
#include "subsystems/intake.h"

extern bool midgoal;
extern bool driver_controlled_cata;
extern bool slow_cata;
extern bool colorsort_on;

/**
 * @brief automate the process of intaking while scoring long to prevent jamming
 * 
 */
void intake_while_scoring_long();

/**
 * @brief automate the process of intaking while scoring mid to prevent jamming
 * 
 */
void intake_while_scoring_mid();

/**
 * @brief primary task for controlling all scoring subsystems
 * 
 */
void scoring_system_controller();

/**
 * @brief Set the alliance color for color sorting
 * 
 */
void set_alliance();

extern Color alliance_color;