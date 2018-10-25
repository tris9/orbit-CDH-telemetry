#include <stdio.h>
#include <stdint.h>

#define SIZE 4

int main(){
    /**
     * If we receive a transmission in the form of an int
     * we can parse out the values if we have a codified
     * way of where to look
     * */

    //Example of the transmission
    uint16_t r = 50017;

    //Mask to get the value equal to 1111 0000 0000 0000
    uint16_t mask = 61440;

    //Array to store the values, could be replaced with struct
    uint16_t a[SIZE];

    for(uint8_t i = 0; i < SIZE; i++){
        a[i] = (r & mask) >> ((SIZE - 1 - i) * SIZE);
        mask = mask >> SIZE;
    }

    printf("Original Number: 50017 = 1100 0011 0110 0001\n");

    for(uint8_t i = 0; i < SIZE; i++){
        printf("%d\n", a[i]);
    }

    printf("12 = 1100\n3 = 0011\n6 = 0110\n1 = 0001");

    return 0;
}

/**
 * We can scale up and down the size of the transmission as well as the size
 * of the values parsed. The only downside being is that the parsed size must
 * be consistent unless we want to do the parsing manually.
 * */