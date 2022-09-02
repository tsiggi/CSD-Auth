#include <stdio.h>
#include <stdlib.h>

int main()
{
    float input,cel=0,fahr=0;
    char ch;
    printf ("input the temperature(C/F) : ");
    scanf ("%f %c,",&input,&ch);
    if (ch!='c' & ch!='C' & ch!='f' & ch!='F')
    {
        printf("wrong input\n");
        exit (12);
    }
    if (ch == 'c'|| ch == 'C')
    {
        cel=input;
        fahr=cel*9/5+32;
    }
    else
    {
        fahr=input;
        cel=(fahr-32)*5/9;
    }
    printf("celcius :  %f\t fahrenheit : %f\n",cel,fahr);
    return 0;
}
