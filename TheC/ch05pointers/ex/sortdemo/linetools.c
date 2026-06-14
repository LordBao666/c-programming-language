#include "linetools.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS_PER_LINE 1001 // 每行最多的字符为1001-1=1000,最后一个字符放'\0'
#define MAX_LINES 5000          // 最多5000行
#define ARGUMENT_ERROR -2       // 表示参数错误
#define MEMORY_NOT_ENOUGH -1    // 内存不足
#define INPUT_TOO_MUCH -1       // 输入太多
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

// 清理lineptr的前n行
static void freeLines(char *lineptr[], int nlines) {
    for (int i = 0; i < nlines; i++) {
        free(lineptr[i]);
    }
}

int readlines(char *lineptr[], int maxlines) {
    int cnt = 0;   // 统计行数
    int words = 0; // 每行读取字符个数
    char line[MAX_WORDS_PER_LINE];
    while (cnt < maxlines && (words = getline(line, MAX_WORDS_PER_LINE)) > 0) {
        if (line[words - 1] == '\n') { // 替换末尾可能存在的换行符
            line[words - 1] = '\0';
            words--;
        }

        lineptr[cnt] = (char *)malloc(sizeof(char) * (words + 1)); //+1是考虑'\0'
        // 分配内存失败
        if (lineptr[cnt] == NULL) {
            // 将之前申请的空间一并回收
            freeLines(lineptr, cnt);
            return MEMORY_NOT_ENOUGH;
        }

        // 将line内容复制到lineptr[cnt]
        strcpy(lineptr[cnt], line);
        cnt++;
    }

    // 这说明已经读取到maxlines,文本内容过多
    if (cnt == maxlines) {
        freeLines(lineptr, cnt);
        return INPUT_TOO_MUCH;
    }

    // 返回实际读取行数
    return cnt;
}

void writelines(char *lineptr[], int nlines) {
    for (int i = 0; i < nlines; i++) {
        printf("%s\n", lineptr[i]);
    }
}

void writelinesReverse(char *lineptr[], int nlines, int len) {
    for (int i = len - 1; i >= len - nlines; i--) {
        printf("%s\n", lineptr[i]);
    }
}
// int main() {
//     /*测试getline */
//     // char line[MAX_WORDS_PER_LINE];
//     // int cnt;
//     // while ((cnt = getline(line, MAX_WORDS_PER_LINE)) > 0) {
//     //     printf("%d\t:%s", cnt, line);
//     // }

//     /*测试readlines 和 writelines*/
//     // char *lines[MAX_LINES];
//     // int lineCnt = readlines(lines, MAX_LINES);
//     // if (lineCnt >= 0) {
//     //     writelines(lines, lineCnt);
//     //     freeLines(lines, lineCnt);
//     // }

//     /*测试writelinesReverse*/
//     // char *lines[MAX_LINES];
//     // int lineCnt = readlines(lines, MAX_LINES);
//     // if (lineCnt >= 0) {
//     //     writelinesReverse(lines, lineCnt,lineCnt);
//     //     freeLines(lines, lineCnt);
//     // }
//     return 0;
// }