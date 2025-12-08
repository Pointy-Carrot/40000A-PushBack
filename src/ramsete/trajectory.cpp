/*

#include "ramsete/trajectory.h"
#include <sstream>
#include "ramsete/static_paths.h"



double sanitize_angle(double angle){
    angle = fmod(angle, 2.0 * M_PI);
    if(angle > M_PI) angle -= 2.0 * M_PI;
    if(angle < -M_PI) angle += 2.0 * M_PI;
    return angle;
}




TrajectoryPoint Trajectory::sample(double time) const {
        // handle edge cases
    // empty points vector
    if(points.empty()){
        return {0, 0, 0, 0, 0, 0};
    }
    // time is before the path start
    if(time <= points.front().time){
        return points.front();
    }
    // time is after path end
    if(time >= points.back().time){
        return points.back();
    }

    for(size_t i = 0; i < points.size() - 1; ++i){
        const TrajectoryPoint& start_point = points[i];
        const TrajectoryPoint& end_point = points[i+1];
        if(time >= start_point.time && time <= end_point.time){

            // edge case division by zero
            double segment_duration = end_point.time - start_point.time;

            if(std::abs(segment_duration) < 1e-6) {
                return start_point;
            }
            
            double time_into_segment = time - start_point.time;
            double alpha = time_into_segment / segment_duration;
            TrajectoryPoint interpolated_point;
            interpolated_point.time = time;
            interpolated_point.x = lerp(start_point.x, end_point.x, alpha);
            interpolated_point.y = lerp(start_point.y, end_point.y, alpha);
            interpolated_point.lin_velo = lerp(start_point.lin_velo, end_point.lin_velo, alpha);
            interpolated_point.ang_velo = lerp(start_point.ang_velo, end_point.ang_velo, alpha);
            interpolated_point.theta = lerp_angle(start_point.theta, end_point.theta, alpha);
            
            return interpolated_point;
        }
    }

    return points.back();
}

double Trajectory::getTotalTime() const {
    return points.empty() ? 0.0 : points.back().time;
}

Trajectory load_trajectory_from_asset(const char* path_data){
    Trajectory trajectory;

    std::stringstream ss(path_data);

    std::string line;

    while(std::getline(ss, line)){
        if(line.empty()) continue;

        TrajectoryPoint point;
        std::stringstream ss_line(line);
        std::string value;
        
        std::getline(ss_line, value, ',');
        point.time = std::stod(value);

        std::getline(ss_line, value, ',');
        point.x = std::stod(value);

        std::getline(ss_line, value, ',');
        point.y = std::stod(value);

        std::getline(ss_line, value, ',');
        point.theta = std::stod(value);

        std::getline(ss_line, value, ',');
        point.lin_velo = std::stod(value);

        std::getline(ss_line, value, ',');
        point.ang_velo = std::stod(value);

        trajectory.points.push_back(point);
        
    }
    return trajectory;
}

Trajectory path_one = load_trajectory_from_asset(path_one_data);
Trajectory path_two = load_trajectory_from_asset(path_two_data);
*/