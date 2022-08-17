#include <iostream>
#include "Rational.h"
using namespace std;

int main()
{
   Rational a(12,3);
   Rational b,c;

    cin>>b;
    cout<<a<<", "<<b<<endl;
    if (a==b)
        cout<<"Equal"<<endl;
    if (a!=b)
        cout<<"Not equal"<<endl;
    if (a>b)
        cout<<"a>b"<<endl;
    if (a<b)
        cout<<"a<b"<<endl;
    c = a+b;
    cout<<"a+b: "<<c<<endl;
    c = a-b;
    cout<<"a-b: "<<c<<endl;
    c = a*b;
    cout<<"a*b: "<<c<<endl;
    c = a/b;
    cout<<"a/b: "<<c<<endl;
    c*=2;
    a/=b;
    cout<<"2*a/b: "<<c<<endl;
    cout<<"a/b: "<<a<<endl;
    
    return 0;
}