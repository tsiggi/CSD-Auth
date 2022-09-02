#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define STR 100
typedef struct city
{
    char *name;
    float x,y;
} city;
city *GetCities(int *N)
{
    char c;
    scanf("%d",N);
    //printf("%d\n",*N);
    city *C;
    C=malloc((*N)*sizeof(city));
    for(int i=0;i<(*N);i++)
    {
        while((c=getchar())!='\n'&&c!=EOF);
        C[i].name=(char*) malloc(STR*sizeof(char));
        fgets(C[i].name,STR,stdin);
        C[i].name[strcspn(C[i].name,"\n")]='\0';
        C[i].name=(char *)realloc(C[i].name,strlen(C[i].name)+1);
        //printf("%s\n",C[i].name);
        //while((c=getchar())!='\n'&&c!=EOF);
        scanf("%f",&C[i].x);
        scanf("%f",&C[i].y);
    }
    return C;
}
void *Distances(city *C,int N)
{
    float (*A)[N];
    int i,j,mini,minj;
    A=(float *)malloc(sizeof(float[N][N]));
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            //A[i][j]=sqrt((C[i].x-C[j].x)*(C[i].x-C[j].x)+(C[i].y-C[j].y)*(C[i].y-C[j].y));
            A[i][j]=(sqrt( pow(C[i].x-C[j].x,2) + pow(C[i].y-C[j].y,2) ));

        }
    }
    mini=0;
    minj=1;
    for(i=0;i<N;i++)
    {
        for(j=i+1;j<N;j++)
        {
            if(/*i<j&&*/(A[i][j]<A[mini][minj]))
            {
                mini=i;
                minj=j;
            }
        }
    }
    printf("Shortest path is %.2f km between %s and %s\n",A[mini][minj],C[mini].name,C[minj].name);
    return A;
}
void GetRoutes(city *C,int N,float A[][N])
{
    char *s,c;
    float xiliometra;
    int i,temp;
    while((c=getchar())!='\n'&&c!=EOF);
    s=(char*)malloc(STR*sizeof(char));
    fgets(s,STR,stdin);
    s[strcspn(s,"\n")]='\0';
    s=(char *)realloc(s,strlen(s)+1);
    //while((c=getchar())!='\n'&&c!=EOF);
    scanf("%f",&xiliometra);
    for(i=0;i<N;i++)
    {
        if(strcmp(C[i].name,s))
        {
            temp=i;
            i=N+1;
        }
    }
    for(i=0;i<N;i++)
    {
        if((A[temp][i]<xiliometra)&&(i!=temp))
        {
            printf("Feasible path of %.2f km to %s\n",A[temp][i],C[i].name);
        }
    }
}
