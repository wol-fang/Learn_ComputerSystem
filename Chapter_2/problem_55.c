#include<stdio.h>
typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer bp, int len) {
    int i;
    for(i=0; i<len; i++) {
        printf("%02x ", bp[i]);     //?But how the pointer "bp" can be an array?
    }
    printf("\n");
}
