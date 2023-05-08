
#ifndef RACE_H
#define RACE_H
#include "../RaseLIB/MagicAir.h"
#include "../RaseLIB/Eagle.h"
#include "../RaseLIB/Broom.h"
#include "../RaseLIB/Camel.h"
#include "../RaseLIB/CamelRun.h"
#include "../RaseLIB/Centaur.h"
#include "../RaseLIB/Allterrboots.h"
#include <vector>
#include <algorithm>
class Race {
protected:
    int distance;
    Race() = default;
    virtual ~Race() = default;
};
#endif

