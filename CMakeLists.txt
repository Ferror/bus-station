cmake_minimum_required(VERSION 3.14)
project(bus-station)

set(CMAKE_CXX_STANDARD 14)

add_executable(Clion
    main.c
    src/bus.c
    src/passenger.c
    header/passenger.h
    header/bus.h
)
