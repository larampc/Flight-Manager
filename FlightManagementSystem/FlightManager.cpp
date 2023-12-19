#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "FlightManager.h"

void FlightManager::addAirport(const Airport& airport) {
    flights.addVertex(airport);
    airports.insert(make_pair(airport.getCode(), airport));
}

void FlightManager::addFlight(const Airport& source, const Airport& dest, std::string& airline) {
    flights.addEdge(source, dest, airline);
}

void FlightManager::addAirline(const Airline& airline) {
    airlines.insert(make_pair(airline.getCode(), airline));
}

Airport FlightManager::getAirport(std::string code) {
    return airports.at(code);
}

void FlightManager::load() {
    ifstream airportsFile("../airports.csv");
    string line;
    getline(airportsFile, line);
    while (getline(airportsFile, line)) {
        string code, name, city, country, latitude, longitude;
        istringstream iss(line);
        getline(iss, code, ',');
        getline(iss, name, ',');
        getline(iss, city, ',');
        getline(iss, country, ',');
        getline(iss, latitude, ',');
        iss >> longitude;
        addAirport(Airport(code,name,city,country, stod(latitude),stod(longitude)));
    }
    airportsFile.close();

    ifstream airlinesFile("../airlines.csv");
    getline(airlinesFile, line);
    while (getline(airlinesFile, line)) {
        string code, name, callSign, country;
        istringstream iss(line);
        getline(iss, code, ',');
        getline(iss, name, ',');
        getline(iss, callSign, ',');
        iss >> country;
        addAirline(Airline(code,name,callSign,country));
    }
    airlinesFile.close();

    ifstream flightsFile("../flights.csv");
    getline(flightsFile, line);
    while (getline(flightsFile, line)) {
        string source, target, airline;
        istringstream iss(line);
        getline(iss, source, ',');
        getline(iss, target, ',');
        iss >> airline;
        addFlight(getAirport(source),getAirport(target),airline);
    }
    flightsFile.close();
}

FlightManager::FlightManager() {
    load();
}

std::unordered_map<std::string, Airline> FlightManager::getAirlines() {
    return airlines;
}

std::unordered_map<std::string, Airport> FlightManager::getAirports() {
    return airports;
}
