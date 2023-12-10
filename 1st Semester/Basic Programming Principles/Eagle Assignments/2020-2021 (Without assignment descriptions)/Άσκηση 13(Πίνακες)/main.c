#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,i;
    scanf("%d",&N);
    if(N<2||N>100000)
    {
        printf("Wrong Input");
        return 1;
    }
    long A[N],B[N],max1=-1,max2=-2,sum=0;
    for (i=0;i<N;i++)
    {
        scanf("%ld",&A[i]);
        sum+=A[i];
    }
    for (i=0;i<N;i++)
    {
        scanf("%ld",&B[i]);
        if(B[i]<0||B[i]>1000000000||A[i]<0||A[i]>1000000000||A[i]>B[i])
        {
            printf("Wrong Input");
            return 1;
        }
        if(B[i]>max1)
        {
            max2=max1;
            max1=B[i];
        }
        else
        {
            if(B[i]>max2)
            {
                max2=B[i];
            }
        }
    }
    if(sum<=max1+max2)
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }
    return 0;
}
