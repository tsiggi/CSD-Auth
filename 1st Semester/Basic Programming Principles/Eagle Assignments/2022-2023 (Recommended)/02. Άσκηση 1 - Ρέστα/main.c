#include <stdio.h>
#include <math.h>

int main(void) {
    int tickets;
    float money;
    scanf("%d %f", &tickets, &money);

    // tickets [1,5]     and      money [0.75 , 100]
    if (tickets>=1 && tickets<=5 && money>=0.75 && money<=100 && money>=tickets*0.75) {
        // change_in_euros = money - tickets * 0.75
        // so change_in_euros [0.00,99.25]
        // this is not helpful because we cant use MOD, DIV .
        // so we need to convert change_in_euros to change_in_cents
        int change_in_cents = round(money*100 - tickets*75.0) ;
        // so from euros we went to cents
        int two_euros = change_in_cents/200; // 2 euros == 200 cents
        change_in_cents = change_in_cents%200;
        int one_euro = change_in_cents/100; // 1 euro == 100 cents
        change_in_cents = change_in_cents%100;
        int fifty_cents = change_in_cents/50;
        change_in_cents = change_in_cents%50;
        int twenty_cents = change_in_cents/20;
        change_in_cents = change_in_cents%20;
        int ten_cents = change_in_cents/10;
        change_in_cents = change_in_cents%10;
        int five_cents = change_in_cents/5;
        change_in_cents = change_in_cents%5;

        if (two_euros>0)
            printf("%d * 2 euros\n",two_euros);
        if (one_euro>0)
            printf("%d * 1 euros\n",one_euro);
        if (fifty_cents>0)
            printf("%d * 50 cents\n",fifty_cents);
        if (twenty_cents>0)
            printf("%d * 20 cents\n",twenty_cents);
        if (ten_cents>0)
            printf("%d * 10 cents\n",ten_cents);
        if (five_cents>0)
            printf("%d * 5 cents\n",five_cents);
        if (change_in_cents>0)
            printf("%d * 1 cents\n",change_in_cents);

    }else{
        printf("Wrong input\n");
    }



    return 0;
}