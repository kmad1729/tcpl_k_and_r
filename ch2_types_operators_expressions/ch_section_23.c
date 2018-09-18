/*examples in section 2.3
 * Constants
 *  integer constant -> 1234
 *  long constant -> 1234l or 1234L
 *  unsigned long constant -> 1234ul or 1234UL
 *  floating point constant 123.4f or 1e-2F
 *  double constant 12.3 or 12.34d
 */

#include <stdio.h>
#include <string.h>

#define VTAB '\013'

enum months {JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};

int tb_strlen_impl(char s[]);

int main() {
    int int_const = 1234;
    long long_const = 1234l;
    long long_const2 = 1234L;
    unsigned long ulong_const = ~(0l);
    float float_const = 3.1416f;
    double double_const = 3.14;

    enum boolean {NO, YES};

    char char_const1 = '0';
    char char_const_null = '\0';
    char string_concat_example[] = "hello, " "world "
        "welcome to c! "
        "where strings are concatenated across "
        "lines!";

    printf("int_const = %d\n", int_const);
    printf("long_const = %ld\n", long_const);
    printf("long_const = %ld\n", long_const2);
    printf("ulong_const = %lu\n", ulong_const);

    printf("float_const = %f\n", float_const);
    printf("double_const = %g\n", double_const);

    if(char_const_null == 0)
        printf("char_const_null is equal to int value 0!\n");

    printf("char_const1 = %c(char); char_const1 = %d(int)\n", char_const1, char_const1);

    if(VTAB == 11)
        printf("value of VTAB = 11!\n");
    if(VTAB == 013)
        printf("value of VTAB = 013!\n");
    if(VTAB == 0xb)
        printf("value of VTAB = 0xb!\n");

    printf("string_concat_example = (%s)\n", string_concat_example);

    printf("tb_strlen_impl(string_concat_example) = %d\n", tb_strlen_impl(string_concat_example));
    printf("string.h strlen(string_concat_example) = %lu\n", strlen(string_concat_example));

    if(NO == 0)
        printf("enum NO = 0!\n");

    if(YES == 0x1)
        printf("enum YES = 0x1!\n");

    printf("MAY month = %d\n", MAY);

}

int tb_strlen_impl(char s[]) {
    int i;
    i = 0;
    while(s[i] != '\0')
        ++i;
    return i;
}
