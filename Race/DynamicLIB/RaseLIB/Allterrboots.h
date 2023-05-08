#ifndef ALL_TERR_BOOTS_H
#define ALL_TERR_BOOTS_H
#include "TVehicleGround.h"
class Allterrboots : public TVehicleGround {
public:
    Allterrboots();
    double get_update_sleep() const override final;
};
#endif

