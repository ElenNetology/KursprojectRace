cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
project(C++)
add_executable(Race Race.cpp)
add_library(RaseLIB SHARED DynamicLIB/RaseLIB/Race.h 
DynamicLIB/RaseLIB/RaceAir.h DynamicLIB/RaseLIB/RaceAir.cpp 
DynamicLIB/RaseLIB/RaceAirGround.h DynamicLIB/RaseLIB/RaceAirGround.cpp 
DynamicLIB/RaseLIB/RaceGround.h DynamicLIB/RaseLIB/RaceGround.cpp 
DynamicLIB/RaseLIB/RaceInAir.h DynamicLIB/RaseLIB/RaceInAir.cpp 
DynamicLIB/RaseLIB/RaceInGroundInAir.h DynamicLIB/RaseLIB/RaceInGroundInAir.cpp 
DynamicLIB/RaseLIB/RaceInGround.h DynamicLIB/RaseLIB/RaceInGround.cpp
DynamicLIB/RaseLIB/TVehicle.h 
DynamicLIB/RaseLIB/Allterrboots.h DynamicLIB/RaseLIB/Allterrboots.cpp 
DynamicLIB/RaseLIB/Broom.h DynamicLIB/RaseLIB/Broom.cpp 
DynamicLIB/RaseLIB/Camel.h DynamicLIB/RaseLIB/Camel.cpp 
DynamicLIB/RaseLIB/CamelRun.h DynamicLIB/RaseLIB/CamelRun.cpp 
DynamicLIB/RaseLIB/Centaur.h DynamicLIB/RaseLIB/Centaur.cpp 
DynamicLIB/RaseLIB/Eagle.h DynamicLIB/RaseLIB/Eagle.cpp 
DynamicLIB/RaseLIB/AirTrans.h DynamicLIB/RaseLIB/AirTrans.cpp 
DynamicLIB/RaseLIB/GroundTrans.h DynamicLIB/RaseLIB/GroundTrans.cpp 
DynamicLIB/RaseLIB/MagicAir.h DynamicLIB/RaseLIB/MagicAir.cpp 
DynamicLIB/RaseLIB/TVehicleAir.h DynamicLIB/RaseLIB/TVehicleAir.cpp 
DynamicLIB/RaseLIB/TVehicleGround.h DynamicLIB/RaseLIB/TVehicleGround.cpp)
target_link_libraries(Race RaseLIB)
