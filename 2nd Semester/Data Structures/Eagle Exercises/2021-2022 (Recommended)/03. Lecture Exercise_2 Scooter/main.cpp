#include "Scooter.h"
#include "ElectricalScooter.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Declaration of test functions
void testDefaultConstructors();
void testGetPollutionScore();
void testGetTaxes();
void testInheritance();

// global input variables
int maxKM1, year1, maxKM2, year2, chargingTime;

// main
int main(int argc, char const *argv[])
{
    // The numbers will be printed with 1 decimal digit by default (see here https://www.cplusplus.com/reference/ios/fixed/)
    cout << fixed << setprecision(1);

    //clog is commonly used for logging purposes. It is used here instead of cout just for eagle-related purposes
    clog << "Scooter maxKM: ";
    cin >> maxKM1;
    clog << "Scooter year: ";
    cin >> year1;
    clog << "Electrical Scooter maxKM: ";
    cin >> maxKM2;
    clog << "Electrical Scooter year: ";
    cin >> year2;
    clog << "Electrical Scooter charging time (mins): ";
    cin >> chargingTime;

    testDefaultConstructors();
    testGetPollutionScore();
    testGetTaxes();
    testInheritance();

    return 0;
}

// Implementation of test functions
void testDefaultConstructors()
{
    cout << ">> Test DefaultConstructors" << endl;
    Scooter scooter;
    ElectricalScooter eScooter;
    cout << "getMaxKM: " << scooter.getMaxKM() << endl;
    cout << "getYear: " << scooter.getYear() << endl;
    cout << "getMaxKM: " << eScooter.getMaxKM() << endl;
    cout << "getYear: " << eScooter.getYear() << endl;
    cout << "getChargingTime: " << eScooter.getChargingTime() << endl;
}

void testGetPollutionScore()
{
    cout << ">> Test GetPollutionScore" << endl;
    Scooter scooter1(maxKM1, year1);
    double actual = scooter1.getPollutionScore();
    cout << "getPollutionScore test1: " << actual << endl;

    Scooter scooter2(maxKM1 + 100, year1 - 10);
    actual = scooter2.getPollutionScore();
    cout << "getPollutionScore test2: " << actual << endl;

    ElectricalScooter eScooter1(maxKM2, year2, chargingTime);
    actual = eScooter1.getPollutionScore();
    cout << "getPollutionScore test3: " << actual << endl;

    ElectricalScooter eScooter2(maxKM2 + 50, year2 - 2, chargingTime - 10);
    actual = eScooter2.getPollutionScore();
    cout << "getPollutionScore test4: " << actual << endl;
}

void testGetTaxes()
{
    cout << ">> Test GetTaxes" << endl;
    Scooter scooter1(maxKM1, year1);
    double actual = scooter1.getTaxes();
    cout << "getTaxes test1: " << actual << endl;

    Scooter scooter2(maxKM1 + 100, year1 - 10);
    actual = scooter2.getTaxes();
    cout << "getTaxes test2: " << actual << endl;

    ElectricalScooter eScooter1(maxKM2, year2, chargingTime);
    actual = eScooter1.getTaxes();
    cout << "getTaxes test3: " << actual << endl;

    ElectricalScooter eScooter2(maxKM2 + 50, year2 - 2, chargingTime - 10);
    actual = eScooter2.getTaxes();
    cout << "getTaxes test4: " << actual << endl;
}

void testInheritance()
{
    cout << ">> Test Inheritance" << endl;
    Scooter *s = new ElectricalScooter(maxKM1, year1, chargingTime);
    cout << "getTaxes test1: " << s->getTaxes() << endl;
    delete s;
}