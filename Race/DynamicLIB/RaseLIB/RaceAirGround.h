#ifndef RACE_AIR_GROUND_H
#define RACE_AIR_GROUND_H
#include "Race.h"
class RaceInGroundInAir;
class RaceAirGround : public Race {
protected:
    virtual ~RaceAirGround() = default;
    RaceAirGround& operator= (const RaceAirGround&) = delete;
    RaceAirGround() = default;
public:
    virtual void bubble_sort_transport() = 0;
    virtual std::string get_name_air_vec(const int& i) const = 0;
    virtual std::string get_name_ground_vec(const int& i) const = 0;
    virtual std::string get_name_air_ground_vec(const int& i) const = 0;
    virtual std::string get_specilization_air_vec(const int& i) const = 0;
    virtual std::string get_specilization_ground_vec(const int& i) const = 0;
    virtual void set_magic_air() = 0;
    virtual void set_eagle() = 0;
    virtual void set_broom() = 0;
    virtual void set_camel() = 0;
    virtual void set_camel_run() = 0;
    virtual void set_centaur() = 0;
    virtual void set_all_terr_boots() = 0;
    virtual int get_size_air_vec() const = 0;
    virtual int get_size_ground_vec() const = 0;
    virtual int get_size_air_ground_vec() const = 0;
    virtual double get_time(const int& i) const = 0;
    static std::shared_ptr<RaceInGroundInAir> creat_race_in_ground_in_air(const int& distance);
};
#endif

