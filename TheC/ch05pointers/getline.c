#include "getline.h"
#include <stdio.h>

#define ARGUMENT_ERROR -2       // 表示参数错误
int getline(char *s, int max) {
    if (max < 2) {
        printf("输入的max非法,应该至少为2\n");
        return ARGUMENT_ERROR;
    }

    // 边界情况
    int c = getchar();
    if (c == EOF) {
        return EOF;
    }
    if (c == '\n') {
        *s++ = '\n'; // 等价于*s=c,s++;
        *s = '\0';
        return 1;
    }

    *s++ = c;
    int cnt = 1;
    while (cnt < max - 1 && (c = getchar()) != EOF && c != '\n') {
        *s++ = c; // 等价于*s=c,s++;
        cnt++;
    }
    if (c == '\n') {
        *s++ = '\n';
        cnt++;
    }
    *s = '\0';
    return cnt;
}
