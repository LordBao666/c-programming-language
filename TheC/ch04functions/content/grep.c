#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE 1001 // 一行最多1000字符,字符串的下一个位置以'\0'结束

/**本实验模拟linux的grep函数:从输入文本中找到并打印含目标串的行
 * e.g 目标串是ould,输入文本为
 * Ah Love! could you and I with Fate conspire
 * To grasp this sorry Scheme of Things entire,
 * Would not we shatter it to bits -- and then
 * Re-mould it nearer to the Heart's Desire!
 *
 * 则函数将打印第1,3,4行
 */

/**
 * 返回值表示本次调用存入 line 数组的字符数（不包括结尾的 '\0'），取值范围为 0 到 max-1。
 * 若输入行超过 max-1 个字* 符，多余的字符将在后续调用中被逐步读取；
 * 调用者无法通过单次返回值获知输入行的真实总长度。
 *
 * max 必须 >=1.
 * line 数组可能溢出,调用者应该了解此情况.
 *
 *
 * e.g1 假设max充分大,标准输入为如下两行时(最后一行是换行符)
 * hello world!
 * how are you?
 * getline读取第一行为"hello world!\n",大小为13,第二行为"how are you?",大小为12
 * 也就是说如果存在换行符,会将换行符也读取进来.
 * getline再调用时,由于标准输入结束,返回0.
 *
 * 在实际操作中，会在每个字符数组后面都加终结符'\0'
 *
 *
 * e.g2假设max充分大,标准输入为如下三行时
 * hello world!
 * how are you?
 *
 * getline读取第一行为"hello world!\n",大小为13,第二行为"how are you?\n",大小为13
 * getline读取的第三行什么也没有,为"",长度为0, 其实这里就是标准输入结束.
 *
 * 在实际操作中，会在每个字符数组后面都加终结符'\0'
 *
 *
 * e.g3 假设max=4,标准输入为一行时
 * hello world!
 * getline依次得到的是 "hel","lo ","wor","ld!", max=4表示读取的字符串最长为3
 * 最后一个位置放终止符'\0'
 */
int getline(char line[], int max);

/**
 * 假定source 和 searchfor均为字符串
 * 返回searchfor在source中首次出现的位置.如果不是子串,返回-1
 *
 */
int strIndex(char source[], int sourceLen, char searchfor[], int searchLen);

/**
 * 假定str为字符串,返回该字符串的长度
 */
int strLen(char str[]);

/**
 * 假定str为长度至少为1的字符串,返回该字符串的next数组
 * len表示str长度
 */
int *generateNext(char str[], int len);

int main() {
    // 1.先输入目标串,长度不要超过MAX_LINE-1
    char searchFor[MAX_LINE];
    getline(searchFor, MAX_LINE);
    int searchLen = strLen(searchFor);
    // 清理掉可能存在的换行符
    if (searchLen > 0 && searchFor[searchLen - 1] == '\n') {
        searchFor[searchLen - 1] = '\0';
        searchLen--;
    }

    // 2.再输入目标文本
    char source[MAX_LINE];
    while ((getline(source, MAX_LINE)) > 0) {
        if (strIndex(source, strLen(source), searchFor, searchLen) >= 0) {
            printf("%s", source);
        }
    }
    return 0;
}

int getline(char line[], int max) {
    if (max <= 0) {
        printf("max 不能小于等于0");
        return -1;
    }
    char c = '\0'; // 初始化为任何除了'\n'的值都行
    int cnt = 0;   // 记录读取多少字符
    while (cnt < max - 1 && (c = getchar()) != EOF && c != '\n') {
        line[cnt++] = c;
    }
    if (c == '\n') {
        line[cnt++] = c;
    }
    line[cnt] = '\0';
    return cnt;
}

int strIndex(char source[], int sourceLen, char searchfor[], int searchLen) {
    if (searchLen == 0) {
        return 0;
    }
    if (searchLen > sourceLen) {
        return -1;
    }

    // 现在1<=searchLen<=sourceLen
    int *next = generateNext(searchfor, searchLen);
    int i = 0, j = 0;
    while (i < sourceLen && j < searchLen) {
        if (source[i] == searchfor[j]) {
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