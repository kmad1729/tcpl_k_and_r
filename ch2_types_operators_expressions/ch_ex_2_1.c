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
    char delim[] = "***************\n";
    unsigned char us_prev_char = 0;
    unsigned char us_next_char = us_prev_char - 1;

    signed char s_prev_char = 0;
    signed char s_next_char = us_prev_char - 1;

    unsigned short us_prev_short = 0;
    unsigned short us_next_short = us_prev_short - 1;

    signed short s_prev_short = 0;
    signed short s_next_short = us_prev_short - 1;

    //char
    printf("unsigned char -->\n");
    while(us_next_char < us_prev_char) {
        us_prev_char = us_next_char--;
    }
    printf("\tminimum unsigned char = %d\n", us_prev_char);
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


}
