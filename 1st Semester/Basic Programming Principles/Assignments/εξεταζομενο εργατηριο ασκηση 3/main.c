#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int n,i,j,f;
    scanf("%d",&n);
    if(n<1||n>999999999)
    {
        printf("Wrong Input");
        return 1;
    }
    for(i=1;i<=n;i++)
    {
        f=0;
        for(j=2;j<=i&&f==0;j++)
        {
            if((i)%j==0)
            {
                if(n%j==0)
                {
                    f=1;
                }
            }
        }
        if (f==0)
        {
            printf("%d ",i);
        }
    }
    return 0;
}
