//Υλοποίηση 1) αταξινόμητος πίνακας
#ifndef arr_h
#define arr_h
#include "struct.h"
#include <iostream>
using namespace std;

class arr //κλάση αταξινόμητου
{
protected:
    int size;
    word *b;
    int c;
public:
    arr()
    {
        size=15000;
        b=new word[size];
        c=0;
    }
    ~arr()
    {
        delete [] b;
    }

    //αυτά θα φύγουν στην τελική έκδοση
    string getB(int i){return b[i].w;};
    int getT(int i){return b[i].t;};
    int getC(){return c;};
    //τέλος
    void increment(int);

    void print();

    virtual void insert(string&);
    virtual bool find(const string&, int&);
    virtual void del(const string&);
};
#endif
