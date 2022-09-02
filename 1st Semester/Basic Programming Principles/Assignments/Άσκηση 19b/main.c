#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *applyMask(char *,char *);
int main()
{
 char *s = malloc (1000*sizeof(char));
 char *mask, *r, *r2;
 int i,n;
 fgets(s,1000,stdin);
 s[strcspn(s,"\n")] = '\0';
 n = strlen(s);
 s=realloc(s,(n+1)*sizeof(char));
 mask = malloc ((n+1)*sizeof(char));
 fgets(mask,n+1,stdin);
 mask[strcspn(mask,"\n")] = '\0';
 for (i=0;i<n;i++)
 if (mask[i]<'0' || mask[i]>'9')
 {
 printf ("Wrong input");
 return 1;
 }
 r= applyMask(s,mask);
 printf ("%s\n",s);
 printf ("%s\n",r);
 return 0;
}
char *applyMask(char *s,char *m)
{
    long long pl=strlen(s),count=0;
    char *p;
    //printf("%d\n",pl);
    for(int j=0;j<pl-1;j++)
    {
        //printf("%d\n",m[j]-48);
        count+=m[j]-48;
    }
    //printf("%d",count);
    p=(char*)malloc(2*count);
    count=0;
    for(int j=0;j<pl;j++)
    {
        for(int k=0;k<(int)m[j]-48;k++)
        {
            p[count]=s[j];
            count++;
        }
    }
    p[count]='\0';
    p=realloc(p,count+1);
    return p;
}
