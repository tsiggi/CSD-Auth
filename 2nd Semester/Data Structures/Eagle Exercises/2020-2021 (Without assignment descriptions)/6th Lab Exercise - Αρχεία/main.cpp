#include <iostream>

#include "myFile.h"
using namespace std;

int main()
{
    char s1[30];
    cin>>s1;
    myFile a(s1); 

    char s2[30];
    cin>>s2;
    myFile b(s2);

    myFile c((char *)"c.txt");

    if (a.exists())
    {
        cout<<"File A is ok"<<endl;
        cout<<"Lines in file A: "<<a.countLines()<<endl;
        cout<<"Chars in file A: "<<a.countChars()<<endl;
    }
    else
    {
        cout<<"File A not found!"<<endl;
    }

    if (b.exists())
    {
        cout<<"File B is ok"<<endl;
        cout<<"Lines in file B: "<<b.countLines()<<endl;
        cout<<"Chars in file B: "<<b.countChars()<<endl;
    }
    else
    {
        cout<<"File B not found!"<<endl;
    }

    if (a==b)
    {
        cout<<"The files A and B are equal."<<endl;
    }
    else
    {
        cout<<"The files A and B are not equal."<<endl;
    }

    c=a;
    c+=b;
    cout<<"File C is equal to A+B."<<endl;
    cout<<"Lines in file C: "<<c.countLines()<<endl;
    cout<<"Chars in file C: "<<c.countChars()<<endl;


    return 0;
}