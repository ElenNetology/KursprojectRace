#include "Broom.h"
#include "Exception.h"


Broom::Broom(const int& distance) {
    this->speed = 20;
    this->name = "Метла";
    this->shortening_the_distance = 1 - ((distance / static_cast<double>(1000)) / 100);
    this->specialization = "воздушный";
}