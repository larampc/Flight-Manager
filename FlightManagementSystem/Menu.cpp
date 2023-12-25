#include "Menu.h"
#include <iostream>
#include <limits>
#include "color_print.h"
using namespace std;
extern bool color_mode;

void invalid(){
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    Color_Print("red", "Invalid Input, please try again\n");
}
void Menu::run() {
    Color_Print("blue", "-----------------------------------\n");
    Color_Print("blue", "\tFlight Management System\n");
    Color_Print("blue", "-----------------------------------\n");
    Color_Print("blue", "Select option:\n");
    Color_Print("white", "Get Information");
    Color_Print("cyan", " - press 1\n");
    Color_Print("white", "Make requests");
    Color_Print("cyan", " - press 2\n");
    Color_Print("white", "Settings");
    Color_Print("cyan", " - press 3\n");
    Color_Print("red", "Quit Manager");
    Color_Print("cyan", " - press 4\n");
    string option; cin >> option;
    while(option != "1" && option != "2" && option != "3" && option != "4") {
        invalid();
        cin >> option;
    }
    switch (option[0]) {
        case '1':
            getInformation();
            break;
        case '2':
            getDiameter();
            break;
        case '3':
            settings();
            break;
    }
}


void Menu::settings() {
    string option;
    Color_Print("cyan", "1- ");
    if (color_mode) Color_Print("yellow", "Disable");
    else Color_Print("yellow", "Enable");
    Color_Print("white", " Color Mode\t");
    Color_Print("cyan", "2- ");
    Color_Print("red", "Cancel\n");

    cin >> option;
    while(option != "1" && option != "2") {
        invalid();
        cin >> option;
    }
    if (option == "1") {
        color_mode = !color_mode;
        if (color_mode) Color_Print("cyan", "Color mode enabled\n");
        else Color_Print("cyan", "Color mode disabled\n");
    }
    run();
}

void Menu::getDiameter() {
    pair<int, vector<pair<Vertex<Airport>*, Vertex<Airport>*>>> temp = flightManager.diameter();
//    cout << flightManager.diameter().first;                                                              !!! TEMPORARY COUTS !!!
    cout << temp.first << endl;                                                                         // !!! TEMPORARY COUTS !!!
    for (auto pair: temp.second) {                                                             // !!! TEMPORARY COUTS !!!
        cout << pair.first->getInfo().getCode() << " - " << pair.second->getInfo().getCode() << endl;  // !!! TEMPORARY COUTS !!!
    }                                                                                                  // !!! TEMPORARY COUTS !!!
}

void Menu::getInformation() {
    Color_Print("blue", "Select option:\n");
    Color_Print("white", "Global number of airports");
    Color_Print("cyan", " - press 1\n");
    Color_Print("white", "Number of flights");
    Color_Print("cyan", " - press 2\n");
    Color_Print("white", "Number of destinations");
    Color_Print("cyan", " - press 3\n");
    Color_Print("white", "Number of airlines flying out of an airport");
    Color_Print("cyan", " - press 4\n");
    Color_Print("white", "Maximum trip");
    Color_Print("cyan", " - press 5\n");
    Color_Print("white", "Airport with the greatest air traffic capacity");
    Color_Print("cyan", " - press 6\n");
    Color_Print("white", "Essential Airport's to the network’s circulation capability");
    Color_Print("cyan", " - press 7\n");
    Color_Print("red", "Cancel");
    Color_Print("cyan", " - press 8\n");
    string option; cin >> option;
    while(option != "1" && option != "2" && option != "3" && option != "4" && option != "5"&& option != "6"&& option != "7"  && option != "8") {
        invalid();
        cin >> option;
    }
    switch (option[0]) {
        case '1':
            Color_Print("white", "Number of airports");
            Color_Print("cyan", to_string(flightManager.countAirports()));
            break;
        case '2':
            getFlightNumbers();
            break;
        case '3':
            getDestinations();
            break;
        case '4':
            getAirlinesAirport();
            break;
        case '5':
            Color_Print("white", "Maximum trip: ");
            break;
        case '8':
            run();
    }
}

void Menu::getFlightNumbers() {
    Color_Print("blue", "Select option:\n");
    Color_Print("white", "Number of available flights");
    Color_Print("cyan", " - press 1\n");
    Color_Print("white", "Number of flights out of an airport");
    Color_Print("cyan", " - press 2\n");
    Color_Print("white", "Number of flights per city");
    Color_Print("cyan", " - press 3\n");
    Color_Print("white", "Number of flights per airline");
    Color_Print("cyan", " - press 4\n");
    Color_Print("red", "Cancel");
    Color_Print("cyan", " - press 5\n");
    string option; cin >> option;
    while(option != "1" && option != "2" && option != "3" && option != "4" && option != "5") {
        invalid();
        cin >> option;
    }
    switch (option[0]) {
        case '1':
            Color_Print("white", "Number of available flights: ");
            Color_Print("cyan", to_string(flightManager.countFlights()) + "\n");
            break;
        case '2':
            getFlightsAirport();
            break;
        case '3':
            getFlightsCity();
            break;
        case '4':
            getFlightsAirline();
            break;
        case '5':
            run();
    }
}

void Menu::getFlightsAirport() {
    Color_Print("blue", "Select option:\n");
    Color_Print("white", "List all airports");
    Color_Print("cyan", " - press 1\n");
    Color_Print("white", "Choose an airport");
    Color_Print("cyan", " - press 2\n");
    Color_Print("red", "Cancel");
    Color_Print("cyan", " - press 3\n");
    string option; cin >> option;
    while(option != "1" && option != "2" && option != "3") {
        invalid();
        cin >> option;
    }
    string airportCode;
    switch (option[0]) {
        case '1':
            for (auto f: flightManager.getAirports()) {
                cout << f.first << " " << flightManager.countFlightsFromAirport(f.first) << endl;
            }
            break;
        case '2':
            Color_Print("cyan", "Airport code: \n");
            cin >> airportCode;
            cout << flightManager.countFlightsFromAirport(airportCode) << endl;
            break;
        case '3':
            run();
    }
}

void Menu::getFlightsCity() {
    Color_Print("blue", "Select option:\n");
    Color_Print("white", "List all cities");
    Color_Print("cyan", " - press 1\n");
    Color_Print("white", "Choose a city");
    Color_Print("cyan", " - press 2\n");
    Color_Print("red", "Cancel");
    Color_Print("cyan", " - press 3\n");
    string option; cin >> option;
    while(option != "1" && option != "2" && option != "3") {
        invalid();
        cin >> option;
    }
    string cityName;
    switch (option[0]) {
        case '1':
            for (auto f: flightManager.getCityAirports()) {
                cout << f.first << " " << flightManager.countFlightsPerCity(f.first) << endl;
            }
            break;
        case '2':
            Color_Print("cyan", "City name: \n");
            cin >> cityName;
            cout << flightManager.countFlightsPerCity(cityName) << endl;
            break;
        case '3':
            run();
    }
}

void Menu::getFlightsAirline() {
    Color_Print("blue", "Select option:\n");
    Color_Print("white", "List all airlines");
    Color_Print("cyan", " - press 1\n");
    Color_Print("white", "Choose an airline");
    Color_Print("cyan", " - press 2\n");
    Color_Print("red", "Cancel");
    Color_Print("cyan", " - press 3\n");
    string option; cin >> option;
    while(option != "1" && option != "2" && option != "3") {
        invalid();
        cin >> option;
    }
    string airlineCode;
    switch (option[0]) {
        case '1':
            for (const auto& f: flightManager.getAirlines()) {
                cout << f.first << " " << flightManager.countFlightsPerAirline(f.first) << endl;
            }
            break;
        case '2':
            Color_Print("cyan", "Airline code: \n");
            cin >> airlineCode;
            cout << flightManager.countFlightsPerAirline(airlineCode) << endl;
            break;
        case '3':
            run();
    }
}

void Menu::getDestinations() {
    Color_Print("blue", "Select option:\n");
    Color_Print("white", "Number of reachable countries from a city");
    Color_Print("cyan", " - press 1\n");
    Color_Print("white", "Number of reachable countries from an airport");
    Color_Print("cyan", " - press 2\n");
    Color_Print("white", "Number of reachable airports from an airport");
    Color_Print("cyan", " - press 3\n");
    Color_Print("white", "Number of reachable cities from an airport");
    Color_Print("cyan", " - press 4\n");
    Color_Print("red", "Cancel");
    Color_Print("cyan", " - press 5\n");
    string option; cin >> option;
    while(option != "1" && option != "2" && option != "3" && option != "4" && option != "5") {
        invalid();
        cin >> option;
    }
    switch (option[0]) {
        case '1':
            getCountriesCity();
            break;
        case '2':
            getCountriesAirport();
            break;
        case '3':
            getAirportsAirport();
            break;
        case '4':
            getCitiesAirport();
            break;
        case '5':
            run();
    }
}

void Menu::getCountriesCity() {
    Color_Print("white", "City name: \n");
    string cityName; cin >> cityName;
    Color_Print("white", "Number of reachable countries: ");
    Color_Print("cyan", to_string(flightManager.countCountriesFromCity(cityName)));
}

void Menu::getCountriesAirport() {
    Color_Print("white", "Airport code: \n");
    string airportCode; cin >> airportCode;
    Color_Print("white", "Do you want to specify the maximum number of stops? [Y/N] \n");
    string option; cin >> option;
    while(option != "Y" && option != "N") {
        invalid();
        cin >> option;
    }
    int k;
    switch (option[0]) {
        case 'Y':
            Color_Print("white", "Number of stops: ");
            cin >> k;
            Color_Print("white", "Number of reachable countries: ");
            Color_Print("cyan", to_string(flightManager.countCountriesKStops(airportCode, k)));
            break;
        case 'N':
            Color_Print("white", "Number of reachable countries: ");
            Color_Print("cyan", to_string(flightManager.countCountriesFromAirport(airportCode)));
    }
}

void Menu::getAirportsAirport() {
    Color_Print("white", "Airport code: \n");
    string airportCode; cin >> airportCode;
    Color_Print("white", "Do you want to specify the maximum number of stops? [Y/N] \n");
    string option; cin >> option;
    while(option != "Y" && option != "N") {
        invalid();
        cin >> option;
    }
    int k;
    switch (option[0]) {
        case 'Y':
            Color_Print("white", "Number of stops: ");
            cin >> k;
            Color_Print("white", "Number of reachable airports: ");
            Color_Print("cyan", to_string(flightManager.countAirportsKStops(airportCode, k)));
            break;
        case 'N':
            Color_Print("white", "Number of reachable airports: ");
            Color_Print("cyan", to_string(flightManager.countAirportsFromAirport(airportCode)));
    }
}

void Menu::getCitiesAirport() {
    Color_Print("white", "Airport code: \n");
    string airportCode; cin >> airportCode;
    Color_Print("white", "Do you want to specify the maximum number of stops? [Y/N] \n");
    string option; cin >> option;
    while(option != "Y" && option != "N") {
        invalid();
        cin >> option;
    }
    int k;
    switch (option[0]) {
        case 'Y':
            Color_Print("white", "Number of stops: ");
            cin >> k;
            Color_Print("white", "Number of reachable cities: ");
            Color_Print("cyan", to_string(flightManager.countCitiesKStops(airportCode, k)));
            break;
        case 'N':
            Color_Print("white", "Number of reachable cities: ");
            Color_Print("cyan", to_string(flightManager.countCitiesFromAirport(airportCode)));
    }
}

void Menu::getAirlinesAirport() {
    Color_Print("white", "Airport code: \n");
    string airportCode; cin >> airportCode;
    Color_Print("white", "Number of airlines: ");
    Color_Print("cyan", to_string(flightManager.countAirlinesFromAirport(airportCode)));
}

