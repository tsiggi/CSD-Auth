#include <stdio.h>
#include <stdlib.h>


void anapoda (float a[],int size)
{
    if (size==1)
    {
        printf("%.1f\n",a[size-1]);
        return ;
    }
    printf("%.1f\n",a[size-1]);
    anapoda(a,size-1);
}
int main()
{
    int N,k[100],M,i,j,b,d,l;
    long long  sum;
    float r[100];
    scanf("%d",&N);
    if(N<1||N>100)
    {
        printf("Wrong input");
        return 1;
    }
    for(i=0;i<N;i++)
    {
        scanf("%d",&k[i]);
    }
    scanf("%d",&M);
    if(M<1||M>100)
    {
        printf("Wrong input");
        return 1;
    }
    for(j=0;j<M;j++)
    {
        scanf("%d",&b);
        scanf("%d",&d);
        if(b<0||b+d>=N)
        {
            printf("Wrong input");
            return 1;
        }
        for(sum=0,l=b;l<=b+d;l++)
        {
            sum+=k[l];
        }
        r[j]=sum*1.0/(d+1);
    }
    anapoda(r,M);
    return 0;
}
