#include "Menu.h"
#include <iostream>
#include <limits>
using namespace std;

void invalid(){
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid Input, please try again";
}
void Menu::run() {
    cout << "-----------------------------------\n";
    cout << "\tFlight Management System\n";
    cout << "-----------------------------------\n";
    cout << "Select option:\n";
    cout << "Get Information\n";
    cout << " - press 1\n";
    cout << "Quit Manager\n";
    cout << " - press 2\n";
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
