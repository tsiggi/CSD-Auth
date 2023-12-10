#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define pl 30
void Matching_Chars(char a[],char b[])
{
    int gram[26]={0},i=0;
    for(int i=0;a[i]!='\0';i++)
        gram[a[i]-'a']++;
    for(int i=0;b[i]!='\0';i++)
        gram[b[i]-'a']--;

    for(i=0;i<26;i++)
    {
        if(gram[i]>0)
        {
            printf("No");
            return ;
        }
    }
    printf("Yes");
    return;
}
int main()
{
    char a[pl],b[pl],flag=1;
    fgets(a,pl,stdin);
    a[strcspn(a,"\n")]='\0';
    fgets(b,pl,stdin);
    b[strcspn(b,"\n")]='\0';
    Matching_Chars(a,b);
    return 0;
}

