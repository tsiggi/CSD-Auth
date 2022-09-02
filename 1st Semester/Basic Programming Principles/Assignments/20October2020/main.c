ask 11 "1"

/*
11.	Να γραφεί πρόγραμμα το οποίο δέχεται ως είσοδο τον αριθμό μιας ημέρας 1-7 και εμφανίζει το αντίστοιχο λεκτικό της ημέρας Κυριακή- Σάββατο.
*/

#include <stdio.h>

int main(void)
{
    int k;

    printf ("Give me an integer in [1,7]: ");
    scanf ("%d",&k);
    if (k<1 || k>7)
    {
        printf ("Out of bounds.\n");
        return 1;
    }

    if (k==1)
        printf ("Kyriaki\n");
    else
        if (k==2)
            printf ("Deytera\n");
        else
            if (k==3)
                printf ("Triti\n");
            else
                if (k==4)
                    printf ("Tetarti\n");
                else
                    if (k==5)
                        printf ("Pempti\n");
                    else
                        if (k==6)
                            printf ("Paraskevi\n");
                        else
                            printf ("Savvato\n");
    return 0;
}
h me thn entolh switch-case
/*
11.	Να γραφεί πρόγραμμα το οποίο δέχεται ως είσοδο τον αριθμό μιας ημέρας 1-7 και εμφανίζει το αντίστοιχο λεκτικό της ημέρας Κυριακή- Σάββατο.
*/

#include <stdio.h>

int main(void)
{
    int  k;

    printf ("Give me an integer in [1,7]: ");
    scanf ("%d",&k);


    switch (k)
    {
        case 1 :
                printf ("Kyriaki\n");
                printf ("No school\n");
                break;
        case 2 :
                printf ("Deytera\n");
                break;
        case 3:
                printf ("Triti\n");
                break;
        case 4:
                printf ("Tetarti\n");
                break;
        case 5:
                printf ("Pempti\n");
                break;
        case 6:
                printf ("Paraskevi\n");
                break;
        case 7:
                printf ("Savvato\n");
                break;
        default:
                printf ("Out of bounds.\n");
    }
    return 0;
}



ask 8 "0"
/*Να γραφεί πρόγραμμα το οποίο θα διαβάζει το χρόνο (σε εκατοστά του
δευτερολέπτου) που χρειάστηκε ένας αθλητής για να τρέξει μια απόσταση και θα
εμφανίζει το χρόνο σε ώρες, λεπτά, δευτερόλεπτα και εκατοστά του δευτερολέπτου.
*/
#include <stdio.h>

int main(void)
{
    int time, h,m,s,s100;

    printf ("Give time: ");
    scanf ("%d",&time);

    s100 = time % 100;
    time = time / 100;

    h = time/3600;
    time = time % 3600;

    m = time/60;
    time = time % 60;

    s = time;

    printf ("h: %d, m:%d, s:%d, s100:%d\n",h,m,s,s100);
    return 0;
}

/*Να γραφεί πρόγραμμα το οποίο θα διαβάζει το αρχικό κεφάλαιο που κατέθεσε ένας καταθέτης σε έναν τραπεζικό λογαριασμό και το επιτόκιο
που του δίνει η τράπεζα και να εμφανίζει το ποσό που θα έχει στο λογαριασμό του μετά από ένα, δύο και τρία χρόνια αντίστοιχα.


#include <stdio.h>

int main(void)
{
    float balance, rate, a1y, a2y, a3y;

    printf ("Give initial balance and rate: ");
    scanf ("%f %f",&balance, &rate);

    printf ("Give initial balance: ");
    scanf ("%f",&balance);
    printf ("Give rate: ");
    scanf ("%f",&rate);

    //a1y = balance + rate/100*balance;
    balance += rate/100*balance;
    printf ("1 yeard: %.2f€\n",balance);

    balance += rate/100*balance;
    printf ("2 year: %.2f€\n",balance);

    balance += rate/100*balance;
    printf ("3 year: %.2f€\n",balance);


    //a2y = a1y + rate/100*a1y;
 //   printf ("2 year: %.2f€\n",a2y);

    //a3y = a2y + rate/100*a2y;
   // printf ("3 year: %.2f€\n",a3y);

   return 0;
}
 */

/*Να γραφεί πρόγραμμα το οποίο θα διαβάζει 2 αξκέραιους αριθμούς και θα εμφανίζει το άθροισμα, το πηλίκο, το γινόμενο και την διαφορά τους.
*/
/*
#include <stdio.h>

int main(void)
{
    int num1, num2;
    int sum, minus, times;
    float div;


    printf ("Give me two integer: ");
    scanf ("%d %d",&num1, &num2);

    sum = num1+num2;
    minus = num1-num2;
    times = num1*num2;


    printf ("%d+%d= %d\n",num1,num2,sum);
    printf ("%d-%d= %d\n",num1,num2,minus);
    printf ("%d*%d= %d\n",num1,num2,times);
    if (num2!=0)
    {
        div = num1/(float)num2;
        printf ("%d/%d= %.2f\n",num1,num2,div);
    }
    else
    {
        printf ("%d/%d= infinite number\n",num1,num2);
    }



    return 0;
}
*/














