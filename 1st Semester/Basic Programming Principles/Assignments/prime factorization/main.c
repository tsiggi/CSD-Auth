#include <stdio.h>
#include <stdlib.h>
#include <math.h>
char isPrime(int a)
{
    int k,i;
    if (a<2 || (a%2==0&&a!=2))
        return 0;
    k=sqrt(a);
    if (a==2)
        return 1;
    for (i=3;i<=k;i+=2)
    {
         if (a%i==0)
            return 0;
    }
    return 1;
}
int main()
{
    int n,i;
    scanf ("%d",&n);
    if (n<2)
    {
        printf ("Wrong input");
        return 1;
    }
    for(i=2;n>1;i+=2)
    {
        if (n%i==0)
        {
            if (isPrime(i))
            {
                printf("%d ",i);
                n=n/i;
                i=1;
            }
        }
        if(i<3)
        {
            i--;
        }
    }



    return 0;
}
