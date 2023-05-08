
#ifndef RACE_GROUND_H
#define RACE_GROUND_H
#include "Race.h"
class RaceInGround;
class RaceGround : public Race {
protected:
    virtual ~RaceGround() = default;
    RaceGround& operator= (const RaceGround&) = delete;
    RaceGround() = default;
public:
    virtual void bubble_sort_transport() = 0;
    virtual std::string get_name(const int& i) const = 0;
    virtual void set_camel() = 0;
    virtual void set_camel_run() = 0;
    virtual void set_centaur() = 0;
    virtual void set_all_terr_boots() = 0;
    virtual int get_size() const = 0;
    virtual double get_time(const int& i) const = 0;
    static std::shared_ptr<RaceInGround> creat_race_in_ground(const int& distance);
};
#endif