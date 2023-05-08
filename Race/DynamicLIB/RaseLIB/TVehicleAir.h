#ifndef T_VEHICLE_AIR_H
#define T_VEHICLE_AIR_H
#include "AirTrans.h"
class TVehicleAir : public AirTrans {
protected:
    virtual ~TVehicleAir() = default;
    double shortening_the_distance;
    TVehicleAir() = default;
    std::string get_name() const override final;
    std::string get_specialization()  const override final;
    int get_speed() const override final;
    double get_shortening_the_distance() const override final;
};
#endif
