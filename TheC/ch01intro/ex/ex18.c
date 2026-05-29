#include <stdio.h>
#define MAXLINE 1000 /* 输入字符串的最大长度 */
int myGetline(char line[], int maxline);


int main() {
    char line[MAXLINE];
    int len;
    int maxLen = 0;
    while ((len = myGetline(line, MAXLINE)) > 0) {
        if (len > 1) {
            printf("%s", line);
        }
        // len=1,表示只有换行符,根据题目,应该丢弃
    }

    return 0;
}

/* 从标准输入读取一行,将行尾的'\t',' '去除之后，存储到字符数组中。
假定该行长度不超过lim-1,返回实际读取长度.
注意,长度是包括换行符的(如果有的话).
假设长度为len, 总是设置 s[len]='\0'
*/
int myGetline(char s[], int lim) {
    int c;
    int lastNonBlank = -1; // 记录最新的非'\t' ' ' 和 '\n'的出现位置
    for (int i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        s[i] = c;
        if (c != '\t' && c != ' ') {
            lastNonBlank = i;
        }
    }
    if (c == '\n') {
        s[++lastNonBlank] = '\n';
    }
    s[++lastNonBlank] = '\0';
    return lastNonBlank;
}
