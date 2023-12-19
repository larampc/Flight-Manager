#include "Airport.h"
#include <cmath>

using namespace std;

string Airport::getCode() const {
    return code;
}

string Airport::getName() const {
    return name;
}

string Airport::getCity() const {
    return city;
}

string Airport::getCountry() const {
    return country;
}

double Airport::getLatitude() const {
    return latitude;
}

double Airport::getLongitude() const {
    return longitude;
}

double Airport::getDistance(double lat, double lon) {
    double dLat = (lat - latitude) *
                  M_PI / 180.0;
    double dLon = (lon - longitude) *
                  M_PI / 180.0;

    double lat1 = (latitude) * M_PI / 180.0;
    lat = (lat) * M_PI / 180.0;

    double a = pow(sin(dLat / 2), 2) +
               pow(sin(dLon / 2), 2) *
               cos(lat1) * cos(lat);
    double rad = 6371;
    double c = 2 * asin(sqrt(a));
    return rad * c;
}
