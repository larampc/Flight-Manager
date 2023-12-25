#ifndef AEDPROJ2_MENU_H
#define AEDPROJ2_MENU_H

#include "FlightManager.h"

class Menu {
private:
    FlightManager flightManager;
public:
    void run();
    void getInformation();
    void getFlightNumbers();
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
};


#endif //AEDPROJ2_MENU_H
