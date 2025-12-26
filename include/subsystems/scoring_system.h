#pragma once
#include "subsystems/intake.h"

extern bool midgoal;
extern bool manual_cata_control;
extern bool slow_cata;
extern bool colorsort_on;

/**
 * @brief automate the process of intaking while scoring long to prevent jamming
 * 
 * @param time time in ms to wait for additional blocks to enter tube
 */
void intake_while_scoring_long(int time);

/**
 * @brief automate the process of intaking while scoring mid to prevent jamming
 * 
 * @param time time in ms to wait for additional blocks to enter tube
 */
void intake_while_scoring_mid(int time);

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

/**
 * @brief driver odom lift control
 * 
 */
void driver_odom_lift();

/**
 * @brief score 7 low using cata to push blocks out of tube
 * 
 */
void score_many_low();

extern Color alliance_color;