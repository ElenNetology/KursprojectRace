
#ifndef RACE_AIR_H
#define RACE_AIR_H
#include "Race.h"
class RaceInAir;
class RaceAir : public Race {
protected:
    virtual ~RaceAir() = default;
    RaceAir& operator= (const RaceAir&) = delete;
    RaceAir() = default;
public:
    virtual void bubble_sort_transport() = 0;
    virtual std::string get_name(const int& i) const = 0;
    virtual void set_magic_air() = 0;
    virtual void set_eagle() = 0;
    virtual void set_broom() = 0;
    virtual int get_size() const = 0;
    virtual double get_time(const int& i) const = 0;
    static std::shared_ptr<RaceInAir> creat_race_in_air(const int& distance);
};
#endif
