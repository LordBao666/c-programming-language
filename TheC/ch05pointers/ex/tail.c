#include "../getline.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//本实验模拟 tail -n 打印文本的后n行,对应第5章的13题

#define DEFAULT_LINES 10         // 默认打印10行
#define MAX_LINE 1000           // 文本最多1000行,超过1000行,表明文本过大
#define MAX_WORDS_PER_LINE 1001 // 每行最多MAX_WORDS_PER_LINE-1个字符,超过则转入另一行
static char *text[MAX_LINE];    // 用于存储文本




// 将非空字符串s转为整型
// 注意,如果s不代表数字,或是s代表的数字为负数,或者大于MAX_LINE,都返回-1
static int myAtoi(char *s) {
    int sum = 0;
    int c;
    while (sum <= MAX_LINE && (c = *s)) {
        if (isdigit(c)) {
            sum = sum * 10 + (c - '0');
        } else {
            return -1;
        }
        s++;
    }
    return sum <= MAX_LINE ? sum : -1;
}

// 回收text的前n行
static void freeLines(int n) {
    for (int i = 0; i < n; i++) {
        free(text[i]);
    }
}

int main(int argc, char *argv[]) {

    if (argc > 2) {
        printf("请按tail -n 或 tail的方式查看文本.n不能超过%d\n", MAX_LINE);
        return -1;
    }
    int lastN = DEFAULT_LINES; // 默认查看后10行
    if (argc == 2) {
        if (*argv[1] == '-') {
            lastN = myAtoi(++argv[1]);
            if (lastN == -1) {
                printf("请按tail -n 或 tail的方式查看文本.n不能超过%d\n", MAX_LINE);
                return -1;
            }
        } else {
            printf("请按tail -n 或 tail的方式查看文本.n不能超过%d\n", MAX_LINE);
            return -1;
        }
    }


    char line[MAX_WORDS_PER_LINE];
    int lineNum = 0; // 记录实际读取的行数
    int size;        // 当前行的大小
    while (lineNum <= MAX_LINE && (size = getline(line, MAX_WORDS_PER_LINE)) > 0) {
        text[lineNum] = (char *)malloc(sizeof(char) * (size + 1)); // 注意这里是size+1,预留一个'\0'
        if (!text[lineNum]) {
            printf("内存不足...\n");
            return -1;
        }
        strcpy(text[lineNum], line);
        lineNum++;
    }

    if (lineNum <= MAX_LINE) {
        // 如果要求打印的行数超过实际行数,那么按实际行数打印
        if (lastN > lineNum) {
            lastN = lineNum;
        }
        for (int i = lineNum - lastN; i < lineNum; i++) {
            printf("%s", text[i]);
        }
    } else {
        printf("文本过大\n");
    }
    freeLines(lineNum);
    return 0;
}
