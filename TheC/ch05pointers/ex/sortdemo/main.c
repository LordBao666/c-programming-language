#include "linetools.h"
#include "qsort.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 5000 // 如果文本达到5000行,那么代表文本过多,不进行排序
char *lineptr[MAXLINES];

// 清理lineptr的前n行
static void freeLines(char *lineptr[], int nlines) {
    for (int i = 0; i < nlines; i++) {
        free(lineptr[i]);
    }
}

// s1和s2对应的字符串转为数值进行比较
int numcmp(char *s1, char *s2);
// s1和s2进行字符串比较,忽略大小写.
// e.g A==a
int strcmpIgnoreCase(char *s1, char *s2);

int main(int argc, char *argv[]) {
    int nflag = 0; // 比较数值
    int rflag = 0; // 是否逆序
    int fflag = 0; // 是否忽略大小写
    for (int i = 1; i < argc; i++) {
        if (*argv[i]++ == '-') {
            int c = *argv[i];
            if (!c) {
                // 第i个参数是 - 这种非法字符
                printf("按照类似 sort [-nrf] 的格式输入\n");
                return -1;
            }
            while (c) {
                switch (c) {
                case 'n': {
                    nflag = 1;
                    break;
                }
                case 'r': {
                    rflag = 1;
                    break;
                }
                case 'f': {
                    fflag = 1;
                    break;
                }
                default: {
                    printf("按照类似 sort [-nrf] 的格式输入\n");
                    return -1;
                }
                }
                c = *++argv[i];
            }
        } else {
            printf("按照类似 sort [-nrf] 的格式输入\n");
            return -1;
        }
    }

    int (*comp)(void *, void *);
    // nflag 优先于 fflag
    if (nflag == 1) {
        comp = (int (*)(void *, void *))numcmp;
    } else if (fflag) {
        comp = (int (*)(void *, void *))strcmpIgnoreCase;
    } else {
        comp = (int (*)(void *, void *))strcmp;
    }

    int lines;
    // 注意readlines是通过malloc分配内存。main函数在成功读取行之后，一定要回收。
    if ((lines = readlines(lineptr, MAXLINES)) >= 0) {
        myQsort((void **)lineptr, 0, lines - 1, comp);
        if (rflag) {
            writelinesReverse(lineptr, lines, lines);
        } else {
            writelines(lineptr, lines);
        }

        freeLines(lineptr, lines);
        return 0;
    } else {
        printf("内存不足或输入文本太多\n");
        return -1;
    }
}

// s1和s2对应的字符串转为数值进行比较
int numcmp(char *s1, char *s2) {
    double v1 = atof(s1);
    double v2 = atof(s2);
    if (v1 < v2) {
        return -1;
    } else if (v1 > v2) {
        return 1;
    } else {
        return 0;
    }
}

// s1和s2进行字符串比较,忽略大小写.
// e.g A==a
int strcmpIgnoreCase(char *s1, char *s2) {
    // s1字符串未空,且当前字符相同(忽略大小写)
    while (*s1 && tolower(*s1) == tolower(*s2)) {
        s1++;
        s2++;
    }
    return tolower(*s1) - tolower(*s2);
}