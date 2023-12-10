#include <stdio.h>

int main(void) {
    int aem;
    scanf("%d", &aem);

    if (aem>0){
        // course = (aem mod 3) +1
        int course = aem%3 + 1;
        // print C1 if in 1st course , C2 if in 2nd course and C3 if in 3rd course
        printf("C%d",course);
    }else
        printf("Wrong Input\n");

    return 0;
}