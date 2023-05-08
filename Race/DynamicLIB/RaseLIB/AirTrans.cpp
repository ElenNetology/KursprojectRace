//Воздушный транспорт
#include "AirTrans.h"

std::shared_ptr<MagicAir> AirTrans::creat_magic_air(const int& distance) {
    return std::make_shared<MagicAir>(distance);
}
std::shared_ptr<Eagle> AirTrans::creat_eagle() {
    return std::make_shared<Eagle>();
}
std::shared_ptr<Broom> AirTrans::creat_broom(const int& distance) {
    return std::make_shared<Broom>(distance);
}


