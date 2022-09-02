#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int n,temp,i,a,j,s;
    scanf("%d",&n);
    if (n<=0)
    {
        printf("Wrong input");
        return 1;
    }
    for (j=0;n>=10;j++)
    {
        temp=n;
        for (i=0;temp>0;i++,temp/=10);

        for(s=0;i>0;i--)
        {
            a=n/pow(10,i-1);
            s+=a;
            n%=(int)pow(10,i-1);
        }
        n=s;
    }
    printf("%d %d",j,n);
    return 0;
}
