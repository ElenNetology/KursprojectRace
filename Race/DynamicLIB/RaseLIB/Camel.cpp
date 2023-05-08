#include "Camel.h"

Camel::Camel() {
    this->speed = 10;
    this->time_befor_bedtime = 30;
    this->sleep_time = 5;
    this->name = "Верблюд";
    this->specialization = "наземный";
}
double Camel::get_update_sleep() const { return 6; }
