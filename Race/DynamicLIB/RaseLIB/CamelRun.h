#ifndef CAMEL_RUN_H
#define CAMEL_RUN_H
#include "TVehicleGround.h"
class CamelRun : public TVehicleGround {
public:
    CamelRun();
    double get_update_sleep() const override final;
    double get_update_sleep_second() const override final;
};
#endif


