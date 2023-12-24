#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <unordered_set>
#include <iostream>
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
        auto cityIt = cityAirports.find(city);
        if ( cityIt == nullptr) {
            cityAirports.insert(make_pair(city, vector<Airport*>{&airports.at(code)}));
        }
        else cityIt->second.push_back(&airports.at(code));
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

int FlightManager::countFlightsFromAirport(std::string airport) {
    return flights.findVertex(airports.at(airport))->getAdj().size();
}

int FlightManager::countAirlinesFromAirport(std::string airport) {
    Vertex<Airport>* airportVertex = flights.findVertex(airports.at(airport));
    unordered_set<std::string> airline;
    for(Edge<Airport> e: airportVertex->getAdj()) {
        airline.insert(e.getWeight());
    }
    return airline.size();
}

int FlightManager::countFlightsPerAirline(std::string code) const {
    int count = 0;
    for(Vertex<Airport>* v : flights.getVertexSet()){
        vector<Edge<Airport>> adjs = v->getAdj();
        count += count_if(adjs.begin(),adjs.end(),[code](const Edge<Airport>& e){
            return e.getWeight()==code;
        });
    }
    return count;
}

int FlightManager::countFlightsPerCity(std::string city) const {
    int count = 0;
    vector<Airport*> airportsInCity = cityAirports.at(city);
    for(Airport* a : airportsInCity){
        auto it = flights.findVertex(*a);
        count += it->getAdj().size();
    }
    for(Vertex<Airport>* v : flights.getVertexSet()){
        vector<Edge<Airport>> adjs = v->getAdj();
        if(v->getInfo().getCity() != city){
            count += count_if(adjs.begin(),adjs.end(),[city](const Edge<Airport>& e){
                return e.getDest()->getInfo().getCity() == city ;
            });
        }
    }
    return count;
}

int FlightManager::countCountriesFromAirport(std::string airport) {
    Vertex<Airport>* airportVertex = flights.findVertex(airports.at(airport));
    unordered_set<std::string> countries;
    for(Edge<Airport> e: airportVertex->getAdj()) {
        countries.insert(e.getDest()->getInfo().getCountry());
    }
    return countries.size();
}

int FlightManager::countAirports() {
    return flights.getVertexSet().size();
}
int FlightManager::countFlights() {
    int res = 0;
    for (auto airport: flights.getVertexSet()) {
        res += airport->getAdj().size();
    }
    return res;
}

int FlightManager::countCountriesFromCity(std::string city) {
    unordered_set<std::string> countries;
    for (Airport* air: cityAirports.at(city)) {
        Vertex<Airport>* airportVertex = flights.findVertex(*air);
        for(Edge<Airport> e: airportVertex->getAdj()) {
            countries.insert(e.getDest()->getInfo().getCountry());
        }
    }
    return countries.size();
}

int FlightManager::countAirportsFromAirport(std::string airport) {
    Vertex<Airport>* airportVertex = flights.findVertex(airports.at(airport));
    unordered_set<std::string> codes;
    for (Edge<Airport> e: airportVertex->getAdj()) {
        codes.insert(e.getDest()->getInfo().getCode());
    }
    return codes.size();
}

int FlightManager::countCitiesFromAirport(std::string airport) {
    Vertex<Airport>* airportVertex = flights.findVertex(airports.at(airport));
    unordered_set<std::string> cities;
    for (Edge<Airport> e: airportVertex->getAdj()) {
        cities.insert(e.getDest()->getInfo().getCity());
    }
    return cities.size();
}

int FlightManager::countAirportsKStops(std::string airport, int k) {
    for (Vertex<Airport>* v: flights.getVertexSet()) {
        v->setVisited(false);
    }
    Vertex<Airport>* start = flights.findVertex(airports.at(airport));
    queue<pair<int, Vertex<Airport>*>> tovisit;
    unordered_set<std::string> airportsVisited;
    int count = 0;
    start->setVisited(true);
    tovisit.emplace(0,start);
    if (k == 0) {
        return count;
    }
    while (!tovisit.empty()) {
        Vertex<Airport>* tocheck = tovisit.front().second;
        for (Edge<Airport> e: tocheck->getAdj()) {
            Vertex<Airport>* v = e.getDest();
            if (!v->isVisited()) {
                v->setVisited(true);
                if (tovisit.front().first+1>k) return count;
                tovisit.emplace(tovisit.front().first+1, v);
                count++;
            }
        }
        tovisit.pop();
    }
    return count;
}

int FlightManager::minDistanceAirports(std::string airportStart, std::string airportEnd) {
    Vertex<Airport>* start = flights.findVertex(airports.at(airportStart));
    Vertex<Airport>* end = flights.findVertex(airports.at(airportEnd));
    return minDistanceAirportsbfs(start, end);
}

int FlightManager::minDistanceAirportsbfs(Vertex<Airport>* airportStart, Vertex<Airport>* airportEnd) {
    int res = 0;
    if (airportStart == airportEnd) return 0;
    queue<pair<int, Vertex<Airport>*>> q;
    for (auto v : flights.getVertexSet())
        v->setVisited(false);
    q.emplace(0, airportStart);
    airportStart->setVisited(true);
    while (!q.empty()) {
        Vertex<Airport>* tocheck = q.front().second;
        for (Edge<Airport> e: tocheck->getAdj()) {
            Vertex<Airport>* v = e.getDest();
            if (!v->isVisited()) {
                v->setVisited(true);
                if (v == airportEnd) {
                    res = q.front().first + 1;
                    return res;
                }
                q.emplace(q.front().first+1, v);
            }
        }
        q.pop();
    }
    return res;
}

pair<int, vector<Vertex<Airport>*>> FlightManager::diameter() {
    int max = 0;
    Vertex<Airport>* start;
    Vertex<Airport>* end;
    for (Vertex<Airport>* v1: flights.getVertexSet()) {
        queue<pair<int, Vertex<Airport>*>> q;
        for (auto v : flights.getVertexSet())
            v->setVisited(false);
        q.emplace(0, v1);
        v1->setVisited(true);
        while (!q.empty()) {
            Vertex<Airport>* tocheck = q.front().second;
            for (Edge<Airport> e: tocheck->getAdj()) {
                Vertex<Airport>* v = e.getDest();
                if (!v->isVisited()) {
                    v->setVisited(true);
                    if (q.front().first+1 > max) {
                        max = q.front().first+1;
                        start = v1;
                        end = v;
                    }
                    q.emplace(q.front().first+1, v);
                }
            }
            q.pop();
        }
    }
    vector<Vertex<Airport>*> vec;
    vec.push_back(start);
    vec.push_back(end);
    return make_pair(max, vec);
}

bool inStack(stack<Airport> s, Airport i) {
    while (!s.empty()) {
        if (s.top() == i) return true;
        s.pop();
    }
    return false;
}
void dfs_art(Graph<Airport>* g, Vertex<Airport> *v, stack<Airport> &s, vector<Airport> &l, int &i){
    v->setVisited(true);
    v->setLow(i);
    v->setNum(i);
    s.push(v->getInfo());
    int child = 0;
    for (Edge<Airport> e: v->getAdj()) {
        if (e.getDest()->getNum() == 0) {
            dfs_art(g, e.getDest(), s, l, ++i);
            v->setLow(min(e.getDest()->getLow(), v->getLow()));
            if (e.getDest()->getLow() >= v->getNum() && v->getLow() != v->getNum()) {
                l.push_back(v->getInfo());
            }
            child++;
        }
        else if (inStack(s, e.getDest()->getInfo())){
            v->setLow(min(e.getDest()->getNum(), v->getLow()));
        }
    }
    if (v->getLow() == v->getNum() && child > 1) {
        l.push_back(v->getInfo());
    }
}

vector<Airport> FlightManager::essentialAirports() {
    vector<Airport> res;
    for (Vertex<Airport>* v: flights.getVertexSet()) {
        v->setVisited(false);
        v->setLow(0);
        v->setNum(0);
    }
    stack<Airport> s;
    int ii = 1;
    for (Vertex<Airport>* v: flights.getVertexSet()) {
        if (!v->isVisited()) {
            dfs_art(&flights, v, s, res, ii);
        }
    }
    return res;
}


