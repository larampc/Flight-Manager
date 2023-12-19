#ifndef AEDPROJ2_AIRPORT_H
#define AEDPROJ2_AIRPORT_H

#include <string>

class Airport {
private:
    std::string code;
    std::string name;
    std::string city;
    std::string country;
    double latitude;
    double longitude;
public:
    Airport(std::string code, std::string name, std::string city, std::string country, double latitude, double longitude):
            code(code), name(name), city(city), country(country), latitude(latitude), longitude(longitude) {};
    std::string getCode() const;
    std::string getName() const;
    std::string getCity() const;
    std::string getCountry() const;
    double getLatitude() const;
    double getLongitude() const;
    double getDistance(double lat, double lon);
};

#endif //AEDPROJ2_AIRPORT_H
