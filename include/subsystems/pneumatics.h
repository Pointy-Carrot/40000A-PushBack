#pragma once

#include "pros/adi.hpp"

class PneumaticsSubsystem{
    public:

        pros::adi::Pneumatics* piston;

        /**
         * @brief Pneumatics Constructor
         * 
         * @param piston 
         */
        PneumaticsSubsystem(pros::adi::Pneumatics* piston);

        /**
         * @brief extends the piston, if not already extended
         * 
         */
        void extend();

        /**
         * @brief retracts the piston, if not already retracted
         * 
         */
        void retract();

        /**
         * @brief get the value of the piston
         * 
         * @return true if extended
         * @return false if retracted
         */
        bool is_extended();

        /**
         * @brief set the value of the piston
         * 
         * @param value 1->extend / 2->retract
         */
        void set_value(int value);

        /**
         * @brief toggles the piston between extended and retracted
         * 
         */
        void toggle();
};
