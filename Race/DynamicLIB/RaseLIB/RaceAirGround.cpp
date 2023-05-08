#include "RaceAirGround.h"

std::shared_ptr<RaceInGroundInAir> creat_race_in_ground_in_air(const int& distance) {
    return std::make_shared<RaceInGroundInAir>(distance);
}

std::shared_ptr<RaceInGroundInAir> RaceAirGround::creat_race_in_ground_in_air(const int& distance)
{
    return std::shared_ptr<RaceInGroundInAir>();
}
