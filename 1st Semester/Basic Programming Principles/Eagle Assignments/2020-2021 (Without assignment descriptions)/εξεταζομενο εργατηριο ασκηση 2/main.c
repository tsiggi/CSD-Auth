#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int y_n(int x,int y,int pl)
{
    int j,y1;
    for(j=1;j<=pl;j++)
    {
        y1=y%10;
        if(y1==x)
        {
            return 1;
        }
        y/=10;
    }
    return 0;
}
int main()
{
    int a,b,p1,p2,i,a1,f1,f2,tempa;
    scanf("%d %d",&a,&b);
    if(a<1 || b<1)
    {
        printf("Wrong Input");
        return 1;
    }
    p1=log10(a)+1;
    p2=log10(b)+1;
    tempa=a;
    f1=1;
    for (i=1;i<=p1&&f1==1;i++)
    {
        f1=0;
        a1=a%10;
        if(y_n(a1,b,p2))
            f1=1;
        a/=10;
    }
    f2=1;
    for (i=1;i<=p2&&f2==1;i++)
    {
        f2=0;
        a1=b%10;
        if(y_n(a1,tempa,p1))
            f2=1;
        b/=10;
    }
    if(f2&&f1)
        printf("Yes");
    else
        printf("No");

    return 0;
}
/*
#include <stdio.h>
#include <math.h>

char contains (long n, char digit)
{
    while (n>0)
    {
        if (n%10==digit)
            return 1;
        n/=10;
    }
    return 0;
}

char containsAllDigits (int a, int b)
{
    char d;
    while (a>0)
    {
        d = a%10;
        a/=10;
        if (!contains(b, d))
            return 0;
    }
    return 1;
}

int main()
{
    int a,b;
    scanf("%d %d",&a, &b);
    if (a<1 || b<1)
    {
        printf("Wrong Input");
        return 1;
    }

    if (containsAllDigits(a,b) && containsAllDigits(b,a))
        printf ("Yes");
    else
        printf ("No");
    return 0;
}
*/
