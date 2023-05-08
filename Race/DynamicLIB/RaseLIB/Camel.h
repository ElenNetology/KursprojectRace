#ifndef CAMEL_H
#define CAMEL_H
#include "TVehicleGround.h"
class Camel : public TVehicleGround {
public:
    Camel();
    double get_update_sleep() const override final;
};
#endif
