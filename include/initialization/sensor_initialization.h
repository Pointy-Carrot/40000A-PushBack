#pragma once

#include "pros/adi.hpp"
#include "pros/distance.hpp"
#include "pros/imu.hpp"
#include "pros/optical.hpp"
#include "pros/rotation.hpp"

extern pros::Distance front_dist;
extern pros::Distance back_dist;
extern pros::Distance left_dist;
extern pros::Distance right_dist;

extern pros::Optical colorsort_optical;

extern pros::adi::Potentiometer cata_pot;
extern pros::adi::Potentiometer alliance_selector_pot;

extern pros::Rotation horiz_tracker;
extern pros::Rotation vert_tracker;

extern pros::Imu imu;