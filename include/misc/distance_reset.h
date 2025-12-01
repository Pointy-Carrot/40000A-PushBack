#pragma once

#include "pros/distance.hpp"

enum class Sensor {LEFT, RIGHT};

enum class Direction {UP, DOWN, LEFT, RIGHT};

class DistanceReset {
    private:

        double left_offset;
        double right_offset;
    
    public:

        pros::Distance* left_sensor;
        pros::Distance* right_sensor;


        /**
         * @brief Distance Reset Constructor 
         * 
         */
        DistanceReset(pros::Distance* left_sensor, double left_offset, pros::Distance* right_sensor, double right_offset);


        void update_position(Sensor sensor_selection, Direction direction);

        double mm_to_in(double mm);
};

extern DistanceReset dist_reset;