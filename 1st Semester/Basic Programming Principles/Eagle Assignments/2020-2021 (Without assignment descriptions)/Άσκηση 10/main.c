#include <stdio.h>
#include <stdlib.h>

int main()
{
    int h,m,s,a,b,pl ;
    scanf("%d %d %d %d %d",&h,&m,&s,&a,&b);
    if(h==12)
        h=0;
    h*=5;
    if (a==12)
        a=0;
    a*=5;
    if (b==12)
        b=0;
    b*=5;
    if( h>59 || h<0  || m<0 || s<0 || m>59 || s>59 || a==b || a<0 || a>59 || b<0 || b>59 ||(a==h&&s==0&&m==0) || (h==b&&s==0&&m==0) || (a==m&&s==0) || (b==m&&s==0) || a==s || b==s )
    {
        printf("Wrong Input");
        return 1;
    }


    if(a>b)
    {
        for (pl=0;b<=a;b++)
        {
            if(a==h)
                pl++;
            if (a==m)
                pl++;
            if (a==s)
                pl++;
        }
        if (pl==3 || pl==0)
            printf("Yes");
        else
            printf("No");
    }
    else
    {
        for (pl=0;a<=b;a++)
        {
            if(a==h)
                pl++;
            if (a==m)
                pl++;
            if (a==s)
                pl++;
        }
        if (pl==3 || pl==0)
            printf("Yes");
        else
            printf("No");
    }
    return 0;
}
