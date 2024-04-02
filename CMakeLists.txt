cmake_minimum_required(VERSION 3.27)

project(Labyrinth_Jungle_2024)

set(CMAKE_CXX_STANDARD 17)

include_directories(include/controller include/model include/view include/utils)

set(MODEL_SOURCES
        src/model/Labyrinth.cpp
        src/model/HumanPlayer.cpp
)

set(VIEW_SOURCES
        src/view/GameView.cpp
)

set(CONTROLLER_SOURCES
        src/controller/GameController.cpp
)

set(UTILS_SOURCES
        src/utils/Pathfinding.cpp
        include/controller/GameController.hpp
        include/model/HumanPlayer.hpp
        include/model/Labyrinth.hpp
        include/model/Player.hpp
        include/utils/PathFinding.hpp
        include/view/GameView.hpp
        include/model/Cell.hpp
)

add_executable(Labyrinth_Jungle_2024
        src/main.cpp
        ${MODEL_SOURCES}
        ${VIEW_SOURCES}
        ${CONTROLLER_SOURCES}
        ${UTILS_SOURCES}
)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
target_link_libraries(Labyrinth_Jungle_2024 sfml-graphics sfml-audio)
