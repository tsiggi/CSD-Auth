#include <iostream>
#include "Student.h"

using namespace std;

int main()
{
    char s[30];
    cin>>s;
    Student a,b;
    if (readStudent(s,a))
    {
        cout<<a<<endl;
        cin>>b;
        cin>>s;
        if (writeToStudent(s,a>b?a:b))
            cout<<"Ok"<<endl;
        else
            cout<<"Error writing to file"<<endl;
    }
    else
        cout<<"Error reading from file"<<endl;
    system("pause");
    return 0;
}
