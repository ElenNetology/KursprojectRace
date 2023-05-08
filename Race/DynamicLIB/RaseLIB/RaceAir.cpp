#include "RaceAir.h"

std::shared_ptr<RaceInAir> creat_race_in_air(int& distance) {
    return std::make_shared<RaceInAir>(distance);

}
