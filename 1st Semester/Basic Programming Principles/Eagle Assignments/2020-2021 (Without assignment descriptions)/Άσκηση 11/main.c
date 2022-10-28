#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int count(int x,int y,int z,int i)
{
    int s=0;
    //printf("x=%d y=%d i=%d \n",x,y,i);
    if(x==0)
    {
        if(y==0)
            return 1;
        else
            return 0;
    }
    for (;i<=z;i*=2)
        s= s + count(x-1,y-i,z,i);
    return s;

}
int main()
{
    int n,m,x;
    scanf("%d %d %d",&n,&m,&x);
    if(n<1||n>10||m<1||m>1024||x<1||x>9)
    {
        printf("Wrong Input");
        return 1;
    }

    if(count(n,m,pow(2,x),2)>0)
        printf("Yes");
    else
        printf("No");
    /*
    if(m%2==1||m>n*pow(2,x))
    {
        printf("No");

    }
    else
        printf("Yes");

*/
    return 0;
}
