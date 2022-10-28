#include <stdio.h>
#include <stdlib.h>

int main()
{
    float temp,C,F;
    char eidos;
    scanf("%f %c",&temp,&eidos);
    if (eidos!='c' && eidos != 'C' &&eidos !='f' && eidos!='F')
    {
        printf("Wrong input");
        exit (0);
    }
    if (eidos=='c' || eidos == 'C')
    {
        F=temp*9.0/5+32;
        printf("%.2f F",F);
    }
    else
    {
        C=(temp-32)*5/9;
        printf ("%.2f C",C);
    }
    return 0;
}
