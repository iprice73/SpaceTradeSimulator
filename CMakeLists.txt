cmake_minimum_required(VERSION 3.10)
project(SpaceTradeSimulator)

set(CMAKE_CXX_STANDARD 17)
include_directories(inc)
include_directories(src)

set(SRC
    src/Alcohol.cpp
    src/Item.cpp
    src/Spice.cpp
    src/Store.cpp
    src/Player.cpp
    src/Ship.cpp
    src/StockManagement.cpp
    src/SolarSystem.cpp
    src/Planet.cpp
    src/Game.cpp
    src/Time.cpp
    src/Docks.cpp
)

set(FLAGS
    -Werror
    -Wall
    -pedantic
    -Wconversion
    -Wextra
)

add_library(${PROJECT_NAME}-lib STATIC ${SRC})

add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib)
target_compile_options(${PROJECT_NAME} PRIVATE ${FLAGS})
target_compile_options(${PROJECT_NAME}-lib PRIVATE ${FLAGS})
