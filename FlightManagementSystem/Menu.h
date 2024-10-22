#ifndef AEDPROJ2_MENU_H
#define AEDPROJ2_MENU_H

#include "FlightManager.h"

/**
 * \mainpage Welcome to the Air Travel Flight Management Program
 *
 * \section description_sec Project description
 *
 * This program was made for AED course unit of Bachelor in Informatics and Computing Engineering at FEUP.
 * This program allows to visualize flights and related information n in an intuitive and accessible manner .
 *
 * \section utility_sec What can this project do?
 *

 * Get information such as:
 * - Schedules of a student, class or UC;
 * - List of students in a course, class or UC sorted by student UP or number;
 * - List of course, year, UC or class occupations sorted by class code or occupation (descending or ascending order);
 * - List of students with at least N UCs.

 * Make requests such as:
 * - add or remove a student;
 * - add, remove or switch UC/class of a given student;
 * - upload files with the desired operations;
 * - undo the previous operation;
 * - check pending requests;
 * - process next request or all pending requests;
 * - erase pending requests.

 * Change settings such enabling colour mode.
 */

/**
 * \class Menu
 * \brief This class handles and runs the different commands.
 *
 * This class has the FlightManager flightManager and different functions to analyze and get information from the data.
 * It is also responsible for handling inputs and outputs.
 */
class Menu {
private:
    FlightManager flightManager;
public:
    /**
     * \brief Outputs the main menu and handles the respective inputs.
     */
    void run();
    /**
     * \brief Outputs the flights information menu and handles the respective inputs.
     */
    void getInformation();
    /**
     * \brief Outputs the flights numbers menu and handles the respective inputs.
     */
    void getFlightNumbers();
    /**
     * \brief Outputs the flights out of airport menu and handles the respective inputs.
     */
    void getFlightsAirport();
    void getFlightsCity();
    void getFlightsAirline();
    void getDestinations();
    void getCountriesCity();
    void getCountriesAirport();
    void getAirportsAirport();
    void getCitiesAirport();
    void getAirlinesAirport();
    void settings();
    void getDiameter();
    void getEssentialAirports();
    void getKAirportTraffic();
    void getRequest();
    void requestFromAirportCodeToAirportCode();
};


#endif //AEDPROJ2_MENU_H
