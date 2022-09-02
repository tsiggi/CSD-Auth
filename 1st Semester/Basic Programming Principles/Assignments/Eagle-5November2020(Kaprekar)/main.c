#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int ar,t,temp,pl=0,al=0,i,a=0,b=0;
    scanf("%d",&ar);
    if (ar<=0)
    {
        printf("Wrong input");
        exit(0);
    }
    t=ar*ar;
    temp=t;
    for (;temp>0;pl++)
    {
        temp=temp/10;
    }
    i=0;
   // while ((i<=pl)&&(al==0))
    for (i=0;(i<pl)&&(al==0);i++)
    {
        a=t/pow(10,(pl-i));
        b=t%(int)pow(10,(pl-i));
        // printf("%d %d\n",a,b);
        if (a+b==ar)
         {
              al=1;
         }
    }
    if (al==1 && b!=0)
        printf("Kaprekar! %d + %d = %d",a,b,ar);
    else
        printf("Not Kaprekar");


    return 0;
}
