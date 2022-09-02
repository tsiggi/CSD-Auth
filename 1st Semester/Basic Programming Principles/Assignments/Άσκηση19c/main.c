#include <stdio.h>
#include <stdlib.h>
#include "library.h"
int main()
{
 int *B,n,*P,m,i;
 scanf ("%d",&n);
 B= malloc(n*sizeof(int));
 if (B!=NULL)
 {
 for (i=0;i<n;i++)
 scanf("%d",&B[i]);
 P = primes(B,n,&m);
 printArray(P,m);
 }
 return 0;
}
