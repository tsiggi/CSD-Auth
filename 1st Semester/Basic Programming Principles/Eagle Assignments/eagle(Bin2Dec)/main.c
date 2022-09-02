#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ar,p1,p2,p3,p4,p5,ar10;
    scanf("%d",&ar);
    p1=ar%10;
    p2=(ar%100 - p1)/10;
    p3=(ar%1000 - p2)/100;
    p4=(ar%10000 - p3)/1000;
    p5=ar/10000;
    if ((p1!=1 && p1!=0)||(p2!=1&&p2!=0) ||(p3!=1&&p3!=0)|| (p4!=1&&p4!=0) || (p5!=1&&p5!=0))
    {
        printf("Wrong Input");
        exit (0);
    }

    ar10=16*p5 +8*p4+4*p3+2*p2+p1;
    printf("%d",ar10);

    return 0;
}
