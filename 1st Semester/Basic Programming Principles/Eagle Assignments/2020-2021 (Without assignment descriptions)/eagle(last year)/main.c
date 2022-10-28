#include <stdio.h>
#include <stdlib.h>

int main()
{
    int y;
    scanf ("%d",&y);
    if (!(y>0))
    {
        printf ("Wrong Input");
        exit(1);
    }
/*    if (y/100 == y*(1.0)/100 )
    {
        if (y/400 == y*(1.0)/400)
            printf("Leap");
        else
            printf("Normal");
    }
    else
        if (y/4 == y*(1.0)/4)
            printf("Leap");
        else
            printf("Normal"); */

    if (!(y/4 == y*(1.0)/4) ||((y/100 == y*(1.0)/100)&& y/400 != y*(1.0)/400 ) )
        printf("Normal");
    else
        printf("Leap");

    return 0;
}
