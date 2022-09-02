#include <stdio.h>
char * readfromKeyboard();
char * removeNonLatin(char *);
int * getLetters(char *);
void printLetters(int *);
void getMaxMin(int *, int *, int *);
char * encode(int *);
int main()
{
 char *s, *s2, *s3;
 int *Letters,i,max,min;
 Letters=malloc(26*sizeof(int));
 for(int i=0;i<26;i++)
    Letters[i]=0;
 Letters[0]=1;
 s3 = encode(Letters);
 printf ("%s\n",s3);
 printf ("%s\n",s3);
 printf ("%s\n",s3);
 printf ("%s\n",s3);


 return 0;
}
