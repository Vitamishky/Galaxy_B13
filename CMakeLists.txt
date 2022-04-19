cmake_minimum_required(VERSION 3.20)
project(Galaxy_B13)

set(CMAKE_CXX_STANDARD 17)


set(PROJECT_HEADERS
        spaceObjects.h
        spaceShip.h
        parametrizationScreen.h
        camera.h
        functions.h
        Planet.h
        MODULE.h
        drawAll.h
        startMenu.h
        optionsMenu.h
        aboutMenu.h
        buildRocket.h
        )
set(PROJECT_SOURCES
        main.cpp
        spaceObjects.cpp
        spaceShip.cpp
        parametrizationScreen.cpp
        camera.cpp
        functions.cpp
        Planet.cpp
        MODULE.cpp
        drawAll.cpp
        startMenu.cpp
        optionsMenu.cpp
        aboutMenu.cpp
        buildRocket.cpp
        sounds.cpp sounds.h)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(Galaxy_B13 ${PROJECT_SOURCES} ${PROJECT_HEADERS})

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/Users/vladi/Documents/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/Users/vladi/Documents/SFML-2.5.1/include)
target_link_libraries(Galaxy_B13 sfml-system sfml-window sfml-graphics sfml-audio sfml-network)

