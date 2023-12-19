#include "Loader.h"

Loader::Loader(){
    FlightManager flightManager = FlightManager();
    ifstream airports("../airports.csv");
    string line;
    getline(airports, line);
    while (getline(airports, line)) {
        string code, name, city, country, latitude, longitude;
        istringstream iss(line);
        getline(iss, code, ',');
        getline(iss, name, ',');
        getline(iss, city, ',');
        getline(iss, country, ',');
        getline(iss, latitude, ',');
        iss >> longitude;
        flightManager.addAirport(Airport(code,name,city,country, stod(latitude),stod(longitude)));
    }
    airports.close();

    ifstream airlines("../airlines.csv");
    getline(airlines, line);
    while (getline(airlines, line)) {
        string code, name, callSign, country;
        istringstream iss(line);
        getline(iss, code, ',');
        getline(iss, name, ',');
        getline(iss, callSign, ',');
        iss >> country;
    }
    airlines.close();

    ifstream flights("../flights.csv");
    getline(flights, line);
    while (getline(flights, line)) {
        string source, target, airline;
        istringstream iss(line);
        getline(iss, source, ',');
        getline(iss, target, ',');
        iss >> airline;
    }
    flights.close();
}
