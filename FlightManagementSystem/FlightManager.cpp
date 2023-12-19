//
// Created by larap on 19/12/2023.
//

#include "FlightManager.h"

void FlightManager::addAirport(const Airport& airport) {
    flights.addVertex(airport);
}
