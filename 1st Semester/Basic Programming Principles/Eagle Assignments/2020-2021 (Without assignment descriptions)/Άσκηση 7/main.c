#include <stdio.h>
#include <stdlib.h>
#include <math.h>
char isPrime(int a)
{
    int j,sq;
    sq =round(sqrt(a));
    for (j=3;j<=sq;j+=2)
        if (a%j==0)
        {
            return 0;
        }
    return 1;
}
int main()
{
    int n,d,i,q;
    char end=1;
    scanf("%d", &n);
    if (n<=2 || n%2==1)
    {
        printf("Wrong Input");
        return 1;
    }
    if(n==4)
        printf("2+2=4");
    else
    {
        d=(n/2.0);
        for (i=3;((i<=d)&&end);i+=2)
        {
            if (isPrime(i))
            {
                q=n-i;
                if (isPrime(q))
                {
                    printf("%d+%d=%d",i,q,n);
                    end=0;
                }
            }
        }
    }
    return 0;
}
