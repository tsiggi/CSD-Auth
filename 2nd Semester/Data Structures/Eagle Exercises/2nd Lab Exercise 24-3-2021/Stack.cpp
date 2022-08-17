#include "Stack.h"
#include <iostream>
Stack::Stack()
{
    size=10;
    telos=-1;
    s=new int[size];
}
Stack::Stack(int n)
{
    size=n;
    telos=-1;
    s=new int[n];
}
Stack::Stack(Stack &s2)
{
    size=s2.size;
    telos=s2.telos;
    s=new int[size];
    for(int i=0;i<size;i++)
    {
        s[i]=s2.s[i];
    }
}
Stack::~Stack()
{
    delete []s;
}
bool Stack::isEmpty()
{
    return (telos+1==0);
    /*if(!(telos+1))
        return true;
    return false;*/
}
bool Stack::pop(int &a)
{
    if(telos==-1)
        return false ;
    a=s[telos];
    telos--;
    return true;
}
bool Stack::push(int a)
{
    if(size==telos+1)
    {
        int *temp;
        temp=new int[size+5];
        if(temp==nullptr)
            return false;
        for(int i=0;i<size;i++)
        {
            temp[i]=s[i];
        }
        delete []s;
        s=temp;
        size+=5;
    }
    telos++;
    s[telos]=a;
    return true;
}
