#include <stdio.h>
#include <stdlib.h>
#include <math.h>
char Increasing(int x,int y)
{
    int pr2,pr1;
    for (;y>1;y--)
    {
        pr1=x/pow(10,y-1);
        pr2=x/pow(10,y-2)-pr1*10;
        x=x%(int)pow(10,y-1);
        if (pr1>pr2)
            return 0;
    }
    return 1;
}
char Decreasing(int x,int y)
{
    int pr2,pr1;
    for (;y>1;y--)
    {
        pr1=x/pow(10,y-1);
        pr2=x/pow(10,y-2)-pr1*10;
        x=x%(int)pow(10,y-1);
        if (pr1<pr2)
            return 0;
    }
    return 1;
}
int main()
{
    int ak,pl;
    scanf("%d",&ak);
    if(ak<10)
    {
        printf("Wrong Input");
        return 1;
    }
    pl=(int)(log10(ak)+1);
    if (Increasing(ak,pl))
        printf("Increasing");
    else
    {
        if (Decreasing(ak,pl))
            printf("Decreasing");
        else
            printf("Bouncing");
    }
    return 0;
}
