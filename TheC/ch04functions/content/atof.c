#include <ctype.h>
#include <stdio.h>
#define MAXLINE 100
// 注意到stdlib.h 自身已经定义了atoi 和 atof函数

/* atof: convert string s to double */
double atof(char s[]) {
    double val, power;
    int i, sign;
    for (i = 0; isspace(s[i]); i++) /* skip white space */
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
    return sign * val / power;
}

int getline(char line[], int max) {
    if (max <= 0) {
        printf("max 不能小于等于0");
        return -1;
    }
    char c = '\0'; // 初始化为任何除了'\n'的值都行
    int cnt = 0;   // 记录读取多少字符
    while (cnt < max - 1 && (c = getchar()) != EOF && c != '\n') {
        line[cnt++] = c;
    }
    if (c == '\n') {
        line[cnt++] = c;
    }
    line[cnt] = '\0';
    return cnt;
}

int main() {
    double sum = 0;
    char line[MAXLINE];
    while (getline(line, MAXLINE) > 0)
        printf("\t%g\n", sum += atof(line));
    return 0;
}