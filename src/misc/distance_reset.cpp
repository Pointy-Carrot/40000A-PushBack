#include "misc/distance_reset.h"
#include "initialization/robot_init.h"



DistanceReset::DistanceReset(pros::Distance* left_sensor, double left_offset, pros::Distance* right_sensor, double right_offset)
    : left_sensor(left_sensor), left_offset(left_offset), right_sensor(right_sensor), right_offset(right_offset) {};

double DistanceReset::mm_to_in(double mm){
    return mm * 0.039;
}

void DistanceReset::update_position(Sensor sensor_selection, Direction direction){
    float sample1;
    float sample2;
    float sample3;
    float avg;
    if(sensor_selection == Sensor::LEFT){
        switch(direction){
            case Direction::UP:
                sample1 = 78 - mm_to_in(left_sensor->get_distance()) - left_offset;
                pros::delay(10);
                sample2 = 78 - mm_to_in(left_sensor->get_distance()) - left_offset;
                pros::delay(10);
                sample3 = 78 - mm_to_in(left_sensor->get_distance()) - left_offset;

                avg = (sample1+sample2+sample3)/3;
                chassis.setPose(avg, chassis.getPose().y, chassis.getPose().theta);
                break;
            case Direction::DOWN:
                sample1 = -78 + mm_to_in(left_sensor->get_distance()) + left_offset;
                pros::delay(10);
                sample2 = -78 + mm_to_in(left_sensor->get_distance()) + left_offset;
                pros::delay(10);
                sample3 = -78 + mm_to_in(left_sensor->get_distance()) + left_offset;

                avg = (sample1+sample2+sample3)/3;
                chassis.setPose(avg, chassis.getPose().y, chassis.getPose().theta);
                break;
            case Direction::LEFT:
                sample1 = 78 - mm_to_in(left_sensor->get_distance()) - left_offset;
                pros::delay(10);
                sample2 = 78 - mm_to_in(left_sensor->get_distance()) - left_offset;
                pros::delay(10);
                sample3 = 78 - mm_to_in(left_sensor->get_distance()) - left_offset;

                avg = (sample1+sample2+sample3)/3;
                chassis.setPose(chassis.getPose().x, avg, chassis.getPose().theta);
                break;
            case Direction::RIGHT:
                sample1 = -78 + mm_to_in(left_sensor->get_distance()) + left_offset;
                pros::delay(10);
                sample2 = -78 + mm_to_in(left_sensor->get_distance()) + left_offset;
                pros::delay(10);
                sample3 = -78 + mm_to_in(left_sensor->get_distance()) + left_offset;

                avg = (sample1+sample2+sample3)/3;
                chassis.setPose(chassis.getPose().x, avg, chassis.getPose().theta);
                break;
        }
    } else{
        switch(direction){
            case Direction::UP:
                sample1 = 58 - mm_to_in(right_sensor->get_distance()) - right_offset;
                pros::delay(10);
                sample2 = 58 - mm_to_in(right_sensor->get_distance()) - right_offset;
                pros::delay(10);
                sample3 = 58 - mm_to_in(right_sensor->get_distance()) - right_offset;

                avg = (sample1+sample2+sample3)/3;
                chassis.setPose(avg, chassis.getPose().y, chassis.getPose().theta);
                break;
            case Direction::DOWN:
                sample1 = -58 + mm_to_in(right_sensor->get_distance()) + right_offset;
                pros::delay(10);
                sample2 = -58 + mm_to_in(right_sensor->get_distance()) + right_offset;
                pros::delay(10);
                sample3 = -58 + mm_to_in(right_sensor->get_distance()) + right_offset;

                avg = (sample1+sample2+sample3)/3;
                chassis.setPose(avg, chassis.getPose().y, chassis.getPose().theta);
                break;
            case Direction::LEFT:
                sample1 = 58 - mm_to_in(right_sensor->get_distance()) - right_offset;
                pros::delay(10);
                sample2 = 58 - mm_to_in(right_sensor->get_distance()) - right_offset;
                pros::delay(10);
                sample3 = 58 - mm_to_in(right_sensor->get_distance()) - right_offset;

                avg = (sample1+sample2+sample3)/3;
                chassis.setPose(chassis.getPose().x, avg, chassis.getPose().theta);
                break;
            case Direction::RIGHT:
                sample1 = -58 + mm_to_in(right_sensor->get_distance()) + right_offset;
                pros::delay(10);
                sample2 = -58 + mm_to_in(right_sensor->get_distance()) + right_offset;
                pros::delay(10);
                sample3 = -58 + mm_to_in(right_sensor->get_distance()) + right_offset;

                avg = (sample1+sample2+sample3)/3;
                chassis.setPose(chassis.getPose().x, avg, chassis.getPose().theta);
                break;
        }
    }
}