#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n,i=0;
    char c;
    scanf("%d",&n);

    char *name[n],B[n];
    int ar[n];

    for(i=0;i<n;i++)
    {
      while((c = getchar()) !='\n' && c!= EOF);
      name[i]=malloc(100000000*sizeof(int));
      fgets(name[i],100000000,stdin);
      name[i][strcspn(name[i],"\n")]='\0';
      printf("%ld\n",sizeof(*name[i]));
      //name[i]=realloc(name[i],(strlen(name[i])+1)*sizeof(char));
      printf("%ld\n",sizeof(*name[i]));
      scanf("%c",&B[i]);
      while((c = getchar()) !='\n' && c!= EOF);
      scanf("%d",&ar[i]);
    }
    int sort[100000];
    for(i=0;i<100000;i++)
        sort[i]=-1;
    for(i=0;i<n;i++)
        sort[ar[i]]=i;
    for(i=0;i<100000;i++)
    {
         if(sort[i]!=-1)
            printf("%s, %c, %d\n",name[sort[i]],B[sort[i]],ar[sort[i]]);
    }
    return 0;
}
