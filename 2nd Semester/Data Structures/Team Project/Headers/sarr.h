//Υλοποίηση 2) ταξινομημένος πίνακας
#ifndef sarr_h
#define sarr_h
#include "arr.h"
class sarr : public arr
{
public:
    sarr():arr(){}; //μπορεί και να μην χρειάζεται
    void insert(string&, int);
    void insert(string&);
    bool find(string&, int&);
    void del(string&);
    int binarySearch(word *b, string &s, int low, int high);
};
#endif
