#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a,b,c,d;
    scanf("%d.%d.%d.%d",&a,&b,&c,&d);
    if (a<0 || a >255 || b<0 || b >255 || c<0 || c >255 ||d<0 || d >255 )
    {
        printf("Wrong input");
        exit(1);
    }
    if (a<=127)
    {
        printf("Class A\n");
        if (a==10 && b>=0 && b<=255 && c>=0 && c<=255 && d>=0 && d<=255 )
        {
            printf("Private");
        }
        else
        {
            printf("Public");
        }
    }
    if (a>=128 && a<=191)
    {
       printf("Class B\n");
       if (a==172 && b>=16 && b<=31 && c>=0 && c<=255 && d>=0 && d<=255 )
        {
            printf("Private");
        }
        else
        {
            printf("Public");
        }
    }
    if (a>=192 && a<=223)
    {
       printf("Class C\n");
       if (a==192 && b==168 && c>=0 && c<=255 && d>=0 && d<=255 )
        {
            printf("Private");
        }
        else
        {
            printf("Public");
        }
    }
    return 0;
}

/* int main()
{
    int x1;
    int x2;
    int x3;
    int x4;

    scanf("%d.%d.%d.%d", &x1, &x2, &x3, &x4);

    if (x1 < 0 || x1 > 255
        || x2 < 0 || x2 > 255
        || x3 < 0 || x3 > 255
        || x4 < 0 || x4 > 255) {
            printf("Wrong input");
            return 0;
    }

    char taksi = '\0';

    if (x1 >= 0 && x1 <= 127) {
        taksi = 'A';
    } else if (x1 >= 128 && x1 <= 191) {
        taksi = 'B';
    } else if (x1 >= 192 && x1 <= 223) {
        taksi = 'C';
    }

    int isPrivate = 0;

    if (x1 == 10
        || (x1 == 172 && (x2 >= 16 && x2 <= 31))
        || (x1 == 192 && x2 == 168)
    )
        isPrivate = 1;

    printf("Class %c\n", taksi);

    if (isPrivate == 1)
        printf("Private");
    else
        printf("Public");


    return 0;
}
#include <stdio.h>
int main(void)
{
    int a,b,c,d;
    char public = 1;

    scanf("%d.%d.%d.%d",&a,&b,&c,&d);
    if (a<0 || a>255 || b<0 || b>255 || c<0 || c>255 || d<0 || d>255)
    {
        printf ("Wrong input\n");
        //return 1;
    }
    else
    {
        if (a<128)
        {
            printf ("Class A\n");
            if (a==10)
                public =0;
        }
        else
        {
            if (a<192)
            {
                printf ("Class B\n");
                if (a==172 && b>=16 && b<=31)
                    public = 0;
            }
            else
            {
                if (a<224)
                {
                    printf ("Class C\n");
                    if (a==192 && b==168)
                        public = 0;
                }
            }
        }
        if (public!=0)
            printf ("Public\n");
        else
            printf ("Private\n");
    }
    return 0;
}

*/
