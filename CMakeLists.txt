cmake_minimum_required(VERSION 3.26)
project(AEDproj2)

set(CMAKE_CXX_STANDARD 17)

add_executable(AEDproj2 main.cpp
        FlightManager/Graph.h
        FlightManager/Airport.h
        FlightManager/Airport.cpp
        FlightManager/Airline.cpp
        FlightManager/Airline.h)
