#include "TVehicleGround.h"

int TVehicleGround::get_time_before_bedtime() const { return this->time_befor_bedtime; }
double TVehicleGround::get_this_sleep_time() const { return this->sleep_time; }
std::string TVehicleGround::get_name() const { return this->name; }
std::string TVehicleGround::get_specialization() const { return this->specialization; }
int TVehicleGround::get_speed() const { return speed; }
double TVehicleGround::get_update_sleep() const { return 0; }
double TVehicleGround::get_update_sleep_second() const { return 0; }