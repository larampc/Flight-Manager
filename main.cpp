#include <iostream>
#include "FlightManagementSystem/Airport.h"
#include "FlightManagementSystem/Loader.h"

int main() {
    Loader loader = Loader();
    Airport airport("bla", "", "", "", 49.0, 2.5);
    std::cout << airport.getDistance(48.0, 2.0) << std::endl;
    return 0;
}
