#include <stdio.h>
#include <stdlib.h>

/**
 *
 * Exercise 4-1. Write the function strindex(s,t) which returns the position of the rightmost occurrence * of t in s, or -1 if there is none.
 *
 * 返回seach在source右侧首次出现位置.如果不是子串,返回-1
 * 假定search 和 source的长度至少为1.
 *
 * 这种题有两种思路,一种思路是借助已有的找左侧子串的方式,另外一种思路将ex01B.c
 *  1 可以将source 和 search反转
 *  2 找到search反转子串在source反转子串的位置,根据此位置返回答案
 *
 *  e.g source=heheo,search=he
 *     反转source' = oeheh, search' = eh
 *     eh在oeheh首次出现的位置是1, 那么返回答案为sourceLen - (1 + searchLen) = 2
 */
int strIndexLast(char source[], int sourceLen, char search[], int searchLen);

/**返回seach在source左侧首次出现位置.如果不是子串,返回-1 */
int strIndex(char source[], int sourceLen, char search[], int searchLen);
int *generateNext(char str[], int len);
int strLen(char str[]);
void reverseStr(char str[], int len);

int main() {
    char source[] = "heheo";
    char target[] = "he";
    printf("%s-->%s:%d\n", source, target, strIndexLast(source, strLen(source), target, strLen(target)));
    return 0;
}

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

int strIndexLast(char source[], int sourceLen, char search[], int searchLen) {
    reverseStr(source, sourceLen);
    reverseStr(search, searchLen);
    int index = strIndex(source, sourceLen, search, searchLen);
    if (index != -1) {
        index = sourceLen - (index + searchLen);
    }
    // 恢复source 和 search
    reverseStr(source, sourceLen);
    reverseStr(search, searchLen);
    return index;
}

int strIndex(char source[], int sourceLen, char search[], int searchLen) {

    if (searchLen > sourceLen) {
        return -1;
    }

    // 现在1<=searchLen<=sourceLen
    int *next = generateNext(search, searchLen);
    int i = 0, j = 0;
    while (i < sourceLen && j < searchLen) {
        if (source[i] == search[j]) {
            i++;
            j++;
        } else if (j > 0) {
            j = next[j];
        } else {
            i++;
        }
    }
    free(next);
    return j == searchLen ? i - searchLen : -1;
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
    next[0] = -1;
    if (len == 1) {
        return next;
    }

    next[1] = 0;
    int index = 0, i = 2;
    while (i < len) {
        if (str[i - 1] == str[index]) {
            next[i++] = ++index;
        } else if (index > 0) {
            index = next[index];
        } else {
            next[i++] = 0;
        }
    }

    return next;
}