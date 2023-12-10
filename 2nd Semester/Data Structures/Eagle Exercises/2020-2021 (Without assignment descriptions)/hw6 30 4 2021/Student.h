//i dont wanna die but sometimes i wish i was never born again

#ifndef student_h
#define student_h

#include <iostream>
#include <fstream>
using namespace std;

class Student 
{
private:
    int AEM;
    char name[30];
    float grade;
public:
    int GetAEM(){return AEM;};
    char* GetName(){return name;};
    float GetGrade(){return grade;};
    
    friend ostream &operator<<(ostream &,Student); 
    friend istream &operator>>(istream&,Student&);
    friend bool readStudent(char *,Student &);
    friend bool writeToStudent(char *,Student &);
};
ostream &operator<<(ostream &o,Student a)
{
    o<<a.AEM<<" "<<a.name<<" "<<a.grade;
    return o;
}
istream &operator>>(istream &i,Student &a)
{
    i>>a.AEM>>a.name>>a.grade;
    return i;
}
bool readStudent(char *s,Student &a)
{
    ifstream ifs;
    
    ifs.open(s);

    if(!ifs.is_open())
        return false;
    
    if(ifs>>a.AEM && ifs>>a.name && ifs>>a.grade)
        return true;
    return false;
}
bool operator > (Student a,Student b)
{
    return a.GetGrade()>b.GetGrade();
}
bool writeToStudent(char *s,Student &a)
{
    ofstream ofs;
    ofs.open(s);
    if(!ofs.is_open())
    {
        ofs.close();
        return false;
    }

    ofs<<a.AEM<<" "<<a.name<<" "<<a.grade<<endl;
    ofs.close();
    return true;

}
#endif