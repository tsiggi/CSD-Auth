#include <stdio.h>

int main(void) {
    int year;
    scanf("%d", &year);

    if (year>0){
        // year = leap : (year%100==0 and year%400==0) or (year%4==0 and year%100!=0)
        if ((year%100==0 && year%400==0) || (year%4==0 && year%100!=0))
            printf("Leap");
        else
            printf("Normal");
    }else
        printf("Wrong Input\n");


    return 0;
}