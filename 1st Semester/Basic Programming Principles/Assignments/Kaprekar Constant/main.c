#include <stdio.h>
#include <stdlib.h>

int main()
{
    int k,k1,k2,k3,k4,max1,max2,max3,max4,i,Kmax,Kmin;
    scanf("%d",&k);
    k1=k/1000;
    k4=k%10;
    k3=(k%100-k4)/10;
    k2=k/100-k1*10;
    if(k>9999 || k<1000 || (k1==k2&&k1==k3&&k1==k4))
    {
        printf("Wrong input");
        return 1;
    }
    for(i=0;k!=6174;i++)
    {
        k1=k/1000;
        k4=k%10;
        k3=(k%100-k4)/10;
        k2=k/100-k1*10;
        max1=k1;
        max2=-1;
        max3=-1;
        max4=-1;
        if(max1>=k2)
            max2=k2;
        else
        {
            max2=max1;
            max1=k2;
        }
        if(k3>max1)
        {
            max3=max2;
            max2=max1;
            max1=k3;
        }
        else
            if(k3>max2)
            {
                max3=max2;
                max2=k3;
            }
            else
                max3=k3;
        if(k4>max1)
        {
            max4=max3;
            max3=max2;
            max2=max1;
            max1=k4;
        }
        else
            if(k4>max2)
            {
               max4=max3;
               max3=max2;
               max2=k4;
            }
            else
                if(k4>max3)
                {
                    max4=max3;
                    max3=k4;
                }
                else
                    max4=k4;
        Kmax=max1*1000+max2*100+max3*10+max4;
        Kmin=max4*1000+max3*100+max2*10+max1;
        k=Kmax-Kmin;
        printf("max:%d min: %d diff:%d\n",Kmax,Kmin,k);
    }
    printf("Took %d turns",i);
    return 0;
}
