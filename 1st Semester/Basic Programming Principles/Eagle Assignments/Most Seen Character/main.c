#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100
int main(void)
{
  char str[max+1];
  int pl,i,a[95]={0},m;
  fgets(str,max+1,stdin);
  str[strcspn(str,"\n")]='\0';
 // puts(str);
  pl=strlen(str);
  for(i=0;i<pl;i++)
  {
    a[str[i]-32]++;
  }
  m=0;
  for(i=1;i<95;i++)
  {
    if(a[m]<a[i])
      m=i;
  }
  printf("%c",m+32);
  return 0;
}
