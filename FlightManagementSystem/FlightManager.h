#ifndef AEDPROJ2_FLIGHTMANAGER_H
#define AEDPROJ2_FLIGHTMANAGER_H

#include "Airport.h"
#include "Airline.h"
#include "Graph.h"
#include <unordered_map>

class FlightManager {
private:
    Graph<Airport> flights;
    std::unordered_map<std::string, Airline> airlines;
    std::unordered_map<std::string, Airport> airports;
    void load();
public:
    FlightManager();
    void addAirport(const Airport& airport);
    void addFlight(const Airport& source, const Airport& dest, std::string& airline);
    void addAirline(const Airline& airline);
    Airport getAirport(std::string code);
    std::unordered_map<std::string, Airline> getAirlines();
    std::unordered_map<std::string, Airport> getAirports();

};


#endif //AEDPROJ2_FLIGHTMANAGER_H
