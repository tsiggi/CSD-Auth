#include <stdio.h>
#include <math.h>

int main() {
    int decimal;  // decimal [0,31]
    scanf("%d",&decimal);

    if(decimal>=0 && decimal<=31){
        int binary = 0;   // stores the binary that came from the decimal
        int digit_of_the_binary = 0;    // counts the digits of the binary

        // Convert Decimal to Binary
        while (decimal!=0){
            // if decimal MOD 2 == 1 then the "digit_of_the_binary" is 1, else is 0
            if(decimal%2==1){
                binary += pow(10,digit_of_the_binary);
            }
            // count = count + 1 , because we are going to the next digit of the binary
            digit_of_the_binary++;
            // decimal = decimal DIV 2 , inorder to find the next digit of the binary;
            decimal /= 2;
        }
        // prints the binary
        printf("%d",binary);
    } else
        printf("Wrong Input");


    return 0;
}
