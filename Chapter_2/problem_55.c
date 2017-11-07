#include<stdio.h>
typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer bp, int len) {
    int i;
    for(i=0; i<len; i++) {
        printf("%02x ", bp[i]);     //?But how the pointer "bp" can be an array?
    }
    printf("\n");
}

/**
 * The Answer:
 * First of all, it's not an array.
 * The [i] means pointer "bp" should skip "i" bytes from bp[0],
 * actually, bp[0] is just the address given by parameter.
 * Even you can skip more large and out of the range, amazing? Try it. :)
 *
 * MORE:
 * In C, pointers all represented by 4 bytes,
 * the difference is that they can skip diffrent bytes.
 * For example, char pointer can only skip one byte for once, but int pointer can skip four.
 * As you see, pointer[0] is the current address,
 * pointer[i] is the later i(第i个) address, and so on.
 * However, except array.
 * Like array a[], a[0] is not an address but a data under that.
 * In this case, a==&a[0].
 */
