#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void chars(char *s, char *most_seen, char *less_seen);
char *reverse (char *s);

void chars(char *s, char *most_seen, char *less_seen)
{
    int i,pl= strlen(s),min,tmax,tmin,max;
    int count[122-58]={0};
    for(i=0;i<pl;i++)
    {
        if(s[i]-58>=0)
            count[s[i]-58]++;
    }
    max=-1;
    min=10000;
    for(i=0;i<122-58;i++)
    {
        if(max<count[i])
         {
             max=count[i];
             tmax=i;
         }
        if(min>count[i]&&count[i]>0)
        {
            min=count[i];
            tmin=i;
        }
    }
    *most_seen=(char) tmax+58;
    *less_seen=(char) tmin+58;
}
char *reverse (char *s)
{
    long long pl=strlen(s);
    int i;
    char tmp;
    char *str;
    str=malloc(pl);
    strcpy(str,s);
    for(i=0;i<pl/2;i++)
    {
        tmp=str[i];
        str[i]=str[pl-i-1];
        str[pl-i-1]=tmp;
    }
    return str;
}
