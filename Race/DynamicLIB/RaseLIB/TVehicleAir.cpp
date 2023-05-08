#include "TVehicleAir.h"

std::string TVehicleAir::get_name() const { return this->name; }
std::string TVehicleAir::get_specialization()  const { return this->specialization; }
int TVehicleAir::get_speed() const { return this->speed; }
double TVehicleAir::get_shortening_the_distance() const { return this->shortening_the_distance; }