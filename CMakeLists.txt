cmake_minimum_required(VERSION 3.10)
project(Gladiators_GBP)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Core Gui Widgets Multimedia REQUIRED)

add_subdirectory(cpr)

add_executable(Gladiators_GBP src/tec/ac/cr/gladiators/main.cpp src/tec/ac/cr/gladiators/client/Client.cpp src/tec/ac/cr/gladiators/client/Client.h src/tec/ac/cr/gladiators/logic/Gladiators.cpp src/tec/ac/cr/gladiators/logic/Gladiators.h src/tec/ac/cr/gladiators/logic/GladiatorsList.cpp src/tec/ac/cr/gladiators/logic/GladiatorsList.h src/tec/ac/cr/gladiators/logic/Towers.cpp src/tec/ac/cr/gladiators/logic/Towers.h src/tec/ac/cr/gladiators/logic/TowersList.cpp src/tec/ac/cr/gladiators/logic/TowersList.h src/tec/ac/cr/gladiators/ui/menu.cpp src/tec/ac/cr/gladiators/ui/menu.ui src/tec/ac/cr/gladiators/ui/menu.h src/tec/ac/cr/gladiators/ui/assets/resources.qrc src/tec/ac/cr/gladiators/ui/field.h src/tec/ac/cr/gladiators/ui/field.cpp src/tec/ac/cr/gladiators/ui/field.ui src/tec/ac/cr/gladiators/ui/stageselect.ui src/tec/ac/cr/gladiators/ui/stageselect.cpp src/tec/ac/cr/gladiators/ui/stageselect.h src/tec/ac/cr/gladiators/ui/elements/buttonhoverwatcher.h src/tec/ac/cr/gladiators/ui/elements/buttonhoverwatcher.cpp src/tec/ac/cr/gladiators/ui/elements/draggablerectitem.cpp src/tec/ac/cr/gladiators/ui/elements/draggablerectitem.h src/tec/ac/cr/gladiators/ui/elements/soldier.h src/tec/ac/cr/gladiators/ui/elements/soldier.cpp src/tec/ac/cr/gladiators/logic/pathfinding/Pathfinding.h src/tec/ac/cr/gladiators/logic/pathfinding/Pathfinding.cpp src/tec/ac/cr/gladiators/logic/pathfinding/PathNode.h src/tec/ac/cr/gladiators/logic/pathfinding/PathNode.cpp src/tec/ac/cr/gladiators/ui/elements/customrectitem.cpp src/tec/ac/cr/gladiators/ui/elements/customrectitem.h src/tec/ac/cr/gladiators/ui/elements/game.h src/tec/ac/cr/gladiators/ui/elements/game.cpp)

include_directories(${CPR_INCLUDE_DIRS})
target_link_libraries(Gladiators_GBP Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Multimedia ${CPR_LIBRARIES})
