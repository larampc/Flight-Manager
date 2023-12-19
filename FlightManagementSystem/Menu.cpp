#include "Menu.h"
#include <iostream>
#include <limits>
using namespace std;

void invalid(){
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid Input, please try again";
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
    while(option != "1" && option != "2") {
        invalid();
        cin >> option;
    }
//    switch (option[0]) {
//        case '1':
//            make_flight_request();
//    }
}
