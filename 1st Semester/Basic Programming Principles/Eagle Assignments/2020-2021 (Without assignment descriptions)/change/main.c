#include <stdio.h>
#include <stdlib.h>

int main()
{
    int pl,p,k2,k1,k50,k20,k10,k5;
    double po;
    scanf("%d %lf",&pl,&po);
    p = po * 100 - pl*75;
    if (pl<1 || pl>5 || po<0.75 || po > 100 || p <0)
    {
        printf("Wrong input");
        exit (0);
    }
    k2=p/200;
    p=p%200;
    if (k2!=0)
    {
        printf("%d * 2 euros\n",k2);
    }
    k1=p/100;
    p=p%100;
    if (k1!=0)
    {
        printf("%d * 1 euros\n",k1);
    }
    k50=p/50;
    p=p%50;
    if (k50!=0)
    {
        printf("%d * 50 cents\n",k50);
    }
    k20=p/20;
    p=p%20;
    if (k20!=0)
    {
        printf("%d * 20 cents\n",k20);
    }
    k10=p/10;
    p=p%10;
    if (k10!=0)
    {
        printf("%d * 10 cents\n",k10);
    }
    k5=p/5;
    p=p%5;
    if (k5!=0)
    {
        printf("%d * 5 cents\n",k5);
    }
    if (p!=0)
    {
        printf("%d * 1 cents",p);
    }

    return 0;
}
