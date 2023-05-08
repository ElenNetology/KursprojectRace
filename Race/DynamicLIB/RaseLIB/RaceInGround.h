#ifndef RACE_IN_GROUND_H
#define RACE_IN_GROUND_H
#include "RaceGround.h"
class RaceInGround : public RaceGround {
protected:
    std::vector <std::shared_ptr<GroundTrans > > transports;
public:
    RaceInGround() = delete;
    RaceInGround(const int& distance);
    void bubble_sort_transport() override final;
    std::string get_name(const int& i) const override final;
    int get_size() const override final;
    void set_camel() override final;
    void set_camel_run() override final;
    void set_centaur() override final;
    void set_all_terr_boots() override final;
    double get_time(const int& i) const override final;
};
#endif

