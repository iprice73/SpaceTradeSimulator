cmake_minimum_required(VERSION 3.10)
project(SpaceTradeSimulator)

set(SRC
    main.cpp
    Alcohol.cpp
    Item.cpp
    Spice.cpp
    Store.cpp
)


add_executable(${PROJECT_NAME} ${SRC})
