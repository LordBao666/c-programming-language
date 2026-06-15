#include "getword.h"
#include "getch.h"
#include <ctype.h>
#include <stdio.h>

int getword(char *word, int lim) {
    int c;
    while (isspace(c = getch()))
        ;
    // 文件读取完毕
    if (c == EOF) {
        return EOF;
    }
    char *p = word; // 记录word起始地址
    *word++ = c;
    // c不是字母,那必然是单个字符
    if (!isalpha(c)) {
        *word = '\0';
        return c;
    }
    int cnt = 1;
    while (cnt < lim && (c = getch()) != EOF && isalnum(c)) {
        *word++ = c;
        cnt++;
    }

    if (cnt < lim) {
        if (c != EOF) { // 说明是碰到非字母或数字的字符
            ungetch(c); // 放回缓冲区
        }
    }
    *word = '\0';
    return *p;
}