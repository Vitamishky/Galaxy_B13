cmake_minimum_required(VERSION 3.20)
project(Galaxy_B13)

set(CMAKE_CXX_STANDARD 17)

include_directories(camera.h drawAll.h functions.h parametrizationScreen.h spaceShip.h spaceObjects.h Planet.h MODULE_2.h)

find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)

add_executable(${PROJECT_NAME} main.cpp camera.cpp parametrizationScreen.cpp spaceObjects.cpp spaceShip.cpp drawAll.cpp Planet.cpp functions.cpp MODULE_2.cpp)

target_link_libraries(Galaxy_B13 sfml-system sfml-window sfml-graphics sfml-audio)