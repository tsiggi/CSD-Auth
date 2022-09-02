#include <stdio.h>
#include <stdlib.h>

int main()
{
    float h,BMI,min,max;
    int w;
    scanf ("%f %d",&h ,& w);
    if ( h < 0.4 || h > 2.5 || w < 0 || w >200 )
    {
        printf ("Wrong input\n");
        exit(1);
    }
    BMI= w/(h*h);
    if (BMI<20)
    {
        printf("Lipovares\n");
    }
    if (BMI<25 && BMI>=20)
    {
        printf("Normal\n");
    }
    if (BMI<30 && BMI>=25)
    {
        printf("Ypervaro\n");
    }
    if (BMI<40 && BMI>=30)
    {
        printf("Paxisarko\n");
    }
    if (BMI>=40)
    {
        printf("Sovara Paxisarko\n");
    }

    min=20*(h*h);
    max=24.99*(h*h);
    printf("BMI: %.2f\nMin: %.2f\nMax: %.2f\n",BMI,min,max);
    return 0;
}
