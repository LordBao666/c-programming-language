#include "../getline.h"
#include <stdio.h>
#include <string.h>

// 模拟find函数的运行方式, -x 是反向匹配, -n显示行号
// find -x -n pattern
// find -n -x pattern
// find -nx pattern

#define MAX_WORDS_PER_LINE 1001 // 每行最多的字符为1001-1=1000,最后一个字符放'\0'

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("请按照 find -n -x pattern的格式输入\n");
        return -1;
    }

    int except = 0;     // 是否打印不匹配pattern的字符串, 默认否，即打印匹配pattern的字符串
    int linenumber = 0; // 是否打印行号,默认否
    int c;

    // 指向当前参数的下标,比如 find -n -x hello,这里相当于指向 -n
    int curArgIndex = 1;
    char *curArg;
    while (curArgIndex < argc - 1) {
        curArg = argv[curArgIndex];
        if (*curArg != '-') {
            printf("请按照 find -n -x pattern的格式输入\n");
            return -1;
        }
        while (c = *++curArg) { // 探索curArg从第1个字符串开始的整个字符串,比如 -nx，这里直接是指向n
            switch (c) {
            case 'n': {
                linenumber = 1;
                break;
            }
            case 'x': {
                except = 1;
                break;
            }
            default: {
                printf("请按照 find -n -x pattern的格式输入\n");
                return -1;
            }
            }
        }
        curArgIndex++;
    }

    char *subStr = argv[argc - 1];
    int curLineNo = 0; // 当前行号
    char line[MAX_WORDS_PER_LINE];
    while (getline(line, MAX_WORDS_PER_LINE) > 0) {
        curLineNo++;
        // 只有2种情况打印, 字符串匹配&&except=0, 或 字符串不匹配&&except=1
        int match = strstr(line, subStr) != NULL; // 匹配是1,不匹配是0
        if (match != except) {                    // match和except不等时才会打印
            if (linenumber) {
                printf("%d: %s", curLineNo, line);
            } else {
                printf("%s", line);
            }
        }
    }
    return 0;
}