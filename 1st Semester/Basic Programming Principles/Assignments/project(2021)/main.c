#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void taxinomisi(int *A,int n);
void taxinomisi2(float *A,int n);
void metrix0(int n,char *str);
void metrix1(int n,char *str);
void metrix2(int n,char *str);
void metrix3(int n,char *str);
int count(int n,char *str);
int *F(int n,char *str);
int *D(int n,char *str);
float *RD(int n,char *str);
int count(int n,char *str);

int main()
{
    FILE *fp;
    char *str,c;
    int numbers,metrix;
    scanf("%d %d",&numbers,&metrix);
    if(numbers<1||numbers>49||metrix<0||metrix>3)
    {
        printf("Wrong Input!");
        return 1;
    }
    scanf(" ");
    str=(char*)malloc(10000*sizeof(char));
    fgets(str,10000,stdin);
    str[strcspn(str,"\n")]='\0';
    str=(char*)realloc(str,strlen(str)+1);

    fp=fopen(str,"r");

    if (fp==NULL)
    {
        printf("File Error!");
        return 1;
    }
    fclose(fp);

    if(metrix==0)
        metrix0(numbers,str);
    if(metrix==1)
        metrix1(numbers,str);
    if(metrix==2)
        metrix2(numbers,str);
    if(metrix==3)
        metrix3(numbers,str);
    return 0;
}
void metrix3(int n,char *str)
{
    float *rd;
    rd=RD(n,str);
    taxinomisi2(rd,n);
}

void metrix2(int n,char *str)
{
    int *d,*f;
    f=F(n,str);
    d=D(n,str);
    for(int i=0;i<49;i++)
    {
        //printf("%2d: %2d %2d ",i+1,f[i],d[i]);
        f[i]+=d[i];
        //printf("%2d\n",f[i]);
    }
    taxinomisi(f,n);
    return ;
}
float *RD(int n,char *str)
{
    int *f,*d,c;
    c=count(n,str)/7;
    f=F(n,str);
    d=D(n,str);
    float *rd;
    rd=malloc(49*sizeof(float));

    for(int i=0;i<49;i++)
    {
        if(f[i]==0)
            rd[i]=0;
        else
        {
            rd[i]=round((d[i]-((c*(1.0))/f[i]))*100);
            rd[i]/=100;
        }
    }
    return rd;
}
void taxinomisi2(float *A,int n)
{
    int i,j,max;
    int temp;
    int B[49],C[49];

    for(i=0;i<49;i++)
    {
         B[i]=i;
         C[i]=(int)100*A[i];
    }
    for(i=0;i<49-1;i++)
    {
        for(j=i+1;j<49;j++)
        {
            if(C[i]<C[j]||(C[i]==C[j]&&B[i]>B[j]))
            {
                temp=C[i];
                C[i]=C[j];
                C[j]=temp;
                temp=B[i];
                B[i]=B[j];
                B[j]=temp;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d ",B[i]+1);
    }

}
int *D(int n,char *str)
{
    FILE *fp;
    fp=fopen(str,"r");
    int *d,c,i,a;
    d=malloc(49*sizeof(int));
    c=count(n,str);
    for(i=0;i<49;i++)
        d[i]=c/7;
    for(i=0;i<c;i++)
    {
        fscanf(fp,"%d",&a);
        if (d[a-1]>i/7)
            d[a-1]=i/7;
    }
    fclose(fp);
    return d;
}
void metrix1(int n,char *str)
{
    int *d;
    d=D(n,str);
    taxinomisi(d,n);
    return;
}
int count(int n,char *str)
{
    FILE *fp;
    fp=fopen(str,"r");
    int count=0,i;
    char c=0;
    while(!c)
    {
        if(fscanf(fp,"%d",&i)<=0)
        {
            c=1;
        }
        else
        {
            if(i<1||i>49)
            {
                printf("Wrong Input!");
                return 1;
            }
            count++;
        }
    }
    fclose(fp);
    return count;
}
int *F(int n,char *str)
{
    FILE *fp;
    fp=fopen(str,"r");
    int *f,i;
    f=malloc(49*sizeof(int));
    for(i=0;i<49;i++)
        f[i]=0;
    int c=count(n,str);
    for(;c>0;c--)
    {
      fscanf(fp,"%d",&i);
      f[i-1]+=1;
     }

    fclose(fp);

    return f;
}
void metrix0(int n,char *str)
{
    int *f;
    f=F(n,str);
    taxinomisi(f,n);
    return ;
}
void taxinomisi(int *A,int n)
{
    int i,j,temp,B[49];
    for(i=0;i<49;i++)
    {
     B[i]=i;
    }
    for(i=0;i<49-1;i++)
    {
        for(j=i+1;j<49;j++)
        {
            if(A[i]<A[j]||((A[i]==A[j])&&B[i]>B[j]))
            {
                temp=A[i];
                A[i]=A[j];
                A[j]=temp;
                temp=B[i];
                B[i]=B[j];
                B[j]=temp;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d ",B[i]+1);
    }
}
