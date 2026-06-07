#include <stdio.h>
#include <stdlib.h>

/**
 *
 *
 * 返回seach在source右侧首次出现位置.如果不是子串,返回-1
 * 假定search 和 source的长度至少为1.
 *
 * 这种题有两种思路,一种思路是是直接从右侧开始匹配,不过对于next的生成和字符串匹配时,
 * 要额外考虑逻辑。但是这种想起来要稍微麻烦一点。
 * 另外一种思路将ex01.c
 */
int strIndexLast(char source[], int sourceLen, char search[], int searchLen);
int *generateNext(char str[], int len);
int strLen(char str[]);
void reverseStr(char str[], int len) {
    int i = 0, j = len - 1;
    while (i < j) {
        char c = str[i];
        str[i] = str[j];
        str[j] = c;
        i++;
        j--;
    }
}

int main() {
    char source[] = "heheo";
    char target[] = "he";
    printf("%s-->%s:%d\n", source, target, strIndexLast(source, strLen(source), target, strLen(target)));
    return 0;
}

int strIndexLast(char source[], int sourceLen, char search[], int searchLen) {

    if (searchLen > sourceLen) {
        return -1;
    }

    // 现在1<=searchLen<=sourceLen
    int *next = generateNext(search, searchLen);
    int i = sourceLen - 1, j = searchLen - 1;
    while (i >= 0 && j >= 0) {
        if (source[i] == search[j]) {
            i--;
            j--;
        } else if (j < searchLen - 1) {
            j = searchLen - (next[j] + 1);
        } else {
            i--;
        }
    }
    free(next);
    return j == -1 ? i + 1 : -1;
}

int strLen(char str[]) {
    int cnt = 0;
    while (str[cnt] != '\0') {
        cnt++;
    }
    return cnt;
}

int *generateNext(char str[], int len) {
    int *next = (int *)malloc(sizeof(int) * len);
    next[len - 1] = -1;
    if (len == 1) {
        return next;
    }

    next[len - 2] = 0;
    int index = len - 1, i = len - 3;
    while (i >= 0) {
        if (str[i + 1] == str[index]) {
            next[i] = len - index;
            i--;
            index--;
        } else if (index < len - 1) {
            index = len - (next[index] + 1);
        } else {
            next[i--] = 0;
        }
    }

    return next;
}