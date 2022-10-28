#ifndef PRIORITYQUEUE_H_INCLUDED
#define PRIORITYQUEUE_H_INCLUDED
#include <iostream>
using namespace std;

template <typename mytype>
class PriorityQueue
{
private :
    mytype *oura;
    int de;
    int size;
    int last;
public:
    PriorityQueue(){
        oura=new mytype [100];
        for(int i=0;i<100;i++){
            oura[i]=0;
        }
        de=0;
        size=0;
        last=10;
    };
    ~PriorityQueue(){delete []oura;};
    void enQueue(mytype a){
        mytype temp1,temp2;


        if(size+1>last){
            cout<<"Not enough space. Requesting more..."<<endl;
            cout<<"Space found. Moving data..."<<endl;
            last+=5;
        }


        for(int i=de;i<=size+de;i++)
        {
            if (oura[i]<a)
            {
                temp1=oura[i];
                oura[i]=a;
                for(int y=i+1;y<=size+de+1;y++)
                {
                    temp2=oura[y];
                    oura[y]=temp1;
                    temp1=temp2;
                }
                break;
            }
            if(i==size+de&&(!(oura[i]<a)))
                oura[size+1]=a;


        }
        size++;
    }
    void deQueue(mytype &a){
        a=oura[de];
        de++;
        if(de%5==0||(size==0&&last>=5)){
            cout<<"Too much available space. Deleting extra memory..." <<endl;
            last-=5;
            //de-=5;
            cout<< "Extra space deleted."<<endl;
        }
        if(size==0)
        {
            cout<<"Array empty...."<<endl;

            return;
        }
        size--;
    }
    void show(){
        cout<<"--------------"<<endl;
        cout<<"Size = "<<size<<endl;
        cout<<"maxSize = "<<last<<endl;
        for(int i=de;i<size+de;i++)
            cout<<oura[i]<<endl;
        cout<<"--------------"<<endl;
    }
};


#endif // PRIORITYQUEUE_H_INCLUDED
