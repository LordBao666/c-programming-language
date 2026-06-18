#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINE 1001

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "按照 diff file1 file2格式来比对文件\n");
        exit(1);
    }

    FILE *file1 = fopen(argv[1], "r");
    if (!file1) {
        fprintf(stderr, "%s 不存在 或 权限不足\n", argv[1]);
        exit(2);
    }
    FILE *file2 = fopen(argv[2], "r");
    if (!file2) {
        fprintf(stderr, "%s 不存在 或 权限不足\n", argv[2]);
        exit(2);
    }

    char line1[MAXLINE];
    char line2[MAXLINE];
    int eof1 = 0; // 文件1是否读取完毕,0表示否,1表示是
    int eof2 = 0; // 文件2是否读取完毕,0表示否,1表示是
    int cnt = 1;  // 记录行数
    while (1) {
        eof1 = fgets(line1, MAXLINE, file1) == NULL;
        eof2 = fgets(line2, MAXLINE, file2) == NULL;
        // 文件1和文件2都未读取完毕
        if (!eof1 && !eof2) {
            int len1 = strlen(line1);
            if (len1 > 0 && line1[len1 - 1] == '\n') { // 去除掉末尾换行符
                line1[len1 - 1] = '\0';
            }
            int len2 = strlen(line2);
            if (len2 > 0 && line2[len2 - 1] == '\n') { // 去除掉末尾换行符
                line2[len2 - 1] = '\0';
            }

            if (strcmp(line1, line2) != 0) {
                printf("第%d行不同.\n%s 为 %s\n%s 为 %s\n", cnt, argv[1], line1, argv[2], line2);
                exit(0);
            }
        } else {
            if (eof1 == 1 && eof2 == 1) {
                printf("%s 和 %s完全相同\n", argv[1], argv[2]);
            } else if (eof1 == 1) {
                printf("%s 是 %s 内容的一部分\n", argv[1], argv[2]);
            } else {
                printf("%s 是 %s 内容的一部分\n", argv[2], argv[1]);
            }
            exit(0);
        }
        cnt++;
    }
}