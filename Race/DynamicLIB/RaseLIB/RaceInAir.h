
#ifndef RACE_IN_AIR_H
#define RACE_IN_AIR_H
#include "RaceAir.h"
class RaceInAir : public RaceAir {
protected:
    std::vector <std::shared_ptr<AirTrans > > transports;
public:
    RaceInAir() = delete;
    RaceInAir(const int& distance);
    void bubble_sort_transport() override final;
    std::string get_name(const int& i) const override final;
    int get_size() const override;
    void set_magic_air() override final;
    void set_eagle() override final;
    void set_broom() override final;
    double get_time(const int& i) const override final;
};
#endif
