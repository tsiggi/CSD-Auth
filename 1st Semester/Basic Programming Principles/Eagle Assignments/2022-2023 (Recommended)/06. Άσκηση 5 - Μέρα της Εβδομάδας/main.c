#include <stdio.h>

int main() {
    int day;  // day [1,31]
    scanf("%d",&day);

    if(day>=1 && day<=31){
        int week_day; // week_day [1,7]
        // day-1 [0,30]      (day-1)%7 [0,6]      (day-1)%7+1 [1,7]
        week_day = ((day-1)%7) + 1;

        if(week_day==1)
            printf("Monday");
        else
            if(week_day==2)
                printf("Tuesday");
            else
                if(week_day==3)
                    printf("Wednesday");
                else
                    if(week_day==4)
                        printf("Thursday");
                    else
                        if(week_day==5)
                            printf("Friday");
                        else
                            if(week_day==6)
                                printf("Saturday");
                            else
                                printf("Sunday");

    } else
        printf("Wrong Input");


    return 0;
}
