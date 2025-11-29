#include "misc/distance_reset.h"
#include "initialization/sensor_initialization.h"
#include "subsystems/chassis_config.h"



DistanceReset::DistanceReset(pros::Distance* left_sensor, float left_offset, pros::Distance* right_sensor, float right_offset)
    : left_sensor(left_sensor), left_offset(left_offset), right_sensor(right_sensor), right_offset(right_offset) {};

float DistanceReset::mm_to_in(float mm){
    return mm * 0.039;
}

void DistanceReset::update_position(Sensor sensor_selection, Direction direction){
    if(sensor_selection == Sensor::LEFT){
        switch(direction){
            case Direction::UP:
                chassis.setPose(-70 + mm_to_in(left_sensor->get_distance()) + left_offset, chassis.getPose().y, chassis.getPose().theta);
                break;
            case Direction::DOWN:
                chassis.setPose(70 - mm_to_in(left_sensor->get_distance()) - left_offset, chassis.getPose().y, chassis.getPose().theta);
                break;
            case Direction::LEFT:
                chassis.setPose(chassis.getPose().x, -70 + mm_to_in(left_sensor->get_distance()) + left_offset, chassis.getPose().theta);
                break;
            case Direction::RIGHT:
                chassis.setPose(chassis.getPose().x, 70 - mm_to_in(left_sensor->get_distance()) - left_offset, chassis.getPose().theta);
                break;
        }
    } else{
        switch(direction){
            case Direction::UP:
                chassis.setPose(70 - mm_to_in(right_sensor->get_distance()), chassis.getPose().y, chassis.getPose().theta);
                break;
            case Direction::DOWN:
                chassis.setPose(-70 + mm_to_in(right_sensor->get_distance()) + right_offset, chassis.getPose().y, chassis.getPose().theta);
                break;
            case Direction::LEFT:
                chassis.setPose(chassis.getPose().x, 70 - mm_to_in(right_sensor->get_distance()) - right_offset, chassis.getPose().theta);
                break;
            case Direction::RIGHT:
                chassis.setPose(chassis.getPose().x, -70 + mm_to_in(right_sensor->get_distance()) + right_offset, chassis.getPose().theta);
                break;
        }
    }
}






DistanceReset dist_reset(&left_dist, 6.3, &right_dist, 5.784);