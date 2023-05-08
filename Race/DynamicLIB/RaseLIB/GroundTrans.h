#ifndef GROUND_TRANS_H
#define GROUND_TRANS_H
#include "TVehicle.h"
class Camel;
class CamelRun;
class Centaur;
class Allterrboots;
class GroundTrans : public TVehicle {
protected:
    virtual ~GroundTrans() = default;
    GroundTrans& operator=(const GroundTrans&) = delete;
    GroundTrans() = default;
public:
    virtual std::string get_name() const = 0;
    virtual std::string get_specialization() const = 0;
    virtual int get_speed() const = 0;
    virtual int get_time_before_bedtime() const = 0;
    virtual double get_this_sleep_time() const = 0;
    virtual double get_update_sleep() const = 0;
    virtual double get_update_sleep_second() const = 0;

    static std::shared_ptr<Camel> creat_camel();
    static std::shared_ptr<CamelRun> creat_camel_run();
    static std::shared_ptr<Centaur> creat_centaur();
    static std::shared_ptr<Allterrboots> creat_all_terr_boots();
};
#endif


