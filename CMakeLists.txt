cmake_minimum_required(VERSION 3.26)
project(AEDproj2)

set(CMAKE_CXX_STANDARD 17)

add_executable(AEDproj2 main.cpp
        FlightManagementSystem/Graph.h
        FlightManagementSystem/Airport.h
        FlightManagementSystem/Airport.cpp
        FlightManagementSystem/Airline.cpp
        FlightManagementSystem/Airline.h
        FlightManagementSystem/FlightManager.cpp
        FlightManagementSystem/FlightManager.h
        FlightManagementSystem/Loader.cpp)
