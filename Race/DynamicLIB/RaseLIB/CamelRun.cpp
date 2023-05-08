#include "CamelRun.h"
#include "Exception.h"

CamelRun::CamelRun() {
    this->speed = 40;
    this->time_befor_bedtime = 10;
    this->sleep_time = 5;
    this->name = "Верблюд-быстроход";
    this->specialization = "наземный";
}
double CamelRun::get_update_sleep() const { return 6.5; }
double CamelRun::get_update_sleep_second() const { return 8; }
