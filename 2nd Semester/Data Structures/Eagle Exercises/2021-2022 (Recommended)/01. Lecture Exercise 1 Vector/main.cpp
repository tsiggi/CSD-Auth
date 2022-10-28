/**
 * **************** IMPORTANT! **************
 * ******* DO NOT MODIFY THIS FILE **********
 * **** DO NOT SUBMIT THIS FILE TO EAGLE ****
 * ******************************************
 */

#include <iostream>
#include <iomanip>
#include "Vector.h"

using namespace std;

// Helper function
void print(Vector v)
{
    cout << "(" << v.GetX() << "," << v.GetY() << ")" << endl;
}

/*******************************************************************
 *********************** Main function *****************************
 *******************************************************************/
int main(int argc, char const *argv[])
{
    double x, y, f;

    // read values for coordinates x, y, and f (multiply factor)
    cin >> x >> y >> f;

    // The numbers will be printed with 1 decimal digit by default (see here https://www.cplusplus.com/reference/ios/fixed/)
    cout << fixed << setprecision(1);

    /**
     ***********************************************************
     *********************** TEST CASE 1 ***********************
     ***********************************************************
     */
    cout << "TEST_CONSTRUCTORS" << endl;
    Vector a1, e1(x, y), b1;
    print(a1);
    print(b1);
    print(e1);

    /**
     ***********************************************************
     *********************** TEST CASE 2 ***********************
     ***********************************************************
     */
    cout << "TEST_GETTERS_SETTERS" << endl;
    Vector a2;
    a2.SetX(3);
    a2.SetY(4);
    print(a2);

    a2.SetX(5);
    a2.SetY(5);
    print(a2);

    /**
     ***********************************************************
     *********************** TEST CASE 3 ***********************
     ***********************************************************
     */
    cout << "TEST_MULTIPLY" << endl;
    Vector a3(x, y);
    a3.multiply(f);
    print(a3);

    a3.SetX(x + 2);
    a3.SetY(y + 3);
    a3.multiply(f);
    print(a3);

    /**
     ***********************************************************
     *********************** TEST CASE 4 ***********************
     ***********************************************************
     */
    cout << "TEST_MAGNITUTE" << endl;
    Vector a4(1, 1);
    cout << a4.magnitude() << endl;

    a4.SetX(x);
    a4.SetY(y);
    cout << a4.magnitude() << endl;

    /**
     ***********************************************************
     *********************** TEST CASE 5 ***********************
     ***********************************************************
     */
    cout << "TEST_ANGLE" << endl;
    Vector a5(1, 1);
    cout << a5.angle() << endl;

    a5.SetX(x);
    a5.SetY(y);
    cout << a5.angle() << endl;

    /**
     ***********************************************************
     *********************** TEST CASE 6 ***********************
     ***********************************************************
     */
    cout << "TEST_ANGLED" << endl;
    Vector a6(1, 1);
    cout << a6.angleD() << endl;

    a6.SetX(x);
    a6.SetY(y);
    cout << a6.angleD() << endl;

    /**
     ***********************************************************
     *********************** TEST CASE 7 ***********************
     ***********************************************************
     */
    cout << "TEST_ADD" << endl;
    Vector a7(x, y);
    Vector e7;
    Vector b7 = a7.add(e7);
    print(b7);

    /**
     ***********************************************************
     *********************** TEST CASE 8 ***********************
     ***********************************************************
     */
    cout << "TEST_CLONE" << endl;
    Vector a8(x, y);
    Vector b8 = a8.clone();
    print(b8);

    return 0;
}