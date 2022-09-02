#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    long long S=0;
    int i=-1,k[100],s[100],a,j,l,temp;
    do{
        scanf("%d",&a);
        if(a!=0)
        {
            i++;
            k[i]=a;
        }
    }while(a!=0&&i<99);
    for(j=0;j<=i;j++)
    {
       a=log10(k[j])+1;
       s[j]=0;
       temp=k[j];
       for(l=0;l<a;l++)
       {
           s[j]+=pow(temp%10,a);
           temp/=10;
       }
    S+=s[j];

    }
    printf("%lld\n",S);
    for(j=0;j<=i;j++)
    {
        printf("%d %d\n",k[j],s[j]);
    }
    return 0;
}
