#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    char yn=0;
    int n,i,temp,s=0,pl,p;
    scanf(" %d",&n);
    if (n<1)
    {
        printf("Wrong Input");
        return 1;
    }
    temp=n;
    for (pl=0;temp>0;pl++,temp/=10);
    //printf("%d\n",pl);
    temp=n;
    for (i=pl;i>0;i--)
    {
        p=temp/(pow(10,i-1));
        s=s+(int)pow(p,pl);
        temp=temp-p*pow(10,i-1);
       // printf("%d %d %d\n",i,s,temp);
    }
    //printf("%d",s);
    if (s==n)
        printf("yes");
    else
        printf("no");

    return 0;
}
