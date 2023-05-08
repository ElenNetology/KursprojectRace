#include "RaceInAir.h"

RaceInAir::RaceInAir(const int& distance) { this->distance = distance; }

void RaceInAir::bubble_sort_transport() {
    std::sort(this->transports.begin(), transports.end(), [](const auto& rhs, const auto& lhs) {
        return rhs->get_shortening_the_distance() / rhs->get_speed() < lhs->get_shortening_the_distance() / lhs->get_speed();
        });
}
std::string RaceInAir::get_name(const int& i) const { return transports[i]->get_name(); }
int RaceInAir::get_size() const { return transports.size(); }

void RaceInAir::set_magic_air() {
    transports.push_back(AirTrans::creat_magic_air(this->distance));
}
void RaceInAir::set_eagle() {
    transports.push_back(AirTrans::creat_eagle());
}
void RaceInAir::set_broom() {
    transports.push_back(AirTrans::creat_broom(this->distance));
}
double RaceInAir::get_time(const int& i) const {
    return ((distance * transports[i]->get_shortening_the_distance()) / transports[i]->get_speed());
}
