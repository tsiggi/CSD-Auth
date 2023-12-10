#include <stdio.h>
#include <math.h>

int main(void) {
    int binary;
    scanf("%d", &binary);

    // first we check if input has more than 5 digits
    if(binary/100000 == 0){
        // Now we check if input has only 1's or 0's
        int temp = binary;
        char flag = 1;
        while(temp !=0 && flag){
            if(temp%10!=1 && temp%10!=0){
                flag = 0;
            }
            temp = temp/10;
        }

        if(flag==1){
            // now we calculate the decimal from the binary
            int decimal = 0;
            int count = 0;
            while (binary != 0){
                if(binary%10==1){
                    decimal += pow(2, count);
                }
                count++;
                binary = binary/10;
            }
            printf("%d",decimal);
        } else{
            printf("Wrong Input");
        }
    } else{
        printf("Wrong Input");
    }

    return 0;
}