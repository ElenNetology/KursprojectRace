/// Races.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>
#include "DynamicLIB/RaseLIB/RaceInAir.h"
#include "DynamicLIB/RaseLIB/RaceInGround.h"
#include "DynamicLIB/RaseLIB/RaceInGroundInAir.h"
#include "DynamicLIB/RaseLIB/RaceAirGround.h"
#include "DynamicLIB/RaseLIB/RaceAir.h"
#include "DynamicLIB/RaseLIB/RaceGround.h"

enum class TRANSPORT_AIR {
    BROOM,
    MAGIC_AIR,
    EAGLE,
    MAX_NUMB
};

enum class TRANSPORT_GROUND {
    CAMEL_RUN,
    CENTAUR,
    CAMEL,
    ALL_TERR_BOOTS,
    MAX_NUMB
};

enum class TRANSPORT_ALL {
    CAMEL_RUN,
    CENTAUR,
    CAMEL,
    ALL_TERR_BOOTS,
    BROOM,
    MAGIC_AIR,
    EAGLE,
    MAX_NUMB
};

int greeting_out_and_choice() {
    std::cout << "Добро пожаловать в гоночный симулятор!\n"
        << "1.Гонка для наземного транспорта\n 2.Гонка для воздушного транспорта"
        << "3.Гонка для наземного и воздушного транспорта\n";
    int choice = 0;
    while (true) {
        std::cout << "Выберите тип гонки: ";
        std::cin >> choice;
        if (std::cin.fail() || choice > 3 || choice < 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }
    return choice;
}

int distance_sampling() {
    int distance = 0;
    std::cout << "Укажите длину дистанции (должна быть положительной).\n";
    while (true) {
        std::cout << "Ваш выбор:  ";
        std::cin >> distance;
        if (std::cin.fail() || distance <= 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка ввода, повторите попытку." << '\n';
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }
    return distance;
}

template <typename PTR_RACE>
void table_name_time_output_only_race_air_and_only_race_ground(const std::shared_ptr<PTR_RACE> RaseLIB) {
    std::cout << std::setw(25) << "Таблица участников" << '\n';
    std::cout << std::setw(20) << "Участники\n" << std::setw(12) << "Время\n";
    for (int idx_i = 0; idx_i < RaseLIB->get_size(); ++idx_i) {
        std::cout << std::setw(20) << RaseLIB->get_name(idx_i);
        std::cout << std::setw(10) << RaseLIB->get_time(idx_i) << '\n';
    }
}

template <typename PTR_RACE>
void table_name_output_only_race_air_and_only_race_ground(const std::shared_ptr<PTR_RACE> RaseLIB) {
    std::cout << std::setw(25) << "Таблица участников" << '\n';
    std::cout << std::setw(20) << "Участники\n";
    for (int idx_i = 0; idx_i < RaseLIB->get_size(); ++idx_i) {
        std::cout << std::setw(20) << RaseLIB->get_name(idx_i) << '\n';
    }
}

void table_name_output_all_race(const std::shared_ptr<RaceAirGround> RaseLIB) {
    std::cout << std::setw(30) << "Таблица участников" << '\n';
    std::cout << std::setw(25) << "Участники\n";
    for (int idx_i = 0; idx_i < RaseLIB->get_size_air_vec(); ++idx_i) {
        std::cout << std::setw(20) << RaseLIB->get_name_air_vec(idx_i);
        std::cout << std::setw(10) << RaseLIB->get_specilization_air_vec(idx_i) << '\n';
    }
    for (int idx_i = 0; idx_i < RaseLIB->get_size_ground_vec(); ++idx_i) {
        std::cout << std::setw(20) << RaseLIB->get_name_ground_vec(idx_i);
        std::cout << std::setw(10) << RaseLIB->get_specilization_ground_vec(idx_i) << '\n';
    }
}

void table_name_time_output_all_race(const std::shared_ptr<RaceAirGround> RaseLIB) {
    std::cout << std::setw(30) << "Таблица участников" << '\n';
    std::cout << std::setw(20) << "Участники" << std::setw(20) << "Время\n";
    for (int idx_i = 0; idx_i < RaseLIB->get_size_air_ground_vec(); ++idx_i) {
        std::cout << std::setw(20) << RaseLIB->get_name_air_ground_vec(idx_i);
        std::cout << std::setw(20) << RaseLIB->get_time(idx_i) << '\n';
    }
}

bool exit_register(const int& minimum_number_vehicles) {
    if (minimum_number_vehicles < 2) {
        std::cout << "Должно быть зарегистрировано хотя бы 2 транспортных средства.\n";
        return true;
    }
    int choice_again = 1;
    std::cout << "1. Зарегистрировать транспорт: \n";
    while (true) {
        std::cin >> choice_again;
        if (std::cin.fail() || choice_again > 1 || choice_again < 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка ввода, повторить попытку" << '\n';
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }
    if (choice_again == 1)
        return true;
    return false;
}

void cheking_vehicle_selection(int& choice, const int& max_numb_vehicle) {
    while (true) {
        std::cout << "Ваш выбор: ";
        std::cin >> choice;
        if (std::cin.fail() || choice > max_numb_vehicle || choice < 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка ввода, повторить попытку" << '\n';
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }
}

bool checking_vectors_emptiness(const std::shared_ptr<RaceAirGround>& RaseLIB) {
    if (RaseLIB->get_size_air_vec() == 0) {
        std::cout << "Вам необходимо зарегистрироваться хотя бы на одном воздушном транспорте\n";
        return true;
    }
    if (RaseLIB->get_size_ground_vec() == 0) {
        std::cout << "Вам необходимо зарегистрироваться хотя бы на одном земном транспорте\n";
        return true;
    }
    return false;
}

void game_race_air(const int& distance) {
    int choice = 0;
    int minimum_number_vehicles = 0;
    int counter_selected_vehicle[static_cast<int>(TRANSPORT_AIR::MAX_NUMB)]{ 0,0,0 };
    std::shared_ptr<RaceAir> RaseLIB = RaceAir::creat_race_in_air(distance);
    std::cout << "Гонка для воздушного транспорта.\n"
        << "1.Метла \n2.Ковер-самолет \n3.Орел \n"
        << "Выберите транспорт или 0 для завершения процесса регистрации.\n";
    while (true) {
        cheking_vehicle_selection(choice, static_cast<int>(TRANSPORT_AIR::MAX_NUMB));
        switch (choice) {
        case 1: if (counter_selected_vehicle[static_cast<int>(TRANSPORT_AIR::BROOM)] == 0) {
            RaseLIB->set_broom();
            ++minimum_number_vehicles;
            ++counter_selected_vehicle[static_cast<int>(TRANSPORT_AIR::BROOM)];
            break;
        }
              else {
            std::cout << "Вы уже зарегистрировали это транспортное средство\n";
            break;
        }
        case 2: if (counter_selected_vehicle[static_cast<int>(TRANSPORT_AIR::MAGIC_AIR)] == 0) {
            RaseLIB->set_magic_air();
            ++minimum_number_vehicles;
            ++counter_selected_vehicle[static_cast<int>(TRANSPORT_AIR::MAGIC_AIR)];
            break;
        }
              else {
            std::cout << "Вы уже зарегистрировали это транспортное средство\n";
            break;
        }
        case 3: if (counter_selected_vehicle[static_cast<int>(TRANSPORT_AIR::EAGLE)] == 0) {
            RaseLIB->set_eagle();
            ++minimum_number_vehicles;
            ++counter_selected_vehicle[static_cast<int>(TRANSPORT_AIR::EAGLE)];
            break;
        }
              else {
            std::cout << "Вы уже зарегистрировали это транспортное средство\n";
            break;
        }
        }
        if (minimum_number_vehicles == static_cast<int>(TRANSPORT_AIR::MAX_NUMB))
            break;
        if (choice == 0) {
            if (exit_register(minimum_number_vehicles))
                continue;
            else
                break;
        }
    }
    table_name_output_only_race_air_and_only_race_ground(RaseLIB);
    RaseLIB->bubble_sort_transport();
    table_name_time_output_only_race_air_and_only_race_ground(RaseLIB);
}

void game_race_ground(const int& distance) {
    int choice = 0;
    int minimum_number_vehicles = 0;
    int counter_selected_vehicle[static_cast<int>(TRANSPORT_GROUND::MAX_NUMB)]{ 0,0,0 };
    std::shared_ptr<RaceGround> RaseLIB = RaceGround::creat_race_in_ground(distance);
    std::cout << "Зарегистрируйте транспорт для неземной гонки.\n"
        << "1.Верблюд-быстроход \n2.Кентавр \n3.Верблюд \n4.Ботинки-вездеходы\n"
        << "Выберите транспорт или 0 для завершения процесса регистрации.\n";
    while (true) {
        cheking_vehicle_selection(choice, static_cast<int>(TRANSPORT_GROUND::MAX_NUMB));
        switch (choice) {
        case 1: if (counter_selected_vehicle[static_cast<int>(TRANSPORT_GROUND::CAMEL_RUN)] == 0) {
            RaseLIB->set_camel_run();
            ++minimum_number_vehicles;
            ++counter_selected_vehicle[static_cast<int>(TRANSPORT_GROUND::CAMEL_RUN)];
            break;
        }
              else {
            std::cout << "Вы уже зарегистрировали это транспортное средство\n";
            break;
        }
        case 2: if (counter_selected_vehicle[static_cast<int>(TRANSPORT_GROUND::CENTAUR)] == 0) {
            RaseLIB->set_centaur();
            ++minimum_number_vehicles;
            ++counter_selected_vehicle[static_cast<int>(TRANSPORT_GROUND::CENTAUR)];
            break;
        }
              else {
            std::cout << "Вы уже зарегистрировали это транспортное средство\n";
            break;
        }
        case 3: if (counter_selected_vehicle[static_cast<int>(TRANSPORT_GROUND::CAMEL)] == 0) {
            RaseLIB->set_camel();
            ++minimum_number_vehicles;
            ++counter_selected_vehicle[static_cast<int>(TRANSPORT_GROUND::CAMEL)];
            break;
        }
              else {
            std::cout << "Вы уже зарегистрировали это транспортное средство\n";
            break;
        }
        case 4: if (counter_selected_vehicle[static_cast<int>(TRANSPORT_GROUND::ALL_TERR_BOOTS)] == 0) {
            RaseLIB->set_all_terr_boots();
            ++minimum_number_vehicles;
            ++counter_selected_vehicle[static_cast<int>(TRANSPORT_GROUND::ALL_TERR_BOOTS)];
            break;
        }
              else {
            std::cout << "Вы уже зарегистрировали это транспортное средство\n";
            break;
        }

        }
        if (minimum_number_vehicles == static_cast<int>(TRANSPORT_GROUND::MAX_NUMB))
            break;
        if (choice == 0) {
            if (exit_register(minimum_number_vehicles))
                continue;
            else
                break;
        }
    }
    table_name_output_only_race_air_and_only_race_ground(RaseLIB);
    RaseLIB->bubble_sort_transport();
    table_name_time_output_only_race_air_and_only_race_ground(RaseLIB);
}

void game_race_air_and_ground(const int& distance) {
    int choice = 0;
    int minimum_number_vehicles = 0;
    int counter_selected_vehicle[static_cast<int>(TRANSPORT_ALL::MAX_NUMB)]{ 0,0,0 };
    std::shared_ptr<RaceAirGround> RaseLIB = RaceAirGround::creat_race_in_ground_in_air(distance);
    std::cout << "Гонка для наземного и воздушного транспорта.\n"
        << "1.Верблюд-быстроход \n2.Кентавр \n3.Верблюд \n4.Ботинки-вездеходы\n"
        << "1.Метла \n2.Ковер-самолет \n3.Орел \n\n"
        << "Выберите транспорт или 0 для завершения процесса регистрации.\n";
    while (true) {
        cheking_vehicle_selection(choice, static_cast<int>(TRANSPORT_ALL::MAX_NUMB));
        switch (choice) {
        case 1: if (counter_selected_vehicle[static_cast<int>(TRANSPORT_ALL::CAMEL_RUN)] == 0) {
            RaseLIB->set_camel_run();
            ++minimum_number_vehicles;
            ++counter_selected_vehicle[static_cast<int>(TRANSPORT_ALL::CAMEL_RUN)];
            break;
        }
              else {
            std::cout << "Вы уже зарегистрировали это транспортное средство\n";
            break;
        }
        case 2: if (counter_selected_vehicle[static_cast<int>(TRANSPORT_ALL::CENTAUR)] == 0) {
            RaseLIB->set_centaur();
            ++minimum_number_vehicles;
            ++counter_selected_vehicle[static_cast<int>(TRANSPORT_ALL::CENTAUR)];
            break;
        }
              else {
            std::cout << "Вы уже зарегистрировали это транспортное средство\n";
            break;
        }
        case 3: if (counter_selected_vehicle[static_cast<int>(TRANSPORT_ALL::CAMEL)] == 0) {
            RaseLIB->set_camel();
            ++minimum_number_vehicles;
            ++counter_selected_vehicle[static_cast<int>(TRANSPORT_ALL::CAMEL)];
            break;
        }
              else {
            std::cout << "Вы уже зарегистрировали это транспортное средство\n";
            break;
        }
        case 4: if (counter_selected_vehicle[static_cast<int>(TRANSPORT_ALL::ALL_TERR_BOOTS)] == 0) {
            RaseLIB->set_all_terr_boots();
            ++minimum_number_vehicles;
            ++counter_selected_vehicle[static_cast<int>(TRANSPORT_ALL::ALL_TERR_BOOTS)];
            break;
        }
              else {
            std::cout << "Вы уже зарегистрировали это транспортное средство\n";
            break;
        }
        case 5: if (counter_selected_vehicle[static_cast<int>(TRANSPORT_ALL::BROOM)] == 0) {
            RaseLIB->set_broom();
            ++minimum_number_vehicles;
            ++counter_selected_vehicle[static_cast<int>(TRANSPORT_ALL::BROOM)];
            break;
        }
              else {
            std::cout << "Вы уже зарегистрировали это транспортное средство\n";
            break;
        }
        case 6: if (counter_selected_vehicle[static_cast<int>(TRANSPORT_ALL::MAGIC_AIR)] == 0) {
            RaseLIB->set_magic_air();
            ++minimum_number_vehicles;
            ++counter_selected_vehicle[static_cast<int>(TRANSPORT_ALL::MAGIC_AIR)];
            break;
        }
              else {
            std::cout << "Вы уже зарегистрировали это транспортное средство\n";
            break;
        }
        case 7: if (counter_selected_vehicle[static_cast<int>(TRANSPORT_ALL::EAGLE)] == 0) {
            RaseLIB->set_eagle();
            ++minimum_number_vehicles;
            ++counter_selected_vehicle[static_cast<int>(TRANSPORT_ALL::EAGLE)];
            break;
        }
              else {
            std::cout << "Вы уже зарегистрировали это транспортное средство\n";
            break;
        }
        }
        if (minimum_number_vehicles == static_cast<int>(TRANSPORT_ALL::MAX_NUMB))
            break;
        if (choice == 0) {
            if (exit_register(minimum_number_vehicles)) {
                continue;
            }
            else {
                if (!checking_vectors_emptiness(RaseLIB)) {
                    break;
                }
                else
                    continue;
            }
        }
    }
    table_name_output_all_race(RaseLIB);
    RaseLIB->bubble_sort_transport();
    table_name_time_output_all_race(RaseLIB);
}


int main() {
    int choice_race = greeting_out_and_choice();
    int distance = distance_sampling();
    switch (choice_race) {
    case 1: game_race_air(distance); break;
    case 2: game_race_ground(distance); break;
    case 3: game_race_air_and_ground(distance); break;
    }
    std::cout << std::setw(25) << "!Игра окончена!";
    return 0;
}
