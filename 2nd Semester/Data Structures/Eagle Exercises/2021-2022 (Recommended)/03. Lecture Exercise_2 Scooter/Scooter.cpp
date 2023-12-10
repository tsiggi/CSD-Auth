#include "Scooter.h"

Scooter::Scooter() {
    this->max_kilometers = 0;
    this->release_year = 0;
}

Scooter::Scooter(int km, int y) {
    this->max_kilometers = km;
    this->release_year = y;
}

int Scooter::getMaxKM() {
    return this->max_kilometers;
}

int Scooter::getYear() {
    return this->release_year;
}

double Scooter::getPollutionScore() {
    // Pollution Score for Scooter
    // pollutionScore =  (  max_kilometers * average_number_of_fuel_fill=250 (given)  ) / days_of_the_year=365
    return (this->max_kilometers * 250.0) / 365.0;
}

double Scooter::getTaxes() {
    // Scooter Taxes
    // years_on_the_streets = 2022 - release_year
    // Taxes = years_on_the_streets * 12.5
    return (2022 - release_year) * 12.5;
}

