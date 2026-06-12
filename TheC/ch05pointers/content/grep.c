#include "../getline.h"
#include <stdio.h>
#include <string.h>
#define MAX_WORDS_PER_LINE 1001 // 每行最多的字符为1001-1=1000,最后一个字符放'\0'

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("请输入程序要搜索的字符串.如果含空格,请用双引号\n");
        return -1;
    }
    char line[MAX_WORDS_PER_LINE];
    char *substr = argv[1]; // 要查询的目标字符串
    while (getline(line, MAX_WORDS_PER_LINE) > 0) {
        if (strstr(line, substr)) {
            printf("%s", line);
        }
    }

    return 0;
}