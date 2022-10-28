#include "myFile.h"
#include <iostream>
#include <fstream>
using namespace std;

char* myFile::GetName()
{
    return name;
}
bool myFile::exists()
{
    ifstream o;
    o.open(name);
    if(o.is_open())
    {
        o.close();
        return true;
    }
    o.close();
    return false;
}
int myFile::countLines()
{
    ifstream i;
    i.open(name);
    int count=1;
    if(!exists())
    {
        i.close();
        return 0;
    }
    char c;
    
    while(i.get(c))
    {
        if(c=='\n')
            count++;   
    }
    i.close();
    return count;
}
int myFile::countChars()
{
    ifstream i;
    i.open(name);
    int count=1;
    if(!exists())
    {
        i.close();
        return 0;
    }
    char c;
    while(i.get(c))
    {
        count++;   
    }
    i.close();
    return count;
}
bool operator == (myFile &a,myFile &b)
{
    ifstream z,x;
    char z1,x1;
    z.open(a.GetName());
    x.open(b.GetName());
    if(!z.is_open()||!x.is_open())
    {
        z.close();
        x.close();
        return false;
    }
    if(a.countChars()!=b.countChars())
    {
        z.close();
        x.close();
        return false;
    }
    while(z.get(z1)&&x.get(x1))
    {
        if(z1!=x1)
        {
            z.close();
            x.close();
            return false;
        }
    }
    z.close();
    x.close();
    return true;

}
void myFile:: operator =(myFile &a)
{
    ofstream z;
    ifstream x;
    char c;
    z.open(this->name);
    x.open(a.GetName());
    if(!z.is_open()||!x.is_open())
    {  
        z.close();
        x.close();    
        return;
    }
    while(x.get(c))
    {
        z<<c;
    }
    z.close();
    x.close();

}
void operator +=(myFile &a ,myFile &b)
{
    ofstream z;
    ifstream x;
    char c;
    z.open(a.GetName(),ios::app);
    x.open(b.GetName());
    while(x.get(c))
    {
        z<<c;
    }

    z.close();
    x.close();
}