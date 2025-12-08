#include "initialization/sensor_initialization.h"
#include "pros/adi.hpp"
#include "pros/distance.hpp"
#include "pros/imu.hpp"
#include "pros/optical.hpp"
#include "pros/rotation.hpp"

pros::Distance front_dist(10);
pros::Distance back_dist(11);
pros::Distance left_dist(12);
pros::Distance right_dist(13);

pros::Optical colorsort_optical(14);

pros::adi::Potentiometer cata_pot('D');
pros::adi::Potentiometer alliance_selector_pot('E');

pros::Rotation horiz_tracker(15);
pros::Rotation vert_tracker(16);

pros::Imu imu(17);