#ifndef SCOOTER_H
#define SCOOTER_H


class Scooter {
private:
    int max_kilometers;
    int release_year;
public:
    Scooter();
    Scooter(int,int);

    virtual int getMaxKM();

    virtual int getYear();

    virtual double getPollutionScore();

    virtual double getTaxes();
};


#endif //SCOOTER_H
