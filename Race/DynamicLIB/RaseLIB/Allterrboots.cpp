#include "Allterrboots.h"
#include "Exception.h"

Allterrboots::Allterrboots() {
    this->speed = 6;
    this->time_befor_bedtime = 60;
    this->sleep_time = 10;
    this->name = "�������-���������";
    this->specialization = "��������";
}
double Allterrboots::get_update_sleep() const { return 5; }