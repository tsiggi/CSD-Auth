#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void printArray(int *p,int n);
char isPrime(int a);
int *primes(int *B,int n,int *m);

int *primes(int *B,int n,int *m)
{
  int *s,i,c=0;
  s=malloc(sizeof(int));
  for(i=0;i<n;i++)
  {
    if(isPrime(B[i])==1)
    {
      if(c!=0)
      {
        s=(int *)realloc(s,(c+1)*sizeof(int));
      }
      s[c]=B[i];
      c++;
    }
  }
  *m=c;
  return s;
}

char isPrime(int a)
{
    int k,i;
    if (a<2 || (a%2==0&&a!=2))
        return 0;
    k=sqrt(a);
    if (a==2)
        return 1;
    for (i=3;i<=k;i+=2)
    {
         if (a%i==0)
            return 0;
    }
    return 1;
}
void printArray(int *p,int n)
{
  for(int i=0;i<n;i++)
  {
    printf("%d ",p[i]);
  }
}
