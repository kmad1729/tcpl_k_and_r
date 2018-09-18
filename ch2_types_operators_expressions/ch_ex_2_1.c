/*
 * ch_ex_2_1.c
 * Write a program to determine the ranges of char, short, int, and long variables
 * both signed and unsigned, by printing appropriate values from standard headers
 * and by direct computation. Harder if you compute them: determine the ranges of
 * various floating point types.
 */

#include <float.h>
#include <limits.h>
#include <stdio.h>

//idea: increase each data type till n+1 < n
//it rolls over since everything is modulo 2^n

int main() {
    int enable_long_running = 0;
    char delim[] = "***************\n";
    unsigned char us_prev_char = 0;
    unsigned char us_next_char = us_prev_char - 1;

    signed char s_prev_char = 0;
    signed char s_next_char = us_prev_char - 1;

    unsigned short us_prev_short = 0;
    unsigned short us_next_short = us_prev_short - 1;

    signed short s_prev_short = 0;
    signed short s_next_short = us_prev_short - 1;

    unsigned int us_prev_int = 0;
    unsigned int us_next_int = us_prev_int - 1;

    signed int s_prev_int = 0;
    signed int s_next_int = us_prev_int - 1;

    unsigned long us_prev_long = 0;
    unsigned long us_next_long = us_prev_long - 1;
    unsigned long max_computed_unsigned_long = 0;

    signed long s_prev_long = 0;
    signed long s_next_long = us_prev_long - 1;
    signed long min_computed_signed_long = 0;
    signed long max_computed_signed_long = 0;

    //char
    printf("unsigned char -->\n");
    while(us_next_char < us_prev_char) {
        us_prev_char = us_next_char--;
    }
    printf("\tminimum unsigned char = %u\n", us_prev_char);
    us_prev_char = 0;
    us_next_char = us_prev_char + 1;
    while(us_next_char > us_prev_char)
        us_prev_char = us_next_char++;
    printf("\tmaximum unsigned char = %d\n", us_prev_char);

    printf("signed char -->\n");
    while(s_next_char < s_prev_char) {
        s_prev_char = s_next_char--;
    }
    printf("\tminimum signed char = %d\n", s_prev_char);
    s_prev_char = 0;
    s_next_char = s_prev_char + 1;
    while(s_next_char > s_prev_char)
        s_prev_char = s_next_char++;
    printf("\tmaximum signed char = %d\n", s_prev_char);

    //from limits.h
    printf("UCHAR_MAX = %d\n", UCHAR_MAX);
    printf("CHAR_MIN = %d\nCHAR_MAX = %d\n", CHAR_MIN, CHAR_MAX);

    printf("%s", delim);

    //short : `short` is shorthand for `short int`
    printf("unsigned short -->\n");
    while(us_next_short < us_prev_short)
        us_prev_short = us_next_short--;
    printf("\tminumum unsigned short = %d\n", us_prev_short);

    us_prev_short = 0;
    us_next_short = us_prev_short + 1;
    while(us_next_short > us_prev_short)
        us_prev_short = us_next_short++;
    printf("\tmaximum unsigned short = %d\n", us_prev_short);

    printf("signed short -->\n");
    s_prev_short = 0;
    s_next_short = s_prev_short - 1;
    while(s_next_short < s_prev_short)
        s_prev_short = s_next_short--;
    printf("\tminimum signed short = %d\n", s_prev_short);

    s_prev_short = 0;
    s_next_short = s_prev_short + 1;
    while(s_next_short > s_prev_short)
        s_prev_short = s_next_short++;
    printf("\tmaximum signed short = %d\n", s_prev_short);
    printf("USHRT_MAX = %d\nSHRT_MIN = %d\nSHRT_MAX = %d\n", USHRT_MAX, SHRT_MIN, SHRT_MAX);
    printf("%s", delim);

    //int
    if(enable_long_running) {
        printf("unsinged int-->\n");
        us_prev_int = 0;
        us_next_int = us_prev_int - 1;
        while(us_next_int < us_prev_int)
            us_prev_int = us_next_int--;
        printf("\tminimum unsigned int = %u\n", us_prev_int);

        us_prev_int = 0;
        us_next_int = us_prev_int + 1;
        while(us_next_int > us_prev_int)
            us_prev_int = us_next_int++;
        printf("\tmaximum unsigned int = %u\n", us_prev_int);

        printf("signed int -->\n");
        s_prev_int = 0;
        s_next_int = s_prev_int - 1;
        while(s_next_int < s_prev_int)
            s_prev_int = s_next_int--;
        printf("\tminimum signed int = %d\n", s_prev_int);

        s_prev_int = 0;
        s_next_int = s_prev_int + 1;
        while(s_next_int > s_prev_int)
            s_prev_int = s_next_int++;
        printf("\tmaximum signed int = %d\n", s_prev_int);
    }

    printf("UINT_MAX = %u\nINT_MIN = %d\nINT_MAX = %d\n", UINT_MAX, INT_MIN, INT_MAX);
    printf("%s", delim);

    if(enable_long_running) {
        //long
        printf("unsigned long-->\n");
        us_prev_long = 0;
        us_next_long = us_prev_long - 1;
        while(us_next_long < us_prev_long)
            us_prev_long = us_next_long--;
        printf("\tminimum unsigned long = %lu\n", us_prev_long);

        us_prev_long = 0;
        us_next_long = us_prev_long + 1;
        while(us_next_long > us_prev_long)
            us_prev_long = us_next_long++;
        printf("\tmaximum unsigned long = %lu\n", us_prev_long);

        printf("signed long -->\n");
        s_prev_long = 0;
        s_next_long = s_prev_long - 1;
        while(s_next_long < s_prev_long)
            s_prev_long = s_next_long--;
        printf("\tminimum signed long = %ld\n", s_prev_long);
        s_prev_long = 0;
        s_next_long = s_prev_long + 1;
        while(s_next_long > s_prev_long)
            s_prev_long = s_next_long++;
        printf("\tmaximum signed long = %ld\n", s_prev_long);
    }
    max_computed_unsigned_long = ~(0ul);
    printf("max computed unsigned long = %lu\n", max_computed_unsigned_long);
    min_computed_signed_long = (1L << ((8 *(sizeof(long)))-1));
    printf("min computed signed long = %ld\n", min_computed_signed_long);
    max_computed_signed_long = ~min_computed_signed_long;
    printf("max computed signed long = %ld\n", max_computed_signed_long);

    printf("ULONG_MAX = %lu\nLONG_MIN = %ld\nLONG_MAX = %ld\n", ULONG_MAX, LONG_MIN, LONG_MAX);
    printf("%s", delim);

    printf("FLT_MIN=%f\nFLT_MAX=%f\n", FLT_MIN, FLT_MAX);
}
