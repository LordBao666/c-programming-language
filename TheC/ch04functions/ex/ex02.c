#include <ctype.h>
#include <stdio.h>
// 注意到stdlib.h 自身已经定义了atoi 和 atof函数

/**
 * Exercise 4-2 Extend atof to handle scientific notation of the form 123.45e-6 where a floating-point *  number may be followed by e or E and an optionally signed exponent
 */
double atof(char s[]) {
    double val, power;
    int i, sign;
    for (i = 0; isspace(s[i]); i++) /* 跳过空格 */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }

 

    // 在课堂基础上添加如下代码
    double ans = sign * val / power;
    if (s[i] == 'e' || s[i] == 'E') {
        i++;
        int exponent = 0;
        int exponentSign = 1;
        if (s[i] == '-') {
            exponentSign = -1;
            i++;
        } else if (s[i] == '+') {
            exponentSign = 1;
            i++;
        }
        // else 没有表示正负,默认就是正,即exponentSign = 1

        for (; isdigit(s[i]); i++) {
            exponent = exponent * 10 + (s[i] - '0');
        }

        if (exponentSign == 1) {
            for (int j = 0; j < exponent; j++) {
                ans = ans * 10;
            }
        } else {
            for (int j = 0; j < exponent; j++) {
                ans = ans / 10;
            }
        }
    }


    return ans;
}

int main() {
    char a[] = "12342.2e-2";
    char b[] = "12345678901e-11";
    char c[] = "12.345e2";
    char d[] = "12.345e+2";
    printf("%f\n", atof(a));
    printf("%f\n", atof(b));
    printf("%f\n", atof(c));
    printf("%f\n", atof(d));
}