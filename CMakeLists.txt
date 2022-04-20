cmake_minimum_required(VERSION 3.20)
project(Galaxy_B13)

set(CMAKE_CXX_STANDARD 17)

set(HEADERS
        aboutMenu.h
        buildRocket.h
        camera.h
        client.h
        drawAll.h
        functions.h
        MODULE.h
        optionsMenu.h
        parametrizationScreen.h
        spaceObjects.h
        spaceShip.h
        startMenu.h
        )

find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)

add_executable(${PROJECT_NAME} ${HEADERS} main.cpp
        camera.cpp
        parametrizationScreen.cpp
        spaceObjects.cpp
        spaceShip.cpp
        drawAll.cpp
        functions.cpp
        MODULE.cpp
        aboutMenu.cpp
        buildRocket.cpp
        optionsMenu.cpp
        startMenu.cpp
        client.cpp)


target_link_libraries(Galaxy_B13 sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
target_link_libraries(Galaxy_Server sfml-system sfml-window sfml-graphics sfml-audio sfml-network)