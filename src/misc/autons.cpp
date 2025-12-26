#include "lemlib/api.hpp" // IWYU pragma: keep
#include "misc/autons.h"
#include "initialization/robot_init.h"
#include "subsystems/scoring_system.h"

void tuning_prog(){
    chassis.setPose(0, 0, 0);
    intake.get_alliance_pot_selection();
    intake.sort_off();
    cata.down(127);
    wing.extend();
    
    // chassis.turnToHeading(90, 100000);
    cata.score_long(127);
    intake.move(127);
    pros::delay(1500);
    cata.down(-30);
    intake.move(-127);
}

void left_sawp(){
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
    // intake bottom left pile
    chassis.moveToPoint(-22, 12, 1000);
    chassis.turnToPoint(-22, -22, 500);
    cata.midgoal_mech_up();
    chassis.moveToPoint(-22, -22, 1000);
    pros::delay(650);
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
    // clear top left loader
    chassis.moveToPoint(-26, -12, 1000, {.forwards = false});
    chassis.turnToPoint(-46, 48, 500);
    intake.brake();
    chassis.moveToPoint(-46, 48, 1000);
    intake.move(127);
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
void right_sawp(){
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
    // intake top left pile
    chassis.moveToPoint(-22, -12, 1000, {.forwards = false});
    chassis.turnToPoint(-22, 22, 500);
    intake.brake();
    chassis.moveToPoint(-22, 22, 1000);
    intake.move(127);
    pros::delay(650);
    loader.extend();
    // score top mid goal
    chassis.turnToPoint(0, 0, 500, {.forwards = false});
    chassis.moveToPoint(0, 0, 1000, {.forwards = false, .maxSpeed = 60});
    cata.midgoal_mech_down();
    chassis.moveToPoint(0, 0, 500, {.forwards = false, .maxSpeed = 15});
    cata.score_mid(60);
    pros::delay(1000);
    cata.down(127);
    loader.retract();
    chassis.waitUntilDone();
    chassis.setPose(-12, 12, chassis.getPose().theta);
    // clear bottom left loader
    chassis.moveToPoint(-26, 12, 1000);
    chassis.turnToPoint(-46, -48, 500);
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
void full_sawp(){
    // initialization
    chassis.setPose(-48, -17, 180);
    intake.get_alliance_pot_selection();
    intake.sort_on();
    cata.down(127);
    wing.extend();
    // clear bottom left loader
    chassis.moveToPoint(-48, -48, 1000);
    loader.extend();
    chassis.turnToHeading(270, 500);
    chassis.waitUntilDone();
    dist_reset.update_position(Sensor::LEFT, Direction::LEFT);
    chassis.moveToPoint(-90, -48, 1000, {.maxSpeed = 60});
    intake.move(127);
    // score bottom long goal
    chassis.moveToPoint(0, -48, 1000, {.forwards = false, .maxSpeed = 80});
    chassis.moveToPoint(0, -48, 500, {.forwards = false, .maxSpeed = 15});
    cata.score_long(127);
    pros::delay(500);
    cata.down(127);
    chassis.waitUntilDone();
    chassis.setPose(-30, -48, chassis.getPose().theta);
    dist_reset.update_position(Sensor::LEFT, Direction::LEFT);
    // intake bottom left pile
    chassis.moveToPoint(-22, -22, 1000);
    pros::delay(650);
    loader.extend();
    // intake top left pile
    chassis.moveToPoint(-22, 22, 1000);
    pros::delay(250);
    loader.retract();
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
    chassis.waitUntilDone();
    dist_reset.update_position(Sensor::RIGHT, Direction::LEFT);
    chassis.moveToPoint(-90, 48, 1000, {.maxSpeed = 60});
    // score top long goal
    chassis.moveToPoint(0, 48, 1000, {.maxSpeed = 80});
    chassis.moveToPoint(0, 48, 500, {.maxSpeed = 15});
    cata.score_long(127);
    pros::delay(500);
    cata.down(127);
};
void prog_skills(){
    // initialization
    chassis.setPose(-46, -9, 180);
    intake.set_alliance_red();
    intake.sort_on();
    cata.down(127);
    wing.extend();
    // intake bottom left pile
    chassis.moveToPoint(-46, -24, 1000);
    chassis.turnToPoint(-24, -24, 500);
    chassis.moveToPoint(-24, -24, 1000, {.maxSpeed = 80});
    pros::delay(500);
    loader.extend();
    // intake bottom right pile
    chassis.moveToPoint(24, -24, 1000, {.maxSpeed = 80});
    pros::delay(250);
    loader.retract();
    pros::delay(500);
    loader.extend();
    // intake top right pile
    chassis.turnToPoint(24, 24, 500);
    chassis.moveToPoint(24, 24, 1000, {.maxSpeed = 80});
    pros::delay(250);
    loader.retract();
    pros::delay(500);
    loader.extend();
    // score bottom mid goal
    chassis.turnToPoint(0, 0, 500, {.forwards = false});
    chassis.moveToPoint(0, 0, 1000, {.forwards = false, .maxSpeed = 60});
    chassis.moveToPoint(0, 0, 500, {.forwards = false, .maxSpeed = 15});
    intake.move(-90);
    pros::delay(1500);
    // intake top left pile
    chassis.moveToPoint(10, 24, 1000, {.forwards = false});
    chassis.turnToPoint(-24, 24, 500);
    intake.brake();
    chassis.moveToPoint(-24, 24, 1000, {.maxSpeed = 80});
    intake.move(127);
    pros::delay(500);
    loader.extend();
    // clear blue park zone and intake blocks
    chassis.turnToHeading(90, 750);
    chassis.moveToPoint(57, 24, 1250);
    pros::delay(750);
    loader.retract();
    chassis.swingToHeading(180, lemlib::DriveSide::RIGHT, 750);
    chassis.waitUntilDone();
    dist_reset.update_position(Sensor::LEFT, Direction::DOWN); // dist reset
    chassis.moveToPoint(63, -35, 2000);
    chassis.waitUntilDone();
    dist_reset.update_position(Sensor::LEFT, Direction::DOWN); // dist reset
    // score top mid goal
    chassis.moveToPoint(20, -20, 1000, {.forwards = false});
    intake.brake();
    chassis.turnToPoint(0, 0, 500, {.forwards = false});
    chassis.moveToPoint(0, 0, 750, {.forwards = false, .maxSpeed = 40});
    cata.midgoal_mech_down();
    chassis.moveToPoint(0, 0, 500, {.forwards = false, .maxSpeed = 20});
    pros::delay(250);
    intake_while_scoring_mid(1000);
    pros::delay(250);
    cata.down(127);
    pros::delay(250);
    cata.score_long(127);
    pros::delay(500);
    cata.down(127);
    chassis.setPose(13, 13, chassis.getPose().theta);
    // intake bottom mid pile
    intake.sort_off();
    chassis.moveToPoint(1, -39, 1250, {.maxSpeed = 80});
    pros::delay(250);
    cata.midgoal_mech_up();
    // move to bottom left loader
    chassis.moveToPoint(0, -24, 1000, {.forwards = false});
    pros::delay(100);
    loader.extend();
    chassis.turnToPoint(-24, -24, 500);
    chassis.moveToPoint(-24, -24, 1000);
    loader.retract();
    chassis.moveToPoint(-46, -48, 1000);
    chassis.turnToHeading(270, 500);
    chassis.waitUntilDone();
    dist_reset.update_position(Sensor::LEFT, Direction::LEFT);
    // clear bottom left loader
    chassis.moveToPoint(-90, -48, 1000, {.maxSpeed = 60});
    chassis.waitUntilDone();
    dist_reset.update_position(Sensor::LEFT, Direction::LEFT);
    // move to bottom right long goal
    chassis.moveToPoint(-24, -56, 1000, {.forwards = false});
    chassis.moveToPoint(24, -56, 1000, {.forwards = false});
    loader.retract();
    intake.brake();
    chassis.moveToPoint(40, -48, 1000, {.forwards = false});
    chassis.turnToHeading(90, 750);
    chassis.waitUntilDone();
    dist_reset.update_position(Sensor::RIGHT, Direction::RIGHT);
    // score bottom right long goal first time
    chassis.moveToPoint(0, -48, 500, {.forwards = false, .maxSpeed = 80});
    chassis.moveToPoint(0, -48, 500, {.forwards = false, .maxSpeed = 15});
    intake_while_scoring_long(1000);
    pros::delay(250);
    cata.down(127);
    pros::delay(250);
    cata.score_long(127);
    pros::delay(500);
    cata.down(127);
    chassis.setPose(30, -48, chassis.getPose().theta);
    dist_reset.update_position(Sensor::RIGHT, Direction::RIGHT);
    // clear bottom right loader
    chassis.moveToPoint(90, -48, 1500, {.maxSpeed = 60});
    loader.extend();
    chassis.turnToHeading(90, 500);
    chassis.waitUntilDone();
    dist_reset.update_position(Sensor::RIGHT, Direction::RIGHT);
    // score bottom right long goal second time
    chassis.moveToPoint(0, -48, 1000, {.forwards = false, .maxSpeed = 80});
    chassis.moveToPoint(0, -48, 500, {.forwards = false, .maxSpeed = 15});
    cata.score_long(127);
    pros::delay(500);
    cata.down(127);
    chassis.setPose(30, -48, chassis.getPose().theta);
    dist_reset.update_position(Sensor::RIGHT, Direction::RIGHT);
    // intake top mid pile
    chassis.swingToPoint(24, 24, lemlib::DriveSide::LEFT, 500);
    chassis.moveToPoint(24, 24, 1000);
    chassis.moveToPoint(0, 32, 1000);
    chassis.turnToPoint(0, 39, 500);
    chassis.moveToPoint(0, 39, 1000);
    chassis.moveToPoint(0, 24, 1000, {.forwards = false});
    // move to top right loader
    pros::delay(100);
    loader.extend();
    chassis.turnToPoint(24, 24, 500);
    chassis.moveToPoint(24, 24, 1000);
    loader.retract();
    chassis.moveToPoint(46, 48, 1000);
    chassis.turnToHeading(90, 500);
    loader.extend();
    chassis.waitUntilDone();
    dist_reset.update_position(Sensor::LEFT, Direction::RIGHT);
    // clear top right loader
    chassis.moveToPoint(90, 48, 1000, {.maxSpeed = 60});
    chassis.turnToHeading(90, 500);
    chassis.waitUntilDone();
    dist_reset.update_position(Sensor::LEFT, Direction::RIGHT);
    // move to top left long goal
    chassis.moveToPoint(24, 56, 1000, {.forwards = false});
    chassis.moveToPoint(-24, 56, 1000, {.forwards = false});
    loader.retract();
    intake.brake();
    chassis.moveToPoint(-40, 48, 1000, {.forwards = false});
    chassis.turnToHeading(270, 500);
    chassis.waitUntilDone();
    dist_reset.update_position(Sensor::RIGHT, Direction::LEFT);
    // score top left long goal first time
    chassis.moveToPoint(0, 48, 500, {.forwards = false, .maxSpeed = 80});
    chassis.moveToPoint(0, 48, 500, {.forwards = false, .maxSpeed = 15});
    intake_while_scoring_long(1000);
    pros::delay(250);
    cata.down(127);
    pros::delay(250);
    cata.score_long(127);
    pros::delay(500);
    cata.down(127);
    chassis.setPose(-30, 48, chassis.getPose().theta);
    dist_reset.update_position(Sensor::RIGHT, Direction::LEFT);
    // clear top left loader
    chassis.moveToPoint(90, 48, 1500, {.maxSpeed = 60});
    chassis.turnToHeading(270, 500);
    chassis.waitUntilDone();
    dist_reset.update_position(Sensor::RIGHT, Direction::LEFT);
    // score top left long goal second time
    chassis.moveToPoint(0, 48, 1000, {.forwards = false, .maxSpeed = 80});
    chassis.moveToPoint(0, 48, 500, {.forwards = false, .maxSpeed = 15});
    cata.score_long(127);
    pros::delay(500);
    cata.down(127);
    chassis.setPose(-30, 48, chassis.getPose().theta);
    dist_reset.update_position(Sensor::RIGHT, Direction::LEFT);
    // clear red park zone and park
    chassis.moveToPoint(-57, 24, 1000);
    chassis.swingToHeading(180, lemlib::DriveSide::LEFT, 500);
    chassis.waitUntilDone();
    dist_reset.update_position(Sensor::RIGHT, Direction::DOWN);
    chassis.moveToPoint(-63, -4, 2000);
    pros::delay(300);
    loader.extend();
    chassis.waitUntilDone();
    loader.retract();
}

void faster_prog_skills(){
    // initialization
    chassis.setPose(-62, -17, 0);
    intake.set_alliance_blue();
    intake.sort_on();
    cata.down(127);
    // clear red park zone
    chassis.moveToPoint(-62, 37, 2500);
    intake.move(127);
    chassis.turnToHeading(0, 500);
    chassis.waitUntilDone();
    dist_reset.update_position(Sensor::LEFT, Direction::UP);
    // intake top left pile
    chassis.turnToPoint(-24, 24, 500);
    chassis.moveToPoint(-24, 24, 1000);
    pros::delay(500);
    loader.extend();
    // score top mid goal
    chassis.turnToPoint(0, 0, 750, {.forwards = false});
    chassis.moveToPoint(0, 0, 1000, {.forwards = false, .maxSpeed = 60});
    cata.midgoal_mech_down();
    chassis.moveToPoint(0, 0, 500, {.forwards = false, .maxSpeed = 15});
    intake_while_scoring_mid(1000);
    pros::delay(500);
    cata.down(127);
    pros::delay(250);
    intake.sort_off();
    intake_while_scoring_mid(1000);
    pros::delay(500);
    cata.down(127);
    chassis.setPose(-12, 12, chassis.getPose().theta);
    // clear top left loader
    chassis.moveToPoint(-48, 48, 1000);
    intake.move(127);
    chassis.turnToHeading(270, 500);
    chassis.waitUntilDone();
    dist_reset.update_position(Sensor::RIGHT, Direction::LEFT);
    chassis.moveToPoint(-90, 48, 1000, {.maxSpeed = 60});
    // score top right long goal
    chassis.moveToPoint(-24, 58, 1000, {.forwards = false});
    chassis.moveToPoint(24, 58, 1000, {.forwards = false});
    loader.retract();
    chassis.moveToPoint(48, 48, 1000, {.forwards = false});
    chassis.turnToHeading(90, 750);
    chassis.waitUntilDone();
    dist_reset.update_position(Sensor::LEFT, Direction::RIGHT);
    chassis.moveToPoint(0, 48, 1000, {.forwards = false, .maxSpeed = 60});
    chassis.moveToPoint(0, 48, 500, {.forwards = false, .maxSpeed = 15});
    intake_while_scoring_long(1000);
    pros::delay(500);
    cata.down(127);
    pros::delay(500);
    cata.score_long(127);
    pros::delay(500);
    cata.down(127);
    chassis.setPose(30, 48, chassis.getPose().theta);
    // clear top right loader
    chassis.moveToPoint(90, 48, 1500, {.maxSpeed = 60});
    loader.extend();
    // score top right long goal
    chassis.moveToPoint(0, 48, 1000, {.forwards = false, .maxSpeed = 60});
    chassis.moveToPoint(0, 48, 500, {.forwards = false, .maxSpeed = 15});
    cata.score_long(127);
    pros::delay(500);
    cata.down(127);
    chassis.setPose(30, 48, chassis.getPose().theta);
    // clear blue park zone
    chassis.moveToPoint(60, 24, 1000);
    loader.retract();
    chassis.swingToHeading(180, lemlib::DriveSide::RIGHT, 500);
    chassis.waitUntilDone();
    dist_reset.update_position(Sensor::LEFT, Direction::DOWN);
    chassis.moveToPoint(62, -37, 2500);
    intake.set_alliance_red();
    intake.sort_on();
    chassis.turnToHeading(180, 500);
    chassis.waitUntilDone();
    dist_reset.update_position(Sensor::LEFT, Direction::DOWN);
    // intake top right pile
    chassis.turnToPoint(38, -15, 750);
    chassis.moveToPoint(38, -15, 1000);
    chassis.moveToPoint(24, 24, 1000);
    pros::delay(500);
    loader.extend();
    chassis.waitUntilDone();
    pros::delay(500);
    // score bottom mid goal
    chassis.turnToPoint(0, 0, 500, {.forwards = false});
    chassis.moveToPoint(0, 0, 1000, {.forwards = false, .maxSpeed = 60});
    chassis.moveToPoint(0, 0, 500, {.forwards = false, .maxSpeed = 15});
    intake.move(-127);
    pros::delay(1500);
    intake.brake();
    chassis.setPose(12, 12, chassis.getPose().theta);
    // clear bottom right loader
    chassis.moveToPoint(48, -48, 1500);
    pros::delay(250);
    intake.sort_off();
    intake.move(127);
    pros::delay(500);
    loader.retract();
    chassis.turnToHeading(90, 500);
    loader.extend();
    chassis.waitUntilDone();
    dist_reset.update_position(Sensor::RIGHT, Direction::RIGHT);
    chassis.moveToPoint(90, -48, 1000, {.maxSpeed = 60});
    // score bottom left long goal
    chassis.moveToPoint(24, -58, 1000, {.forwards = false});
    chassis.moveToPoint(24, -58, 1000, {.forwards = false});
    loader.retract();
    chassis.moveToPoint(-24, -58, 1000, {.forwards = false});
    chassis.moveToPoint(-48, -48, 1000, {.forwards = false});
    chassis.turnToHeading(270, 500);
    chassis.waitUntilDone();
    dist_reset.update_position(Sensor::LEFT, Direction::LEFT);
    chassis.moveToPoint(0, -48, 1000, {.forwards = false, .maxSpeed = 60});
    chassis.moveToPoint(0, -48, 500, {.forwards = false, .maxSpeed = 15});
    intake_while_scoring_long(1000);
    pros::delay(500);
    cata.down(127);
    pros::delay(500);
    cata.score_long(127);
    pros::delay(500);
    cata.down(127);
    chassis.setPose(-30, -48, chassis.getPose().theta);
}

void ramsete_test(){
    // ramchassis.follow(path_one);
    // ramchassis.follow(path_two);
}
