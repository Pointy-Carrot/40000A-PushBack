#include "initialization/sensor_initialization.h"
#include "pros/adi.hpp"
#include "pros/distance.hpp"
#include "pros/imu.hpp"
#include "pros/optical.hpp"
#include "pros/rotation.hpp"

pros::Distance left_dist(16);
pros::Distance right_dist(2);

pros::Optical colorsort_optical(20);

pros::adi::Potentiometer cata_pot('E');
pros::adi::Potentiometer alliance_selector_pot('D');

pros::Rotation horiz_tracker(-17);
pros::Rotation vert_tracker(19);

pros::Imu imu(4);