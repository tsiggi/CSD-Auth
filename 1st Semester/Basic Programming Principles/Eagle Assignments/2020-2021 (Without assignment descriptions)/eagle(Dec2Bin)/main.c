#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ar,p1,p2,p3,p4,p5,ar10,ap1,ap2,ap3,ap4;
    scanf("%d",&ar10);
    if (ar10<0||ar10>31)
    {
        printf("Wrong Input");
        exit (0);
    }
    p1=ar10%2;
    ap1=ar10/2;
    p2=ap1%2;
    ap2=ap1/2;
    p3=ap2%2;
    ap3=ap2/2;
    p4=ap3%2;
    ap4=ap3/2;
    p5=ap4%2;
    ar=p5*10000+p4*1000+p3*100+p2*10+p1;
    printf("%d",ar);
    return 0;
}
