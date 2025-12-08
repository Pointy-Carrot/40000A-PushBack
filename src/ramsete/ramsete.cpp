/*


#include "ramsete/ramsete.h"
#include "cmath"
#include "lemlib/chassis/chassis.hpp"
#include "ramsete/trajectory.h"
#include "initialization/robot_init.h"
#include "initialization/drive_initialization.h"


Ramsete::Ramsete(lemlib::Chassis* chassis, double track_width, double wheel_diameter, double b, double zeta) 
    : chassis(chassis), track_width(track_width), wheel_diameter(wheel_diameter), b(b), zeta(zeta) {};


ChassisSpeeds Ramsete::calculate(const Pose2d& current_pose, const TrajectoryPoint& desired_state){
    double eX_global = desired_state.x - current_pose.x;
    double eY_global = desired_state.y - current_pose.y;
    double eTheta = sanitize_angle(desired_state.theta - current_pose.theta);

    double cosTheta = cos(current_pose.theta);
    double sinTheta = sin(current_pose.theta);


    double eX = cosTheta * eX_global + sinTheta * eY_global;
    double eY = -sinTheta * eX_global + cosTheta * eY_global;


    double vRef = desired_state.lin_velo;
    double omegaRef = desired_state.ang_velo;


    double k = 2.0 * zeta * std::sqrt(omegaRef * omegaRef + b * vRef * vRef);


    double v = vRef * cos(eTheta) + k * eX;


    double omega = 0.0;
    double sinc_eTheta = 0.0;


    if(std::abs(eTheta) < 1e-6){
        sinc_eTheta = 1.0;
    } else{
        sinc_eTheta = sin(eTheta) / eTheta;
    }


    omega = omegaRef + k * eTheta + (b * vRef * sinc_eTheta * eY);

    return {v, omega};
}



WheelSpeeds Ramsete::to_wheel_speeds(const ChassisSpeeds& speeds){
    double left = speeds.vx - (speeds.omega * track_width / 2.0);
    double right = speeds.vx + (speeds.omega * track_width / 2.0);
    return {left, right};

}

WheelSpeeds Ramsete::wheel_velo_in_per_sec_to_rpm(const WheelSpeeds& wheel_speeds){
    double left_rpm = (wheel_speeds.left / diameter_to_circumference(wheel_diameter)) * 60.0;
    double right_rpm = (wheel_speeds.right / diameter_to_circumference(wheel_diameter)) * 60.0;
    double clamped_left_rpm = std::clamp(left_rpm, -600.0, 600.0);
    double clamped_right_rpm = std::clamp(right_rpm, -600.0, 600.0);
    return {clamped_left_rpm, clamped_right_rpm};
}

double Ramsete::diameter_to_circumference(double diameter){
    return diameter * M_PI;
}


void Ramsete::follow(const Trajectory& path){
    double start_time = pros::millis() / 1000.0;
    double path_time = 0.0;
    Pose2d current_pose;
    
    while(path_time <= path.getTotalTime()){
        path_time = (pros::millis() / 1000.0) - start_time;

        TrajectoryPoint desired_state = path.sample(path_time);

        current_pose.x = chassis->getPose().x;
        current_pose.y = chassis->getPose().y;
        current_pose.theta = chassis->getPose(true).theta;

        ChassisSpeeds target_speeds = calculate(current_pose, desired_state);

        WheelSpeeds wheel_speeds_in_per_sec = to_wheel_speeds(target_speeds);

        WheelSpeeds wheel_speeds_rpm = wheel_velo_in_per_sec_to_rpm(wheel_speeds_in_per_sec);


        explicitchassis.move_drive(wheel_speeds_rpm.left, wheel_speeds_rpm.right);

        pros::delay(20);
    }
}




void autonomous() {
    Trajectory myPath;
    myPath.points = {
        {0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
        {0.5, 3.0, 0.0, 0.0, 6.0, 0.0},
        {1.0, 12.0, 0.0, 0.0, 18.0, 0.0},
        {1.5, 21.0, 0.0, 0.0, 6.0, 0.0},
        {2.0, 24.0, 0.0, 0.0, 0.0, 0.0}
    };
    ramchassis.follow(myPath);
}
*/