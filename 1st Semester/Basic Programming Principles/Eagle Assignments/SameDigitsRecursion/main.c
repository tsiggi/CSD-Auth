#include <stdio.h>
#include <stdlib.h>
int count(long long x,long long y)
{
    int r=0;
    if (x==0 || y==0)
        return 0;
    if (x%10==y%10)
        r++;
    return r+count(x/10,y/10);
}
int main()
{
    long long a,b;
    scanf("%lld %lld",&a,&b);
    printf("%d",count(a,b));
    return 0;
}
