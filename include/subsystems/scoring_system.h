#pragma once
#include "subsystems/intake.h"

extern bool midgoal;
extern bool manual_cata_control;
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
 * @brief primary task for controlling cata
 * 
 */
void cata_controller();

/**
 * @brief primary task for controlling intake
 * 
 */
void intake_controller();

/**
 * @brief Set the alliance color for color sorting
 * 
 */
void set_alliance();

/**
 * @brief driver intake control
 * 
 */
void driver_intake();

/**
 * @brief driver cata control
 * 
 */
void driver_cata();

/**
 * @brief driver wing control
 * 
 */
void driver_wing();

/**
 * @brief driver loader control
 * 
 */
void driver_loader();


extern Color alliance_color;