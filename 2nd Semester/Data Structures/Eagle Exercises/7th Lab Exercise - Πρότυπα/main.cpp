#include <iostream>

#include "PriorityQueue.h"
#include "Point2D.h"

using namespace std;

int main()
{
    //Data
    int x1,y1,x2,y2,x3,y3,a,b;
    cin>>x1>>y1>>x2>>y2>>x3>>y3>>a>>b;


    //Priority queue with points
    PriorityQueue<Point2D>  *B = new PriorityQueue<Point2D>();

    B->enQueue(Point2D(x1,y1));
    B->enQueue(Point2D(x2,y2));
    B->enQueue(Point2D(x3,y3));

    B->show();


    //Priority queue with integers
    PriorityQueue<int>  *A = new PriorityQueue<int>();

    int temp;

    for (int i=1;i<=a;i++)
    {
        A->enQueue(i);
        A->enQueue(2*a-i+1);
    }

    A->show();

    for (int i=0;i<b;i++)
        A->deQueue(temp);

    A->show();

    return 0;
}
