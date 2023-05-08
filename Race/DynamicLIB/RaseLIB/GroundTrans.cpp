// Класс "Наземный транспорт"
#include "GroundTrans.h"

std::shared_ptr<Camel> GroundTrans::creat_camel() {
    return std::make_shared<Camel>();
}

std::shared_ptr<CamelRun> GroundTrans::creat_camel_run() {
    return std::make_shared<CamelRun>();
}

std::shared_ptr<Centaur> GroundTrans::creat_centaur() {
    return std::make_shared<Centaur>();
}

std::shared_ptr<Allterrboots> GroundTrans::creat_all_terr_boots() {
    return std::make_shared<Allterrboots>();
}

