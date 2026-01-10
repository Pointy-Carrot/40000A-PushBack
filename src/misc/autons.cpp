#include "lemlib/api.hpp" // IWYU pragma: keep
#include "misc/autons.h"
#include "initialization/robot_init.h"
#include "subsystems/scoring_system.h"

void left_sawp(){
    // initialization
    chassis.setPose(-47.5, 16, 0);
    intake.get_alliance_pot_selection();
    intake.sort_on();
    cata.down(127);
    wing.extend();
    // clear top left loader
    chassis.moveToPoint(-48, 48, 1000);
    loader.extend();
    chassis.turnToHeading(270, 500);
    chassis.moveToPoint(-90, 48, 1150, {.maxSpeed = 50});
    intake.move(127);
    // score bottom long goal
    chassis.moveToPoint(0, 48, 1000, {.forwards = false, .maxSpeed = 80});
    chassis.moveToPoint(0, 48, 500, {.forwards = false, .maxSpeed = 15});
    pros::delay(750);
    intake.brake();
    cata.score_long(127);
    pros::delay(500);
    cata.down(127);
    loader.retract();
    chassis.waitUntilDone();
    chassis.setPose(-30, 48, chassis.getPose().theta);
    // intake top left pile
    chassis.swingToPoint(-16, 20, lemlib::DriveSide::LEFT, 750);
    chassis.waitUntilDone();
    intake.move(127);
    chassis.moveToPoint(-16, 20, 1000);
    pros::delay(450);
    loader.extend();
    chassis.moveToPoint(-24, 16, 500);
    // score top mid goal
    chassis.turnToPoint(0, -8, 500, {.forwards = false});
    chassis.moveToPoint(0, -8, 1000, {.forwards = false, .maxSpeed = 60});
    cata.midgoal_mech_down();
    chassis.waitUntilDone();
    intake.brake();
    cata.score_mid(70);
    loader.retract();
    pros::delay(1000);
    // intake bottom left pile
    chassis.moveToPoint(-24, -24, 2000);
    cata.down(127);
    cata.midgoal_mech_up();
    loader.retract();
    pros::delay(250);
    intake.move(127);
    pros::delay(900);
    loader.extend();
    // score bottom mid goal
    chassis.turnToPoint(0, -8, 500, {.forwards = false});
    chassis.moveToPoint(0, -8, 1000, {.forwards = false, .maxSpeed = 45});
    chassis.waitUntilDone();
    chassis.turnToHeading(225, 500);
    pros::delay(250);
    intake.move(-127);
    loader.retract();
};

void right_sawp(){
    // initialization
    chassis.setPose(-47.5, -16, 180);
    intake.get_alliance_pot_selection();
    intake.sort_off();
    cata.down(127);
    wing.extend();
    // clear bottom left loader
    chassis.moveToPoint(-48, -48, 1000);
    loader.extend();
    chassis.turnToHeading(270, 500);
    chassis.moveToPoint(-90, -48, 1150, {.maxSpeed = 50});
    intake.move(127);
    // score bottom long goal
    chassis.moveToPoint(0, -48, 1000, {.forwards = false, .maxSpeed = 80});
    chassis.moveToPoint(0, -48, 500, {.forwards = false, .maxSpeed = 15});
    pros::delay(1000);
    intake.brake();
    cata.score_long(127);
    pros::delay(500);
    cata.down(127);
    loader.retract();
    chassis.waitUntilDone(); 
    chassis.setPose(-30, -48, chassis.getPose().theta);
    // intake bottom left pile
    chassis.swingToPoint(-24, -24, lemlib::DriveSide::RIGHT, 750);
    chassis.waitUntilDone();
    intake.move(127);
    chassis.moveToPoint(-24, -24, 1000);
    pros::delay(350);
    loader.extend();
    // score bottom mid goal
    chassis.turnToPoint(-4, 0, 750, {.forwards = false});
    chassis.moveToPoint(-4, 0, 1000, {.forwards = false, .maxSpeed = 60});
    chassis.waitUntilDone();
    intake.move(-127);
    chassis.turnToHeading(225, 500);
    pros::delay(1250);
    // intake top left pile
    chassis.moveToPoint(-25, 30, 1500);
    loader.retract();
    pros::delay(250);
    intake.move(127);
    pros::delay(1000);
    loader.extend();
    // score top mid goal
    chassis.turnToPoint(0, 8, 500, {.forwards = false});
    chassis.moveToPoint(0, 8, 750, {.forwards = false, .maxSpeed = 60});
    cata.midgoal_mech_down();
    chassis.waitUntilDone();
    pros::delay(1000);
    cata.score_mid(65);
    loader.retract();
};

void left_7_ball_split(){
    // initialization
    chassis.setPose(-47, 16, 90);
    intake.get_alliance_pot_selection();
    intake.sort_on();
    cata.down(127);
    wing.extend();
    // intake top left pile
    chassis.moveToPoint(-22, 22, 1000);
    pros::delay(500);
    loader.extend();
    // score top mid goal
    chassis.turnToPoint(0, 0, 500, {.forwards = false});
    chassis.moveToPoint(0, 0, 1000, {.forwards = false, .maxSpeed = 60});
    cata.midgoal_mech_down();
    chassis.moveToPoint(0, 0, 500, {.forwards = false, .maxSpeed = 15});
    cata.score_mid(60);
    pros::delay(1000);
    cata.down(127);
    chassis.waitUntilDone();
    chassis.setPose(-12, 12, chassis.getPose().theta);
    // clear top left loader
    chassis.moveToPoint(-46, 48, 1000);
    chassis.turnToHeading(270, 500);
    cata.midgoal_mech_up();
    chassis.waitUntilDone();
    dist_reset.update_position(Sensor::RIGHT, Direction::RIGHT);
    chassis.moveToPoint(-90, 48, 1000, {.maxSpeed = 60});
    // score top long goal
    chassis.moveToPoint(0, 48, 1000, {.forwards = false, .maxSpeed = 80});
    chassis.moveToPoint(0, 48, 500, {.forwards = false, .maxSpeed = 15});
    cata.score_long(127);
    pros::delay(500);
    cata.down(127);
    chassis.waitUntilDone();
    chassis.setPose(-30, 48, chassis.getPose().theta);
    dist_reset.update_position(Sensor::RIGHT, Direction::LEFT);
    // wing push
    chassis.moveToPoint(-36, 37, 1000);
    chassis.turnToPoint(-10, 37, 500, {.forwards = false});
    wing.retract();
    chassis.moveToPoint(-10, 37, 1000, {.forwards = false});
};

void right_7_ball_split(){
    // initialization
    chassis.setPose(-47, -16, 90);
    intake.get_alliance_pot_selection();
    intake.sort_on();
    cata.down(127);
    wing.extend();
    // intake bottom left pile
    chassis.moveToPoint(-22, -22, 1000);
    pros::delay(500);
    loader.extend();
    // score bottom mid goal
    chassis.turnToPoint(0, 0, 500, {.forwards = false});
    chassis.moveToPoint(0, 0, 1000, {.forwards = false, .maxSpeed = 60});
    chassis.moveToPoint(0, 0, 500, {.forwards = false, .maxSpeed = 15});
    intake.move(-127);
    loader.retract();
    chassis.waitUntilDone();
    pros::delay(1000);
    chassis.setPose(-10, -10, chassis.getPose().theta);
    // clear bottom left loader
    chassis.moveToPoint(-46, -48, 1000, {.forwards = false});
    chassis.turnToHeading(270, 750);
    loader.extend();
    intake.brake();
    chassis.waitUntilDone();
    dist_reset.update_position(Sensor::LEFT, Direction::LEFT);
    chassis.moveToPoint(-90, -48, 1000, {.maxSpeed = 60});
    intake.move(127);
    // score bottom long goal
    chassis.moveToPoint(0, -48, 1000, {.maxSpeed = 80});
    chassis.moveToPoint(0, -48, 500, {.maxSpeed = 15});
    cata.score_long(127);
    pros::delay(500);
    cata.down(127);
    chassis.waitUntilDone();
    chassis.setPose(-30, -48, chassis.getPose().theta);
    dist_reset.update_position(Sensor::LEFT, Direction::LEFT);
    // wing push
    chassis.moveToPoint(-36, -37, 1000);
    chassis.turnToPoint(-10, -37, 750);
    wing.retract();
    chassis.moveToPoint(-10, -37, 1000);
};

void left_9_ball_split(){
    // initialization
    chassis.setPose(-47, 16, 90);
    intake.get_alliance_pot_selection();
    intake.sort_on();
    cata.down(127);
    wing.extend();
    // intake top left pile
    chassis.moveToPoint(-22, 22, 1000);
    intake.move(127);
    pros::delay(500);
    loader.extend();
    // intake top line blocks
    chassis.moveToPoint(-9, 42, 1000);
    pros::delay(250);
    loader.retract();
    // score top mid goal
    chassis.moveToPoint(-24, 24, 1000, {.forwards = false});
    chassis.turnToPoint(0, 0, 500, {.forwards = false});
    chassis.moveToPoint(0, 0, 1000, {.forwards = false, .maxSpeed = 60});
    cata.midgoal_mech_down();
    chassis.moveToPoint(0, 0, 500, {.forwards = false, .maxSpeed = 15});
    cata.score_mid(60);
    pros::delay(1000);
    cata.down(127);
    chassis.waitUntilDone();
    chassis.setPose(-12, 12, chassis.getPose().theta);
    // clear top left loader
    chassis.moveToPoint(-46, 48, 1000);
    chassis.turnToHeading(270, 500);
    cata.midgoal_mech_up();
    loader.extend();
    chassis.waitUntilDone();
    dist_reset.update_position(Sensor::RIGHT, Direction::LEFT);
    chassis.moveToPoint(-90, 48, 1000, {.maxSpeed = 60});
    // score top long goal
    chassis.moveToPoint(0, 48, 1000, {.forwards = false, .maxSpeed = 80});
    chassis.moveToPoint(0, 48, 500, {.forwards = false, .maxSpeed = 15});
    loader.retract();
    cata.score_long(127);
    pros::delay(500);
    cata.down(127);
};

void right_9_ball_split(){
    // initialization
    chassis.setPose(-47, -16, 90);
    intake.get_alliance_pot_selection();
    intake.sort_on();
    cata.down(127);
    wing.extend();
    // intake bottom left pile
    chassis.moveToPoint(-22, -22, 1000);
    intake.move(127);
    pros::delay(500);
    loader.extend();
    // intake bottom line blocks
    chassis.moveToPoint(-9, -42, 1000);
    pros::delay(250);
    loader.retract();
    // score low mid goal
    chassis.moveToPoint(-24, -24, 1000, {.forwards = false});
    chassis.turnToPoint(0, 0, 500, {.forwards = false});
    intake.brake();
    chassis.moveToPoint(0, 0, 1000, {.forwards = false, .maxSpeed = 60});
    chassis.moveToPoint(0, 0, 500, {.forwards = false, .maxSpeed = 15});
    intake.move(-127);
    chassis.waitUntilDone();
    pros::delay(1000);
    chassis.setPose(-10, -10, chassis.getPose().theta);
    // clear bottom left loader
    chassis.moveToPoint(-46, -48, 1000, {.forwards = false});
    pros::delay(500);
    intake.brake();
    chassis.turnToHeading(270, 750);
    loader.extend();
    chassis.waitUntilDone();
    dist_reset.update_position(Sensor::LEFT, Direction::LEFT);
    chassis.moveToPoint(-90, -48, 1000, {.maxSpeed = 60});
    // score bottom long goal
    chassis.moveToPoint(0, -48, 1000, {.maxSpeed = 80});
    chassis.moveToPoint(0, -48, 500, {.maxSpeed = 15});
    loader.retract();
    cata.score_long(127);
    pros::delay(500);
    cata.down(127);
};

void prog_skills(){
    // initialization
    chassis.setPose(-63, -17, 0);
    intake.set_alliance_red();
    intake.sort_off();
    cata.down(127);
    wing.extend();
    // clear red park zone
    chassis.moveToPoint(-63, -30, 1000, {.forwards = false});
    odom_lift.extend();
    chassis.moveToPoint(-63, 32, 4000, {.maxSpeed = 78});
    intake.move(127);
    pros::delay(1500);
    odom_lift.retract();
    chassis.moveToPoint(-40, 48, 1000);
    // position reset
    chassis.turnToHeading(180, 750);
    chassis.waitUntilDone();
    chassis.tank(-60, -60);
    pros::delay(1000);
    chassis.tank(0, 0);
    chassis.setPose(-36, 63, chassis.getPose().theta);
    // pick up single red from upper left cluster
    chassis.moveToPoint(-34, 12, 1000);
    chassis.turnToPoint(-20, 24, 750);
    chassis.moveToPoint(-20, 24, 250);
    chassis.turnToPoint(0, 0, 750, {.forwards = false});


    pros::delay(1000000);
    chassis.moveToPoint(-36, 12, 1000, {.forwards = false});
    chassis.turnToPoint(-14, 14, 500);
    chassis.moveToPoint(-14, 14, 1000);
    chassis.turnToPoint(0, 0, 500, {.forwards = false});
    chassis.moveToPoint(0, 0, 750, {.forwards = false, .maxSpeed = 50});
    cata.midgoal_mech_down();

    pros::delay(100000);
    
}

void ramsete_test(){
    // ramchassis.follow(path_one);
    // ramchassis.follow(path_two);
}
