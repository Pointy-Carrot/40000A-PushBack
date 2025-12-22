#pragma once

#include "pros/motors.hpp"
#include "pros/optical.hpp"
#include "pros/adi.hpp"

enum Color {RED, BLUE, NONE};
enum IntakeState {INTAKE, OUTTAKE, SORT, STOP};

class IntakeSubsystem {
    public:
        pros::Motor* intake;
        pros::Optical* sort_sensor;
        pros::adi::Potentiometer* alliance_pot;
        int alliance_color = 2;
        int volts;
        int prev_volts;
        bool sorting = false;

        /**
         * @brief intake constructor
         * 
         * @param intake intake motor
         * @param sort_sensor color sort optical sensor
         */
        IntakeSubsystem(pros::Motor* intake, pros::Optical* sort_sensor, pros::adi::Potentiometer* alliance_pot);

        /**
         * @brief spin the intake at a specified voltage
         * 
         * @param voltage voltage
         */
        void move(int voltage);

        /**
         * @brief helper function for move
         * 
         * @param volts voltage
         */
        void move_velo(int volts);

        /**
         * @brief Set the brake mode of the intake
         * 
         * @param brake_mode brake mode
         */
        void set_brake_mode(pros::motor_brake_mode_e brake_mode);

        /**
         * @brief stop the intake
         * 
         */
        void brake();

        /**
         * @brief sort a certain color of blocks depending on the alliance specified
         * 
         * @param alliance_color What alliance you are on (1->RED / 2->BLUE)
         */
        void sort(int alliance_color);

        /**
         * @brief all control for the intake subsystem
         * 
         */
        void intake_control();

        /**
         * @brief Get the alliance color
         * 
         * @return int (1->RED / 2->BLUE)
         */
        int get_alliance_color();

        /**
         * @brief turn on color sort
         * 
         */
        void sort_on();

        /**
         * @brief turn off color sort
         * 
         */
        void sort_off();

        /**
         * @brief Set the alliance color to red
         * 
         */
        void set_alliance_red();

        /**
         * @brief Set the alliance color to blue
         * 
         */
        void set_alliance_blue();

        /**
         * @brief Get the alliance potentiometer selection
         * 
         */
        void get_alliance_pot_selection();
};

extern IntakeState intake_state;
