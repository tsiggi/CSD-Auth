#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int dec,i=0,temp;
    scanf ("%d",&dec);
    if (dec<0 || dec > 65535)
    {
        printf("Wrong Input");
        return 1;
    }
    temp=dec;
    for(;temp>0;temp/=2)
    {
        i++;
    }
    if (dec==0)
        printf("0");
    else
    {
    for (;i>0;i--)
    {
        if (dec>=pow(2,i-1))
            {
                printf("1");
                dec=dec-pow(2,i-1);
            }
        else
            printf("0");

    }
    }
    return 0;
}
