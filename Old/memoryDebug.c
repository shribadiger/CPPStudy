/*
 * This is a program to use mtrace function to track the memory allocation
 */
#include<stdio.h>
#include<stdlib.h>

// Here we are definig the debug option to handle
#ifdef DEBUG_ON
#include<mcheck.h>
#endif

struct Data {
        int IntValue;
        double DoubleValue;
        char CharArray[20];
};

struct Data* allocate_memory(unsigned int count) {
        return (struct Data*) malloc(count*sizeof(struct Data));
}

int main() {
#ifdef DEBUG_ON
        mtrace();
#endif
        struct Data* ptr = allocate_memory(7);
        printf("\n Size of the Data struct %ld bytes\n", sizeof(*ptr));

#ifdef DEBUG_ON
        muntrace();
#endif
        return 0;
}
