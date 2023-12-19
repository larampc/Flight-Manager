#ifndef AEDPROJ2_AIRLINE_H
#define AEDPROJ2_AIRLINE_H

#include <string>

class Airline {
private:
    std::string code;
    std::string name;
    std::string callSign;
    std::string country;
public:
    Airline(std::string code, std::string name, std::string callSign, std::string country):
    code(code), name(name), callSign(callSign), country(country) {};
    std::string getCode() const;
    std::string getName() const;
    std::string getCallSign() const;
    std::string getCountry() const;
    friend std::ostream & operator << (std::ostream &os, Airline &p);
};


#endif //AEDPROJ2_AIRLINE_H
