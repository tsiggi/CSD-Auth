#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100
void wronginput(char a[])
{
    int i,sa;
    sa=strlen(a);
    for (int i=0;i<sa;i++)
    {
        if(a[i]<'a'||a[i]>'z')
        {
            printf("Wrong Input");
            exit(1);
        }
    }
    return ;
}
char check(char l1[],char l2[])
{
    int i,s1,s2,a1[26]={0},a2[26]={0};
    s1=strlen(l1);
    s2=strlen(l2);
    if(s1!=s2)
        return 0;
    for(i=0;i<s1;i++)
    {
        a1[l1[i]-97]++;
        a2[l2[i]-97]++;
    }
    for(i=0;i<26;i++)
    {
        if(a1[i]!=a2[i])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    char l1[max+1],l2[max+1];
    fgets(l1,max+1,stdin);//διαβαζω την πρωτη λεξη και βγαζω το εντερ απο το τελος
    l1[strcspn(l1,"\n")]='\0';
    fgets(l2,max+1,stdin);//το ιδιο και για την δευτερη
    l2[strcspn(l2,"\n")]='\0';
    wronginput(l1);//για λαθος εισοδο
    wronginput(l2);
    if (check(l1,l2)==1)
        printf("Yes");
    else
        printf("No");
    return 0;
}
