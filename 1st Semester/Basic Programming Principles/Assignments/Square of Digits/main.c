#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int a,temp,i,s,b,j;
    scanf("%d",&a);
    if (a<=0)
    {
        printf("Wrong input");
        return 1;
    }
    j=0;
    do
    {
        temp=a;
        for (i=0;temp>0;i++,temp/=10);
        //printf("%d",i);
        for (s=0;i>0;i--)
        {
            b=a/pow(10,i-1);
            s=s+b*b;
            a=a%(int)pow(10,i-1);
        }
        a=s;
        j++;

    }
    while (a!=1&&a!=4&&a!=16&&a!=20&&a!=37&&a!=42&&a!=58&&a!=89&&a!=145);
    printf("%d %d",j,a);
    return 0;
}
