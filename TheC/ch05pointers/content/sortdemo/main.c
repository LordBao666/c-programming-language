#include "linetools.h"
#include "qsort.h"
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

int main() {
    int lines;
    // 注意readlines是通过malloc分配内存。main函数在成功读取行之后，一定要回收。
    if ((lines = readlines(lineptr, MAXLINES)) >= 0) {
        myQsort(lineptr, 0, lines - 1);
        writelines(lineptr, lines);
        freeLines(lineptr,lines);
        return 0;
    } else {
        printf("内存不足或输入文本太多\n");
        return -1;
    }
}