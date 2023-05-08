#ifndef T_VEHICLE_H
#define T_VEHICLE_H
#include <string>
#include <memory>
class TVehicle {
public:
    virtual std::string get_name() const = 0;
protected:
    int speed;
    std::string name;
    std::string specialization;
    virtual ~TVehicle() = default;
    TVehicle& operator=(const TVehicle&) = delete;
    TVehicle() = default;
};
#endif

