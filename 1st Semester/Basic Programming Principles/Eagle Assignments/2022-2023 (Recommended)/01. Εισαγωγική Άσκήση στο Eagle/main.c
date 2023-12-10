#include <stdio.h>

int main(void) {
    // initial and read the input
    long long input;
    scanf("%lld", &input);

    // f(x) = (x*x -3)/(x-3)
    if (input==3) {
        // if input is 3 then we have division with 0 => INFINITE
        printf("Infinite");
    }else{
        double output;
        // output = f(input)
        output = (input * input - 3) / (1.0 * (input - 3));

        // print the double number with 1 number after the decimal point
        printf("%.1f\n", output);
    }



    return 0;
}