
#ifndef TRANSPORT_AIR_H
#define TRANSPORT_AIR_H
#include "TVehicle.h"
class MagicAir;
class Eagle;
class Broom;
class AirTrans : public TVehicle {
protected:
    virtual ~AirTrans() = default;
    AirTrans& operator=(const AirTrans&) = delete;
    AirTrans() = default;
public:
    virtual std::string get_name() const = 0;
    virtual std::string get_specialization() const = 0;
    virtual int get_speed() const = 0;
    virtual double get_shortening_the_distance() const = 0;

    static std::shared_ptr<MagicAir> creat_magic_air(const int& distance);
    static std::shared_ptr<Eagle> creat_eagle();
    static std::shared_ptr<Broom> creat_broom(const int& distance);
};
#endif
