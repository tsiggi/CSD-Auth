#include <stdio.h>
#include <stdlib.h>

int main()
{
    int p,c,k2,k1,k50,k20,k10,k05,k01;
    double xr;
    scanf("%d %lf",&p,&xr);
    if (p<1 || p>5 || xr<0.75 || xr>100 || xr-p*0.75<0 )
    {
        printf("Wrong input");
        exit (0);
    }
    c=xr*100;
    c=c-p*75;
    k2=c/200;
    if (k2!=0)
    {
        c=c-k2*200;
        printf("%d * 2 euros\n",k2);
    }
    k1=c/100;
    if (k1!=0)
    {
        c=c-k1*100;
        printf("%d * 1 euros\n",k1);
    }
    k50=c/50;
    if (k50!=0)
    {
        c=c-k50*50;
        printf("%d * 50 cents\n",k50);
    }
    k20=c/20;
    if (k20!=0)
    {
        c=c-k20*20;
        printf("%d * 20 cents\n",k20);
    }
    k10=c/10;
    if (k10!=0)
    {
        c=c-k10*10;
        printf("%d * 10 cents\n",k10);
    }
    k05=c/5;
    if (k05!=0)
    {
        c=c-k05*5;
        printf("%d * 5 cents\n",k05);
    }
    k01=c;
    if (k01!=0)
    {
        c=c-k01;
        printf("%d * 1 cents\n",k01);
    }
    return 0;
}
