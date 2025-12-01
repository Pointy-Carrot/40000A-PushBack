#pragma once

#include "cmath"
#include "vector"

struct TrajectoryPoint {
    double time;        // seconds
    double x;           // inches
    double y;           // inches
    double theta;       // radians
    double lin_velo;    // inches/sec
    double ang_velo;    // radians/sec
};

/**
 * @brief helper function for linear interpolation
 * 
 * @param start starting value
 * @param end ending value
 * @param t percentage value between start and end
 * @return double interpolated value
 */
double lerp(double start, double end, double t);

/**
 * @brief sanitizes angle handling wrap-around
 * 
 * @param angle unsanitized angle
 * @return double sanitized angle
 */
double sanitize_angle(double angle);

/**
 * @brief helper function for linear interpolation
 * 
 * @param start starting value
 * @param end ending value
 * @param t percentage value between start and end
 * @return double interpolated value
 */
double lerp_angle(double start, double end, double t);

class Trajectory {
    public:
        std::vector<TrajectoryPoint> points;

        /**
         * @brief samples trajectory at a specific point in time using linear interpolation
         * 
         * @param time the time(seconds) to sample the path at
         * @return TrajectoryPoint an interpolated TrajectoryPoint for the specified time
         */
        TrajectoryPoint sample(double time) const;


        double getTotalTime() const;



};

extern Trajectory load_trajectory_from_asset(const char* path_data);

extern Trajectory path_one;
extern Trajectory path_two;
