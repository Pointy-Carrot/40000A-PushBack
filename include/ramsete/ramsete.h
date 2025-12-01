#pragma once
#include "lemlib/chassis/chassis.hpp"
#include "ramsete/trajectory.h"
#include "trajectory.h"



struct Pose2d {
    double x;
    double y;
    double theta;
};

struct ChassisSpeeds {
    double vx;
    double omega;
};

struct WheelSpeeds {
    double left;
    double right;
};

class Ramsete {
    private:
        double b;
        double zeta;
        double track_width;
        double wheel_diameter;
    public:

        lemlib::Chassis* chassis;

        /**
         * @brief Ramsete Constructor
         * 
         * @param chassis chassis object
         * @param track_width the track with of the chassis
         * @param b gain constant to be tuned (like kP in a PID controller)
         * @param zeta dampening constant to be tuned (like kD in a PID controller)
         */
        Ramsete(lemlib::Chassis* chassis, double track_width, double wheel_diameter, double b, double zeta);


        /**
         * @brief Calculates the corrected chassis speeds (linear and angular) to follow the trajectory
         * 
         * @param current_pose the robot's current position and heading
         * @param desired_state the target position and heading
         * @return ChassisSpeeds A ChassisSpeeds struct with a linear and angular velocity
         */
        ChassisSpeeds calculate(const Pose2d& current_pose, const TrajectoryPoint& desired_state);

        /**
         * @brief primary function call for Ramsete
         * 
         * @param path the Trajectory to follow
         */
        void follow(const Trajectory& path);

        /**
         * @brief transforms linear and angular speeds into left and right wheel speeds
         * 
         * @param speeds the linear and angular speeds
         * @return WheelSpeeds the left and right wheel speeds
         */
        WheelSpeeds to_wheel_speeds(const ChassisSpeeds& speeds);

        
        /**
         * @brief convert velocities in inches per second to rpms
         * 
         * @param left_in_per_sec left wheel velocity
         * @param right_in_per_sec right wheel velocity
         */
        WheelSpeeds wheel_velo_in_per_sec_to_rpm(const WheelSpeeds& wheel_speeds);

        /**
         * @brief calculate circumference from a given diameter
         * 
         * @param diameter diameter of the circle
         * @return double circumference
         */
        double diameter_to_circumference(double diameter);

};






extern Ramsete ramchassis;