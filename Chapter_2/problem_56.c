/**
 * When using the function show_bytes(), it required us to input two values.
 * However, these two valus are both about one parameter, address and it's length.
 * Is there a way that we just need to input one value but got the right answer eventually?
 * I hava tried like this:
 * Notice, it is BUGGY codes.
 */

#include<stdio.h>
typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer bp) {
    int i;
    int len = sizeof(*bp);
    for(i=0; i<len; i++) {
        printf("%02x ", bp[i]);
    }
    printf("\n");
}

/**
 * But why?
 * You know that "[type] *pointer" decleared a pointer who pointed at a [type] value,
 * thus the "sizeof(*pointer)" is just the "sizeof([type])".
 * However, whatever the parameter was it will be transformed as byte_pointer type eventually,
 * so the value of "sizeof(*bp)" always equalls 1. That's the reason.
 *
 * Emmm, it could be improved?
 * How about that:
 */

#include<stdio.h>
typedef unsigned char *byte_pointer;

void show_bytes(void *p) {
	byte_pointer bp = p;
	int len = sizeof(*p);
    int i;
    for(i=0; i<len; i++) {
        printf("%02x ", bp[i]);
    }
    printf("\n");
}

/**
 * It looks resonable, But it can't work. T_T
 * Because the "void *" is none type pointer, function sizeof can't calculate its value.
 *
 * So, don't be lazy. :)
 */
