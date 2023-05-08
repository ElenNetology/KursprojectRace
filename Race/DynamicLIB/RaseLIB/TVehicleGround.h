#ifndef T_VEHICLE_GROUND_H
#define T_VEHICLE_GROUND_H
#include "GroundTrans.h"
class TVehicleGround : public GroundTrans {
protected:
    virtual ~TVehicleGround() = default;
    int time_befor_bedtime;
    double sleep_time;
    TVehicleGround() = default;
    int get_time_before_bedtime() const override final;
    double get_this_sleep_time() const override final;
    std::string get_name() const override final;
    std::string get_specialization() const override final;
    int get_speed() const override final;
    double get_update_sleep() const override;
    double get_update_sleep_second() const override;
};
#endif

