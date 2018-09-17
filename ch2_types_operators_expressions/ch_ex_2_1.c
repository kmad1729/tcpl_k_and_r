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
    unsigned char us_prev = 0;
    unsigned char us_next = us_prev - 1;

    signed char s_prev = 0;
    signed char s_next = us_prev - 1;

    //char
    printf("unsigned char -->\n");
    while(us_next < us_prev) {
        us_prev = us_next--;
    }
    printf("minimum unsigned char = %d\n", us_prev);
    us_prev = 0;
    us_next = us_prev + 1;
    while(us_next > us_prev)
        us_prev = us_next++;
    printf("maximum unsigned char = %d\n", us_prev);

    printf("signed char -->\n");
    while(s_next < s_prev) {
        s_prev = s_next--;
    }
    printf("minimum signed char = %d\n", s_prev);
    s_prev = 0;
    s_next = s_prev + 1;
    while(s_next > s_prev)
        s_prev = s_next++;
    printf("maximum signed char = %d\n", s_prev);

    //from limits.h
    printf("UCHAR_MAX = %d\n", UCHAR_MAX);
    printf("CHAR_MIN = %d\nCHAR_MAX = %d\n", CHAR_MIN, CHAR_MAX);

    printf("%s", delim);
}
