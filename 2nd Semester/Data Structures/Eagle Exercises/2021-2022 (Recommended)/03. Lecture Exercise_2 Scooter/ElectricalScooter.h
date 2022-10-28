#ifndef ELECTRICALSCOOTER_H
#define ELECTRICALSCOOTER_H

#include "Scooter.h"

class ElectricalScooter:public Scooter {
private:
    int charging_time_mins;
public:
    ElectricalScooter();
    ElectricalScooter(int,int,int);
    int getMaxKM();
    int getYear();
    int getChargingTime();
    void setChargingTime(int);
    double getPollutionScore();
    double getTaxes();
};


#endif //ELECTRICALSCOOTER_H
