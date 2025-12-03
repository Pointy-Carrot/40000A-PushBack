#include "lemlib/api.hpp" // IWYU pragma: keep\
#include "lemlib/chassis/chassis.hpp"
#include "subsystems/chassis_config.h"
#include "subsystems/intake.h"
#include "subsystems/cata.h"
#include "subsystems/pneumatics.h"
#include "misc/autons.h"
#include "misc/distance_reset.h"
#include "ramsete/ramsete.h"

void left_sawp(){};
void right_sawp(){};
void left_7_ball_long(){};
void right_7_ball_long(){};
void left_7_ball_split(){};
void right_7_ball_split(){};
void full_sawp(){};
void prog_skills(){
    // initialization
    chassis.setPose(-46, -9, 180);
    intake.set_alliance_red();
    intake.sort_on();
    cata.down();
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
    chassis.turnToPoint(10, 10, 500);
    chassis.moveToPoint(10, 10, 1000, {.maxSpeed = 50});
    chassis.waitUntiDone();
    intake.move(-90);
    pros::delay(1500);
    // intake top left pile
    chassis.moveToPoint(10, 24, 1000, {.forward = false});
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
    dist_reset.update_positiono(Sensor::LEFT, Direction::DOWN); // dist reset
    chassis.moveToPoint(63, -35, 2000);
    chassis.waitUntilDone();
    dist_reset.update_position(Sensor::LEFT, Direction::DOWN); // dist reset
    // score top mid goal
    chassis.moveToPoint(20, -20, 1000, {.forward = false});
    intake.brake();
    chassis.turnToPoint(0, 0, 500, {.forward = false});
    chassis.moveToPoint(0, 0, 750, {.forward = false, .maxSpeed = 40});
    cata.midgoal_mech_down();
    chassis.moveToPoint(0, 0, 500, {.forward = false, .maxSpeed = 20});
    pros::delay(250);
    intake_while_scoring_mid();
    pros::delay(250);
    cata.down();
    pros::delay(250);
    cata.score_long();
    pros::delay(500);
    cata.down();
    chassis.setPose(13, 13, chassis.getPose().theta);
    // intake bottom mid pile
    intake.sort_off();
    chassis.moveToPoint(1, -39, 1250, {.maxSpeed = 80});
    pros::delay(250);
    cata.midgoal_mech_up();
    // move to bottom left loader
    chassis.moveToPoint(0, -24, 1000, {.forward = false});
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
    chassis.moveToPoint(-24, -56, 1000, {.forward = false});
    chassis.moveToPoint(24, -56, 1000, {.forward = false});
    loader.retract();
    intake.brake();
    chassis.moveToPoint(40, -48, 1000, {.forward = false});
    chassis.turnToHeading(90, 750);
    chassis.waitUntilDone();
    dist_reset.update_position(Sensor::RIGHT, Direction::RIGHT);
    // score bottom right long goal first time
    chassis.moveToPoint(0, -48, 500, {.forward = false, .maxSpeed = 80});
    chassis.moveToPoint(0, -48, 500, {.forward = false, .maxSpeed = 15});
    intake_while_scoring_long();
    pros::delay(250);
    cata.down();
    pros::delay(250);
    cata.score_long();
    pros::delay(500);
    cata.down();
    chassis.setPose(30, -48, chassis.getPose().theta);
    dist_reset.update_position(Sensor::RIGHT, Direction::RIGHT);
    // clear bottom right loader
    chassis.moveToPoint(90, -48, 1500, {.maxSpeed = 60});
    loader.extend();
    chassis.turnToHeading(90, 500);
    chassis.waitUntilDone();
    dist_reset.update_position(Sensor::RIGHT, Direction::RIGHT);
    // score bottom right long goal second time
    chassis.moveToPoint(0, -48, 1000, {.forward = false, .maxSpeed = 80});
    chassis.moveToPoint(0, -48, 500, {.forward = false, .maxSpeed = 15});
    cata.score_long();
    pros::delay(500);
    cata.down();
    chassis.setPose(30, -48, chassis.getPose().theta);
    dist_reset.update_position(Sensor::RIGHT, Direction::RIGHT);
    // intake top mid pile
    chassis.swingToPoint(24, 24, lemlib::DriveSide::LEFT, 500);
    chassis.moveToPoint(24, 24, 1000);
    chassis.moveToPoint(0, 32, 1000);
    chassis.turnToPoint(0, 39, 500);
    chassis.moveToPoint(0, 39, 1000);
    chassis.moveToPoint(0, 24, 1000, {.forward = false});
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
    chassis.moveToPosition(90, 48, 1000, {.maxSpeed = 60});
    chassis.turnToHeading(90, 500);
    chassis.waitUntilDone();
    dist_reset.update_position(Sensor::LEFT, Direction::RIGHT);
    // move to top left long goal
    chassis.moveToPoint(24, 56, 1000, {.forward = false});
    chassis.moveToPoint(-24, 56, 1000, {.forward = false});
    loader.retract();
    intake.brake();
    chassis.moveToPoint(-40, 48, 1000, {.forward = false});
    chassis.turnToHeading(270, 500);
    chassis.waitUntilDone();
    dist_reset.update_position(Sensor::RIGHT, Direction::LEFT);
    // score top left long goal first time
    chassis.moveToPoint(0, 48, 500, {.forward = false, .maxSpeed = 80});
    chassis.moveToPoint(0, 48, 500, {.forward = false, .maxSpeed = 15});
    intake_while_scoring_long();
    pros::delay(250);
    cata.down();
    pros::delay(250);
    cata.score_long();
    pros::delay(500);
    cata.down();
    chassis.setPose(-30, 48, chassis.getPose().theta);
    dist_reset.update_positon(Sensor::RIGHT, Direction::LEFT);
    // clear top left loader
    chassis.moveToPoint(90, 48, 1500, {.maxSpeed = 60});
    chassis.turnToHeading(270, 500);
    chassis.waitUntilDone();
    dist_reset.update_position(Sensor::RIGHT, Direction::LEFT);
    // score top left long goal second time
    chassis.moveToPoint(0, 48, 1000, {.forward = false, .maxSpeed = 80});
    chassis.moveToPoint(0, 48, 500, {.forward = false, .maxSpeed = 15});
    cata.score_long();
    pros::delay(500);
    cata.down();
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
    









     /**   
    // initialization
    chassis.setPose(-49, 18, 0);
    intake.sort_off();
    cata.down();
    // move to top left loader
    chassis.moveToPoint(-49, 48, 1000);
    loader.extend();
    chassis.turnToHeading(270, 500);
    intake.move(127);
    // clear top left loader
    chassis.waitUntilDone();
    dist_reset.update_position(Sensor::RIGHT, Direction::LEFT); // distance reset
    chassis.moveToPoint(-90, 48, 1000, {.maxSpeed = 60});
    // score top long goal left side
    chassis.moveToPoint(0, 48, 1000, {.forwards = false, .maxSpeed = 80});
    chassis.moveToPoint(0, 48, 500, {.forwards = false, .maxSpeed = 20});
    chassis.waitUntilDone();
    cata.down();
    dist_reset.update_position(Sensor::RIGHT, Direction::LEFT); // distance reset
    // move to top right block pile
    chassis.swingToHeading(180, lemlib::DriveSide::LEFT, 500);
    chassis.moveToPoint(-36, 24, 1000);
    chassis.turnToPoint(-24, 24, 500);
    // intake top right block pile
    intake.set_alliance_red();
    intake.sort_on();
    chassis.moveToPoint(-24, 24, 1000, {.maxSpeed = 60});
    pros::delay(500);
    loader.extend();
    // intake top left block pile
    chassis.turnToHeading(90, 500);
    chassis.moveToPoint(24, 24, 1500, {.maxSpeed = 60});
    pros::delay(500);
    loader.retract();
    pros::delay(500);
    loader.extend();
    // score top mid goal
    chassis.turnToPoint(0, 0, 500, {.forwards = false});
    chassis.moveToPoint(0, 0, 1000, {.forwards = false, .maxSpeed = 60});
    cata.midgoal_mech_down();
    chassis.moveToPoint(0, 0, 500, {.forwards = false, .maxSpeed = 20});
    cata.score_mid();
    loader.retract();
    chassis.waitUntilDone();
    cata.down();
    chassis.setPose(12, 12, chassis.getPose().theta);// reset position
    // move to top right loader
    intake.sort_off();
    chassis.moveToPoint(49, 48, 1000);
    intake.move(-127);
    loader.extend();
    chassis.turnToHeading(90, 500);
    intake.move(127);
    // clear top right loader
    chassis.waitUntilDone();
    dist_reset.update_position(Sensor::LEFT, Direction::RIGHT); // distance reset
    chassis.moveToPoint(90, 48, 1000, {.maxSpeed = 60});
    // score top long goal right side
    chassis.moveToPoint(0, 48, 1000, {.forwards = false, .maxSpeed = 80});
    chassis.moveToPoint(0, 48, 500, {.forwards = false, .maxSpeed = 20});
    cata.score_long();
    chassis.waitUntilDone();
    cata.down();
    dist_reset.update_position(Sensor::LEFT, Direction::RIGHT); // distance reset
    // clear blue parking zone
    chassis.moveToPoint(54, 20, 1500);
    chassis.swingToHeading(180, lemlib::DriveSide::RIGHT, 500);
    chassis.waitUntilDone();
    dist_reset.update_position(Sensor::LEFT, Direction::DOWN); // distance reset
    chassis.moveToPoint(56, -36, 2000);
    // move to bottom long goal right side
    chassis.moveToPoint(40, -48, 1000);
    chassis.turnToHeading(90, 750);
    loader.extend();
    chassis.waitUntilDone();
    dist_reset.update_position(Sensor::RIGHT, Direction::RIGHT); // distance reset
    // score bottom long goal right side
    chassis.moveToPoint(0, -48, 750, {.forwards = false, .maxSpeed = 60});
    chassis.moveToPoint(0, -48, 500, {.forwards = false, .maxSpeed = 20});
    cata.score_long();
    chassis.waitUntilDone();
    cata.down();
    dist_reset.update_position(Sensor::RIGHT, Direction::RIGHT); // distance reset
    // move to bottom right loader
    chassis.moveToPoint(48, -48, 1000);
    loader.extend();
    // clear bottom right loader
    chassis.moveToPoint(90, -48, 1000, {.maxSpeed = 60});
    chassis.waitUntilDone();
    dist_reset.update_position(Sensor::RIGHT, Direction::RIGHT); // distance reset
    // score bottom long goal right side
    chassis.moveToPoint(0, -48, 1000, {.forwards = false, .maxSpeed = 80});
    chassis.moveToPoint(0, -48, 500, {.forwards = false, .maxSpeed = 20});
    cata.score_half();
    chassis.waitUntilDone();
    cata.down();
    dist_reset.update_position(Sensor::RIGHT, Direction::RIGHT); // distance reset
    // move to bottom right block pile
    chassis.swingToPoint(36, -24, lemlib::DriveSide::LEFT, 750);
    chassis.moveToPoint(36, -24, 1000);
    chassis.turnToPoint(24, -24, 500);
    // pick up bottom right block pile
    intake.set_alliance_red();
    intake.sort_on();
    chassis.moveToPoint(24, -24, 1000, {.maxSpeed = 60});
    pros::delay(500);
    loader.extend();
    // pick up bottom left block pile
    chassis.moveToPoint(-30, -24, 1500, {.maxSpeed = 60});
    pros::delay(500);
    loader.retract();
    pros::delay(500);
    loader.extend();
    // move to bottom mid goal
    chassis.moveToPoint(24, -24, 1000, {.forwards = false});
    chassis.waitUntilDone();
    pros::delay(500); // allow blocks tfo settle from loader grab
    chassis.turnToPoint(0, 0, 500);
    loader.retract();
    // score bottom mid goal
    chassis.moveToPoint(0, 0, 500, {.maxSpeed = 60});
    chassis.moveToPoint(0, 0, 500, {.maxSpeed = 20});
    intake.move(-100);
    chassis.waitUntilDone();
    pros::delay(1000);
    intake.move(-50);
    // move to bottom left loader
    chassis.moveToPoint(18, -18, 500, {.forwards = false});
    chassis.turnToPoint(-48, -48, 500);
    chassis.moveToPoint(-48, -48, 2000);
    intake.move(-127);
    intake.sort_off();
    chassis.turnToHeading(270, 500);
    intake.brake();
    chassis.waitUntilDone();
    dist_reset.update_position(Sensor::LEFT, Direction::LEFT); // distance reset
    // clear bottom left loader
    chassis.moveToPoint(-90, -48, 1000, {.maxSpeed = 60});
    intake.move(127);
    loader.extend();
    dist_reset.update_position(Sensor::LEFT, Direction::LEFT); // distance reset
    // score bottom long goal left side
    chassis.moveToPoint(0, -48, 1000, {.forwards = false, .maxSpeed = 80});
    chassis.moveToPoint(0, -48, 500, {.forwards = false, .maxSpeed = 20});
    cata.score_long();
    chassis.waitUntilDone();
    dist_reset.update_position(Sensor::LEFT, Direction::UP); // distance reset
    // clear red park zone
    chassis.moveToPoint(-54, -20, 1000);
    chassis.swingToHeading(0, lemlib::DriveSide::RIGHT, 500);
    chassis.waitUntilDone();
    dist_reset.update_position(Sensor::LEFT, Direction::UP); // distannce reset
    chassis.moveToPoint(-56, 36, 1500);
    // score top long goal left side
    chassis.moveToPoint(-40, 48, 1000);
    chassis.turnToHeading(270, 500);
    chassis.waitUntilDone();
    dist_reset.update_position(Sensor::RIGHT, Direction::LEFT); // distance reset
    chassis.moveToPoint(0, 48, 1000, {.forwards = false, .maxSpeed = 80});
    chassis.moveToPoint(0, 48, 500, {.forwards = false, .maxSpeed = 20});
    cata.score_long();
    chassis.waitUntilDone();
    cata.down();
    dist_reset.update_position(Sensor::RIGHT, Direction::LEFT); // distance reset
    // park in red park zone
    chassis.moveToPoint(-54, 20, 1000);
    chassis.swingToHeading(180, lemlib::DriveSide::LEFT, 500);
    chassis.moveToPoint(-56, -8, 1500);
    */
}

void ramsete_test(){
    ramchassis.follow(path_one);
    ramchassis.follow(path_two);
}
