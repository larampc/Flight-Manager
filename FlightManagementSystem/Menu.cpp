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
            makeFlightRequest();
            break;
        case '2':
            getDiameter();
            break;
        case '3': {
            settings();
            break;
        }
    }
}

void Menu::makeFlightRequest() {
    pair<int, vector<Vertex<Airport>*>> p = flightManager.diameter();
    cout << "\n" << p.first;
    cout << "\n" << p.second[0]->getInfo().getCode();
    cout << "\n" << p.second[1]->getInfo().getCode();
    cout << "\n" << flightManager.minDistanceAirportsbfs(p.second[0], p.second[1]);
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
    cout << flightManager.diameter().first;

}
