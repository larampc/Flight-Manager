#ifndef AEDPROJ2_FLIGHT_H
#define AEDPROJ2_FLIGHT_H

#include <string>
#include "Airport.h"
#include "Airline.h"

class Flight {
private:
    Airport source;
    Airport dest;
    Airline airline;
public:
    Airport getSource();
    Airport getDest();
    Airline getAirline();
};


#endif //AEDPROJ2_FLIGHT_H
