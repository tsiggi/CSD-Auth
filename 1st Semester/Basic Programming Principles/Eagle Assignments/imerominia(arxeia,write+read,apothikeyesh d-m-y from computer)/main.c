#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    FILE *fl;
    int d,m,y;
    float km;
    fl=fopen("a.txt","r");
    if(fl!=NULL)
    {
        while(!feof(fl))
        {
            fscanf(fl,"%f",&km);
            printf("You walked %.2fkm!",km);
        }
    }
    printf("how many km you run today: ");
    scanf("%f",&km);
    fl=fopen("a.txt","w");
    if(fl!=NULL)
    {
        fprintf(fl,"%f",km);
    }
    return 0;
}
