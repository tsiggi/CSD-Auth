#include "../Headers/HashTable.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;


void hashtable::insert(string s)                                 //� � � � �
{                                                                //� � � � � � � � � � � � � � � � � � �
    int l;                                                       //l � � � � � � � � � � � � � � (� � � � �) � � �(� � � � � � � �)
    bool k=find(s,l);                                           //� � FIND � � bool � � � � � � � S � � � � � l � � �

    if(!k)                                                       // � � � � �
    {
        array[l].w=s;                                            // � � � � �
        array[l].t=1;                                            // � � � � � � � � � (� � � 0 � � � � � � � � array[l].t=1;
        array[l].enable=true;                                    // � � � � � � � � �
        size2++;                                                 // � � � S � � �
    }
    else                                                         // � � � � � �
    {
        array[l].t++;                                            // � � � � � � � � l � � � � 1
    }


    if((size2*2)>=size)                                         //� � � � � � � � � � � � � � �
    {
        int j,k=0;

        ht *temp;                                                   //� � temp � � � � � � � �

        temp=new(nothrow) ht[2*size];                                        // new � � temp

        if(!temp)                                                            //an � � � � � temp �
        {
            cerr<<"!!!Memory Error!!!"<<endl;
        }
        int temps=size;                                                     //� �
        size*=2;                                                            // � � � Size � �

        for(int i=0;i<temps;i++)                                             //� � � � � � � � � � O(n)
        {
            k=0;
            if(array[i].enable==true)                                               //an � � � � � �
            {
                do{
                    j=F(array[i].w,k);
                    k++;
                }while(temp[j].enable==true && temp[j].w.compare(s)!=0);             // � � � � � � � � temp � � � � size
                temp[j].enable=true;                                                 //� � � � � � array � temp

                temp[j].t=array[i].t;

                temp[j].w=array[i].w;

            }
        }
        delete []array;                                                     //� � � �
        array = temp;                                                       // � � array � � �

    }
}



bool hashtable::find(string s,int &a)                           //� � � true � false � � � � � � � � (� � �  � � � �(� � � � � � � � � � �)
{
    int k=0;
    do{
        a=F(s,k);
        k++;
    }while(array[a].enable==true && array[a].w.compare(s)!=0);

    //� � � � � array[a].enable==FALSE � ( array[a].enable==true � array[a].w.compare(s)==0) � � � �
    //� � array[a].enable � � � � � � � � � � � � � � � � � � � � � �


    return array[a].enable;
}

int hashtable::F(string s,int a)                                 //� � � � � � �=� � � � � � � � � � � � � � s
{
    int h1=404597,h2=972887;                                         // h1,h2 big primes

    int h3=54059,h4=972887,h=37;                              // h3,h4 big primes ,h small prime
    for(int i=0;i<int(s.size());i++)
    {
        h=(h*h3*s[i]*(i+1))%h4;                                  // � � � � h � � � � � � � � � h2     (� � � � � � � � 400.000 � � � � � � � � � �)
    }
    if(h<0)                                                      // � � � � � � h < 0 � � � �
        h*=-1;


    return (h+h1*a+h2*a*a)%size;
    //� � � � � � � � � � � � � (� � � �) MOD size
    //� � � � � � � � � 0 � � size-1 � �

    //� � � � � � � � �  � � � � � �
    //(� � � � � � � � � � � � � � � ) MOD (size)
}

