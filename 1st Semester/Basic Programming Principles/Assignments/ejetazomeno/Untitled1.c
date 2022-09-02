#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char * readfromKeyboard();
char * removeNonLatin(char *);
int * getLetters(char *);
void printLetters(int *);
void getMaxMin(int *, int *, int *);
char * encode(int *);

char * readfromKeyboard()
{
    char *str;
    str=malloc(20*sizeof(char));
    fgets(str,19,stdin);
    str[19]='\0';
    str[strcspn(str,"\n")]='\0';

    return str;
}
char * removeNonLatin(char *str1)
{
    char *str2;
    int c=strlen(str1),j=0;
    str2=malloc((c+1)*sizeof(char));
    for (int i=0;i<c;i++)
    {
        if(str1[i]>='a'&&str1[i]<='z')
        {
            str2[j]=str1[i];
            j++;
        }
        else
        {
            if(str1[i]>='A'&&str1[i]<='Z')
            {
                str2[j]=str1[i]+32;
                j++;
            }
        }
    }
    str2[j]='\0';
    return str2;
}
int * getLetters(char *str)
{
    int *s,count,i;
    count=strlen(str);
    s=malloc(26*sizeof(int));
    for(i=0;i<count;i++)
    {
        s[i]=0;
    }
    for(i=0;i<count;i++)
    {
        s[str[i]-97]++;
    }
    return s;
}

void printLetters(int *a)
{
    int i,j,count=0;
    count=0;
    for(i=0;i<26;i++)
    {
        if(a[i]>0)
        {
            count+=1;
        }
    }
    for(i=0;i<26;i++)
    {
        if(a[i]>0)
        {
            printf("%c: %d",i+97,a[i]);
            count--;
            if(count!=0)
            {
                printf(",");
                printf(" ");
            }
        }
    }
    printf("\n");
    return;
}
void getMaxMin(int *A, int *max, int *min)
{
    int i,k=0,l=0;
    for(i=0;i<26;i++)
    {
        if(A[k]<A[i])
        {
            k=i;
        }
        if(A[l]>A[i])
        {
             l=i;
        }
    }
    *min=l;
    *max=k;
}

char * encode(int *A)
{
    int i=0,count,j=0;
    char *c;
    for(i=0,count=0;i<26;i++)
    {
        count+=A[i];
    }

    c=malloc((count+1)*sizeof(char));

    count=0;
    for(i=0;i<26;i++)
    {
        if(A[i]>0)
        {
            j=A[i];
            for(int k=0;k<j;i++)
            {
                c[count+k]=i+97;
            }
            count+=A[i];
        }
    }
    c[count]='\0';
    return c;
}
