#include "linetools.h"
#include "qsort.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 5000 // 如果文本达到5000行,那么代表文本过多,不进行排序
char *lineptr[MAXLINES];
int nflag = 0; // 比较数值
int rflag = 0; // 是否逆序
int fflag = 0; // 是否忽略大小写
int dflag = 0; // directory 序,即只考虑空格,字母和数字

// 清理lineptr的前n行
static void freeLines(char *lineptr[], int nlines) {
    for (int i = 0; i < nlines; i++) {
        free(lineptr[i]);
    }
}

// s1和s2对应的字符串转为数值进行比较
int numcmp(char *s1, char *s2);
// s1和s2进行比较,将忽略大小写和directory都考虑进来
int charcmp(char *s1, char *s2);

int main(int argc, char *argv[]) {

    for (int i = 1; i < argc; i++) {
        if (*argv[i]++ == '-') {
            int c = *argv[i];
            if (!c) {
                // 第i个参数是 - 这种非法字符
                printf("按照类似 sort [-nrfd] 的格式输入\n");
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
                case 'd': {
                    dflag = 1;
                    break;
                }
                default: {
                    printf("按照类似 sort [-nrfd] 的格式输入\n");
                    return -1;
                }
                }
                c = *++argv[i];
            }
        } else {
            printf("按照类似 sort [-nrfd] 的格式输入\n");
            return -1;
        }
    }

    if (nflag && dflag) {
        printf("-n 和 -d选项不兼容\n");
        return -1;
    }

    int (*comp)(void *, void *);
    // nflag
    if (nflag == 1) {
        comp = (int (*)(void *, void *))numcmp;
    } else {
        comp = (int (*)(void *, void *))charcmp;
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

// s1和s2进行比较,将忽略大小写和directory都考虑进来
int charcmp(char *s1, char *s2) {
    int c1, c2;
    while (1) {
        c1 = *s1;
        c2 = *s2;
        if (dflag) {
            // c1不是'\0'并且不是字母数字(isalnum)和空格
            while (c1 && !isalnum(c1) && c1 != ' ') {
                s1++;
                c1 = *s1;
            }
            while (c2 && !isalnum(c2) && c2 != ' ') {
                s2++;
                c2 = *s2;
            }
        }
        if (fflag) {
            c1 = tolower(c1);
            c2 = tolower(c2);
        }

        if (c1 != c2) {
            return c1 - c2;
        } else if (!c1) { // c1=='\0'
            return 0;
        }
        // 相等,且均不为'\0'
        s1++;
        s2++;
    }
}
