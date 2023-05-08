#include "RaceGround.h"

std::shared_ptr<RaceInGround> creat_race_in_ground(const int& distance) {
    return std::make_shared<RaceInGround>(distance);
}
