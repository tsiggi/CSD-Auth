#include "ElectricalScooter.h"

ElectricalScooter::ElectricalScooter():Scooter() {
    this->charging_time_mins = 0;
}

ElectricalScooter::ElectricalScooter(int km, int y, int t):Scooter(km, y) {
    this->charging_time_mins = t;
}

int ElectricalScooter::getMaxKM() {
    return Scooter::getMaxKM();
}

int ElectricalScooter::getYear() {
    return Scooter::getYear();
}

int ElectricalScooter::getChargingTime() {
    return this->charging_time_mins;
}

void ElectricalScooter::setChargingTime(int charging_time_mins) {
    this->charging_time_mins = charging_time_mins;
}

double ElectricalScooter::getPollutionScore() {
    // Pollution Score for ElectricalScooter
    // pollutionScore =  (  charging_time_mins * average_charging_times=300 (given)  ) / days_of_the_year=365
    return (this->charging_time_mins * 300) / 365.0;
}

double ElectricalScooter::getTaxes() {
    // ElectricalScooter Taxes = 80% of Scooter Taxes with the same maxKm and release_year
    return 0.8 * Scooter::getTaxes();
}
