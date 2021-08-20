#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>

int main(){
    char input[]="(shrikant) (Badiger) ((Indi)(Bijapur))";
    int index=0;
    int lengthOfInput=(int)strlen(input);
    printf(" Length of String : %d\n",lengthOfInput);
    char* result=(char*)malloc(sizeof(char)*lengthOfInput);
    char* itr=result;
    for(;index<lengthOfInput;index++){
        if(input[index] =='('){
            printf("\n Begin Paranthesis found");
            continue;
        }
        else if (input[index] == ')'){
            printf("\n Closing Paranthesis found");
            continue;
        }
        else {
            *itr=input[index];
            itr++;
        }
    }
    printf("\n Final Result = %s",result);
    return 0;
}
