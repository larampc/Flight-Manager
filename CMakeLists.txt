cmake_minimum_required(VERSION 3.26)
project(AEDproj2)

set(CMAKE_CXX_STANDARD 17)

# Doxygen Build
find_package(Doxygen)
if(DOXYGEN_FOUND)
    set(BUILD_DOC_DIR "${CMAKE_SOURCE_DIR}/docs/output")
    if(NOT EXISTS "${BUILD_DOC_DIR}")
        file(MAKE_DIRECTORY "${BUILD_DOC_DIR}")
    endif()

    set(DOXYGEN_IN "${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile")
    set(DOXYGEN_OUT "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile")
    configure_file("${DOXYGEN_IN}" "${DOXYGEN_OUT}" @ONLY)

    message("Doxygen build started")
    add_custom_target(Doxygen ALL
            COMMAND "${DOXYGEN_EXECUTABLE}" "${DOXYGEN_OUT}"
            WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM)
else(DOXYGEN_FOUND)
    message("Doxygen needs to be installed to generate the documentation.")
endif(DOXYGEN_FOUND)

add_executable(AEDproj2 main.cpp
        FlightManagementSystem/Graph.h
        FlightManagementSystem/Airport.h
        FlightManagementSystem/Airport.cpp
        FlightManagementSystem/Airline.cpp
        FlightManagementSystem/Airline.h
        FlightManagementSystem/FlightManager.cpp
        FlightManagementSystem/FlightManager.h
        FlightManagementSystem/Menu.cpp
        FlightManagementSystem/Menu.h
        FlightManagementSystem/color_print.cpp
        FlightManagementSystem/color_print.h
        FlightManagementSystem/Flight.cpp
        FlightManagementSystem/Flight.h
)
