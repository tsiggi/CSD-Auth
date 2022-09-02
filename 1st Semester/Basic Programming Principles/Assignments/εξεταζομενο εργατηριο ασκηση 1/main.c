#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int n;
    int p,i,a,f=1;
    scanf("%d",&n);
    if (n<1||n>999999999)
    {
        printf("Wrong Input");
        return 1;
    }
    n=round(n);
    p=(int)(log10(n)+1);
    p=round(p);
    for (i=1;i<=p&&f==1;i++,n/=10)
    {
        a=((int)n)%10;
        if (a==p)
        {

            f=0;
        }
    }

    if(f==1)
        printf("No");
    if(f==0)
        printf("Yes");


    return 0;
}
