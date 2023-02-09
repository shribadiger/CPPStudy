/* code to check the multiple goto statements in the given code */
#include<iostream>
using namespace std;

int main() {
    char userInput; // collect the user input and act accordingly
    while(1) { 
       printf("\n Please enter any char:");
       scanf("%c",&userInput);
       if(userInput=='a') {
           goto apple;
       } else if (userInput == 'b') {
           goto ball;
       } else if (userInput =='c') {
           goto cat;
       } else {
            goto out;
       }
    }
    apple:
	printf("\n Apple Invoked");
    ball:
        printf("\n Ball Invoked");
    cat: 
        printf("\n Cat Invoked");
    out:
        printf("\n Error: Please check your input");
    return 0;
}
