#ifndef AEDPROJ2_FLIGHTMANAGER_H
#define AEDPROJ2_FLIGHTMANAGER_H

#include "Airport.h"
#include "Airport.h"
#include "Graph.h"

class FlightManager {
private:
    Graph<Airport> flights;
public:
    void addAirport(const Airport& airport);
//    void addFlight(const Airport source, const Airport dest, )
};


#endif //AEDPROJ2_FLIGHTMANAGER_H
