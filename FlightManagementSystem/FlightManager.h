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
    std::unordered_map<std::string, vector<Airport*>> cityAirports;
    void load();
public:
    FlightManager();
    void addAirport(const Airport& airport);
    void addFlight(const Airport& source, const Airport& dest, std::string& airline);
    void addAirline(const Airline& airline);
    Airport getAirport(std::string code);
    std::unordered_map<std::string, Airline> getAirlines();
    std::unordered_map<std::string, Airport> getAirports();
    int countFlightsPerAirline(std::string code) const;
    int countFlightsPerCity(std::string city) const;
    int countAirports();
    int countFlights();
    int countFlightsFromAirport(std::string airport);
    int countAirlinesFromAirport(std::string airport);
    int countCountriesFromAirport(std::string airport);
    int countCountriesFromCity(std::string city);
    int countAirportsFromAirport(std::string airport);
    int countCitiesFromAirport(std::string airport);
    int countAirportsKStops(std::string airport, int k);
    int minDistanceAirportsbfs(Vertex<Airport>* airportStart, Vertex<Airport>* airportEnd);
    int minDistanceAirports(std::string airportStart, std::string airportEnd);
    pair<int, vector<Vertex<Airport>*>> diameter();
    vector<Airport> essentialAirports();
};


#endif //AEDPROJ2_FLIGHTMANAGER_H
