#include "Airline.h"

std::string Airline::getCode() const {
    return code;
}

std::string Airline::getName() const {
    return name;
}

std::string Airline::getCallSign() const {
    return callSign;
}

std::string Airline::getCountry() const {
    return country;
}

std::ostream &operator<<(std::ostream &os, Airline &airline) {
    os << airline.code + " " + airline.name + " " + airline.callSign + " " + airline.country + "\n";
    return os;
}
