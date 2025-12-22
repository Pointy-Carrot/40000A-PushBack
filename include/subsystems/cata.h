#pragma once
#include "pros/motors.h"
#include "pros/motors.hpp"
#include "pros/adi.hpp"
#include "subsystems/pneumatics.h"

enum CataState {LONGGOAL, MIDGOAL, DOWN, HALF};

class CataSubsystem {
    private:
        
        float down_position;
        float long_goal_position;
        float midgoal_position;
        float half_position;
        int num_times_called = 0;
    public:

        pros::Motor* cata;
        pros::adi::Potentiometer* cata_pot;
        PneumaticsSubsystem* gate;
        PneumaticsSubsystem* midgoal_switch;

        /**
         * @brief Cata Constructor
         * 
         * @param cata cata motor
         * @param cata_pot cata potentiometer
         * @param gate gate piston
         * @param midgoal_switch midgoal switch piston
         */
        CataSubsystem(pros::Motor* cata, pros::adi::Potentiometer* cata_pot, PneumaticsSubsystem* gate, PneumaticsSubsystem* midgoal_switch);

        /**
         * @brief Set the Down Position of the cata
         * 
         * @param position down position
         */
        void setDownPosition(float position);

        /**
         * @brief Set the Up Position of the cata
         * 
         * @param position up position
         */
        void setLongGoalPosition(float position);

        /**
         * @brief Set the Midgoal Position of the cata
         * 
         * @param position midgoal position
         */
        void setMidgoalPosition(float position);

        /**
         * @brief Set the Halfway Up Position of the cata
         * 
         * @param position halfway up position
         */
        void setHalfPosition(float position);

        /**
         * @brief score into the long tube
         * 
         */
        void score_long();

        /**
         * @brief score into the mid tube
         * 
         */
        void score_mid();

        /**
         * @brief score 3 blocks in the tube
         * 
         */
        void score_half();

        /**
         * @brief reset the cata to the loading position
         * 
         */
        void down();

        /**
         * @brief spin the cata at a specified voltage
         * 
         * @param voltage voltage
         */
        void move(int voltage);

        /**
         * @brief Set the brake mode of the cata
         * 
         * @param brake_mode brake mode
         */
        void set_brake_mode(pros::motor_brake_mode_e brake_mode);

        /**
         * @brief stop the cata
         * 
         */
        void brake();

        /**
         * @brief stops the cata at the bottom of its range of motion for driver control
         * 
         */
        void driver_bottom_limit();

        /**
         * @brief stops the cata at the top of its range of motion for driver control
         * 
         */
        void driver_top_limit();

        /**
         * @brief checks to see if the cata is halfway up or more so that the intake can continue
         * 
         * @return true 
         * @return false 
         */
        bool is_halfway_up();

        /**
         * @brief move the cata to a position
         * 
         * @param position up, down, midgoal, halfway, custom float
         */
        void move_to(float position);

        /**
         * @brief puts the midgoal mech into the long goal scoring position
         * 
         */
        void midgoal_mech_up();

        /**
         * @brief puts the midgoal mech into the midgoal position
         * 
         */
        void midgoal_mech_down();

        /**
         * @brief toggle the midgoal mech
         * 
         */
        void toggle_midgoal_mech();

        /**
         * @brief get the current position of the midgoal
         * 
         */
        bool get_midgoal_status();

        /**
         * @brief Get the up position
         * 
         * @return float 
         */
        float get_long_goal_position();

        /**
         * @brief Get the down position
         * 
         * @return float 
         */
        float get_down_position();

        /**
         * @brief Get the midgoal position
         * 
         * @return float 
         */
        float get_midgoal_position();

        /**
         * @brief Get the half position
         * 
         * @return float 
         */
        float get_half_position();
};

extern CataState cata_position;
extern CataState prev_cata_position;