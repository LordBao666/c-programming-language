#include "../getch.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// 统计关键词数目,下面只是列举了关键字的部分
// 已经按照字典序排序
struct key {
    char *word;
    int count;
} keytab[] = {
    "auto", 0,
    "break", 0,
    "case", 0,
    "char", 0,
    "const", 0,
    "continue", 0,
    "default", 0,
    "int", 0,
    /* ... */
    "return", 0, 
    "unsigned", 0,
    "void", 0,
    "volatile", 0,
    "while", 0};

#define MAXWORD 100 // 一个单词的最大长度

#define NKEYS (sizeof keytab / sizeof(struct key))

/* binsearch: find word in tab[0]...tab[n-1] */
int binsearch(char *word, struct key tab[], int n);

/**
 * 跳过空白符,再从标准输入中获取一个单词,并存储到word中
 *  这个单词可以是
 *      1.普通单词，以字母开头的字母/数字串，比如hello,h123,
 *      2.普通字符,比如 + 1
 *  返回普通单词的首字符,比如hello返回h, 如果是普通字符,则返回它本身
 *
 *  特别地,如果文件碰到EOF,则返回EOF.
 *
 *  word长度不能超过lim,超过的部分将忽略不计
 *  比如lim=2,而word是hello, 那么只保留he,而llo仍保留在标准输入中
 *
 *  lim至少为1,否则没有意义
 */
int getword(char *word, int lim);

/* count C keywords */
int main() {
    char word[MAXWORD + 1]; // 额外留一个位置放'\0'
    while ((getword(word, MAXWORD)) >= 0) {
        int index = binsearch(word, keytab, NKEYS);
        if (index >= 0) {
            keytab[index].count++;
        }
    }
    for (int i = 0; i < NKEYS; i++) {
        if (keytab[i].count > 0) {
            printf("%s : %d\n", keytab[i].word, keytab[i].count);
        }
    }
    return 0;
}

int binsearch(char *word, struct key tab[], int n) {
    int lo = 0, hi = n - 1;
    int mi;
    while (lo <= hi) {
        mi = lo + ((hi - lo) >> 1);
        int com = strcmp(word, tab[mi].word);
        if (com == 0) {
            return mi;
        } else if (com < 0) {
            hi = mi - 1;
        } else {
            lo = mi + 1;
        }
    }
    return -1;
}

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
