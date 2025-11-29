#pragma once

#include "pros/distance.hpp"

enum class Sensor {LEFT, RIGHT};

enum class Direction {UP, DOWN, LEFT, RIGHT};

class DistanceReset {
    private:

        float left_offset;
        float right_offset;
    
    public:

        pros::Distance* left_sensor;
        pros::Distance* right_sensor;


        /**
         * @brief Distance Reset Constructor 
         * 
         */
        DistanceReset(pros::Distance* left_sensor, float left_offset, pros::Distance* right_sensor, float right_offset);


        void update_position(Sensor sensor_selection, Direction direction);

        float mm_to_in(float mm);
};

extern DistanceReset dist_reset;