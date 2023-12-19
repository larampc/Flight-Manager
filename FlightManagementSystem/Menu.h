#ifndef AEDPROJ2_MENU_H
#define AEDPROJ2_MENU_H

#include "FlightManager.h"

class Menu {
private:
    FlightManager flightManager;
public:
    void run();
    void makeFlightRequest();
    void settings();
};


#endif //AEDPROJ2_MENU_H
