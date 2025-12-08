include "initialization/robot_init.h"

// explicit drive init
DriveExplicit explicitchassis(&DL, &DR);

// chassis init
lemlib::Chassis chassis(drivetrain, // drivetrain
                        lateral_controller, // lateral pid
                        angular_controller, // angular pid
                        sensors // odom sensors
);

// intake init
IntakeSubsystem intake(&intake_motor, &colorsort_motor, &colorsort_optical, &alliance_selector_pot);

// pneumatics init
PneumaticsSubsystem wing(&wing_piston);
PneumaticsSubsystem loader(&loader_piston);
PneumaticsSubsystem gate(&gate_piston);
PneumaticsSubsystem midgoal_switch(&midgoal_piston);

// dist reset init
DistanceReset dist_reset(&left_dist, 6.3, &right_dist, 5.784);

// cata init
CataSubsystem cata(&cata_motor, &cata_pot, &gate, &midgoal_switch, 0, 0, 0); // TUNE // after gate and midgoal switch

// ramsete init
Ramsete ramchassis(&chassis, 10.724, lemlib::Omniwheel::NEW_275, 2.0, 0.7); // after chassis
