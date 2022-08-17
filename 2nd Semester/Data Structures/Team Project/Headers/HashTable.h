#ifndef HASHTABLE_H_INCLUDED
#define HASHTABLE_H_INCLUDED

#include <string>
using namespace std;

class ht
{
public:
    bool enable=false;                                     //� � � � � � � � � (� � � FALSE � � � � � � �
    string w;                                             // � � � � �
    int t=0;                                             //  � � � � � � � � � � �
};


class hashtable
{
private :

    ht *array ;                                                                 //� � � � � � � ht

    int size;                                                                 //� � � �

    int size2;                                                              //� � � � � � � �

public :
    hashtable(){array= new ht[1500];size=1500 ;size2=0;};          // � � � � 1500 �(size=1500 � � � � � � size2=0)

    int F(string,int);                                           //� � � � � � int � � � � � � � � � � � � � � � � (� � int � � � 0 � � � � � � h)

    void insert(string);                                       //� � � string � � � � � � � � � � � � � � � � � � � � � H(x) % (� � � � �)

    bool find(string,int &);                                 //� true � � � � � i � � � � � � false

    //Getters for the private members
    int GetTimes(string s){                                     //� � s � � � � � � � t>0 � � 0
        int i;
        if(find(s,i))
            return array[i].t;
        return 0;
    };
    string GetWord(int i){return array[i].w;};                                        //� � w � � � � � � � � i
    int GetSize(){return size;};                                                     // � � � � �
    bool GetEnabled(int i){return array[i].enable;};                                //� � � � � � � i � � � Array
};
#endif // HASHTABLE_H_INCLUDED

