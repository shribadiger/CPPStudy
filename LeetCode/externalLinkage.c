/*
 checking the object in which the data is loaded 
*/
#include<stdio.h>

int staticCheck(void) {
    static int x = 0;
    x++; // incrementing the value of x
    return x;
}

int main(void) {
    int j;
    for(j=0; j<5; j++) {
       printf("\n Value of staticCheck(): %d\n",staticCheck());
    }
    return 0;
}
