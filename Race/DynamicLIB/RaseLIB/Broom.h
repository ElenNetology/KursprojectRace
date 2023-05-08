#ifndef BROOM_H
#define BROOM_H
#include "TVehicleAir.h"
class Broom : public TVehicleAir {
public:
    Broom() = delete;
    Broom(const int& distance);
};
#endif
