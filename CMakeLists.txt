cmake_minimum_required(VERSION 3.10)
project(Gladiators_GBP)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

add_subdirectory(cpr)

add_executable(Gladiators_GBP src/tec/ac/cr/gladiators/main.cpp src/tec/ac/cr/gladiators/client/Client.cpp src/tec/ac/cr/gladiators/client/Client.h src/tec/ac/cr/gladiators/logic/Gladiators.cpp src/tec/ac/cr/gladiators/logic/Gladiators.h src/tec/ac/cr/gladiators/logic/GladiatorsList.cpp src/tec/ac/cr/gladiators/logic/GladiatorsList.h src/tec/ac/cr/gladiators/logic/Towers.cpp src/tec/ac/cr/gladiators/logic/Towers.h src/tec/ac/cr/gladiators/logic/TowersList.cpp src/tec/ac/cr/gladiators/logic/TowersList.h)

include_directories(${CPR_INCLUDE_DIRS})
target_link_libraries(Gladiators_GBP Qt5::Core Qt5::Gui Qt5::Widgets ${CPR_LIBRARIES})