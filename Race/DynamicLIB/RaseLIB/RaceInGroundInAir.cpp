#include "RaceInGroundInAir.h"
RaceInGroundInAir::RaceInGroundInAir(const int& distance) {
    this->distance = distance;
}

void RaceInGroundInAir::bubble_sort_transport() {
    sort_transport_air();
    sort_transport_ground();
    int idx_i = 0;
    int idx_k = 0;
    while (true) {
        if (get_time_air(idx_i) > get_time_ground(idx_k)) {
            transport_all.push_back(transports_second[idx_k]);
            time.push_back(get_time_ground(idx_k));
            ++idx_k;
        }
        else if (get_time_air(idx_i) < get_time_ground(idx_k)) {
            transport_all.push_back(transports_first[idx_i]);
            time.push_back(get_time_air(idx_i));
            ++idx_i;
        }
        else if (get_time_air(idx_i) == get_time_ground(idx_k)) {
            transport_all.push_back(transports_first[idx_i]);
            transport_all.push_back(transports_second[idx_k]);
            time.push_back(get_time_air(idx_i));
            time.push_back(get_time_ground(idx_k));
            ++idx_k;
            ++idx_i;
        }
        if (idx_i == transports_first.size()) {
            for (int i = idx_k; i < transports_second.size(); ++i) {
                transport_all.push_back(transports_second[i]);
                time.push_back(get_time_ground(i));
            }
            break;
        }
        if (idx_k == transports_second.size()) {
            for (int i = idx_i; i < transports_first.size(); ++i) {
                transport_all.push_back(transports_first[i]);
                time.push_back(get_time_air(i));
            }
            break;
        }
    }
}

void RaceInGroundInAir::set_magic_air() {
    transports_first.push_back(AirTrans::creat_magic_air(this->distance));
}

void RaceInGroundInAir::set_eagle() {
    transports_first.push_back(AirTrans::creat_eagle());
}

void RaceInGroundInAir::set_broom() {
    transports_first.push_back(AirTrans::creat_broom(this->distance));
}

void RaceInGroundInAir::set_camel() {
    transports_second.push_back(GroundTrans::creat_camel());
}

void RaceInGroundInAir::set_camel_run() {
    transports_second.push_back(GroundTrans::creat_camel_run());
}

void RaceInGroundInAir::set_centaur() {
    transports_second.push_back(GroundTrans::creat_centaur());
}

void RaceInGroundInAir::set_all_terr_boots() {
    transports_second.push_back(GroundTrans::creat_all_terr_boots());
}

std::string RaceInGroundInAir::get_name_air_vec(const int& i) const {
    return transports_first[i]->get_name();
}

std::string RaceInGroundInAir::get_name_ground_vec(const int& i) const {
    return transports_second[i]->get_name();
}

std::string RaceInGroundInAir::get_name_air_ground_vec(const int& i) const {
    return transport_all[i]->get_name();
}

std::string RaceInGroundInAir::get_specilization_air_vec(const int& i) const {
    return transports_first[i]->get_specialization();
}

std::string RaceInGroundInAir::get_specilization_ground_vec(const int& i) const {
    return transports_second[i]->get_specialization();
}

int RaceInGroundInAir::get_size_air_vec() const { return transports_first.size(); }

int RaceInGroundInAir::get_size_ground_vec() const { return transports_second.size(); }

int RaceInGroundInAir::get_size_air_ground_vec() const { return transport_all.size(); }

double RaceInGroundInAir::get_time(const int& i)const { return this->time[i]; }

void RaceInGroundInAir::sort_transport_air() {
    for (size_t idx_i = 0; idx_i + 1 < transports_first.size(); ++idx_i) {
        for (size_t idx_j = 0; idx_j + 1 < transports_first.size() - idx_i; ++idx_j) {
            if (get_time_air(idx_j + 1) < get_time_air(idx_j)) {
                std::swap(transports_first[idx_j], transports_first[idx_j + 1]);
            }
        }
    }
}

void RaceInGroundInAir::sort_transport_ground() {
    for (size_t idx_i = 0; idx_i + 1 < transports_second.size(); ++idx_i) {
        for (size_t idx_j = 0; idx_j + 1 < transports_second.size() - idx_i; ++idx_j) {
            if (get_time_ground(idx_j + 1) < get_time_ground(idx_j)) {
                std::swap(transports_second[idx_j], transports_second[idx_j + 1]);
            }
        }
    }
}

double RaceInGroundInAir::get_time_ground(const int& i) {
    double time = static_cast<double>(this->distance) / static_cast<double>(transports_second[i]->get_speed());
    int cycle = static_cast<int>(time) / transports_second[i]->get_time_before_bedtime();
    if (transports_second[i]->get_name() == "Верблюд" || transports_second[i]->get_name() == "Ботинки-вездеходы") {
        if (cycle >= 1) {
            for (int k = 0; k < cycle; ++k) {
                if (k == 1) {
                    time += transports_second[i]->get_this_sleep_time();
                    continue;
                }
                time += transports_second[i]->get_update_sleep();
            }
        }
        return time;
    }
    else if (transports_second[i]->get_name() == "Верблюд-быстроход") {
        if (cycle >= 1) {
            for (int k = 0; k < cycle; ++k) {
                if (k == 1) {
                    time += transports_second[i]->get_this_sleep_time();
                    continue;
                }
                if (k == 2) {
                    time += transports_second[i]->get_update_sleep();
                    continue;
                }
                time += transports_second[i]->get_update_sleep_second();
            }
        }
        return time;
    }
    else if (transports_second[i]->get_name() == "Кентавр") {
        if (cycle >= 1) {
            for (int k = 0; k < cycle; ++k) {
                time += transports_second[i]->get_this_sleep_time();
            }
        }
        return time;
    }
    return 0;
}

double RaceInGroundInAir::get_time_air(const int& i) {
    return ((distance * transports_first[i]->get_shortening_the_distance()) / transports_first[i]->get_speed());
}
