#include <stdio.h>

// 下面三个函数定义在<string.h>,编译时会提醒问题.我稍微改下名字
/**  copy at most n characters of string ct to s; return s. Pad with '\0''s
 *   if ct has fewer than n characters.
 *
 * 注意
 * C 标准规定：strncpy(s, ct, n) 最多复制 n 个字符
      如果 ct 的长度 小于 n，剩余位置用 '\0' 填充
      如果 ct 的长度 大于等于 n，则不保证以 '\0' 结尾
      所以调用者必须自己保证 s 有足够空间，并在需要时手动加 '\0'
 */
char *myStrncpy(char *s, char *ct, int n);

/**
 * concatenate at most n characters of string ct to string s, terminate s
 * with '\0'; return s.
 */
char *myStrncat(char *s, char *ct, int n);

/**
 *compare at most n characters of string cs to string ct; return <0 if
 *cs<ct, 0 if cs==ct, or >0 if cs>ct
 */
int myStrncmp(char *cs, char *ct, int n);

char *myStrncpy(char *s, char *ct, int n) {
    char *ans = s;
    int cnt = 0;
    while (cnt < n && *ct) { //*ct 等价于 *ct!='\0', 0就是'\0'
        *s++ = *ct++;
        cnt++;
    }
    while (cnt < n) {
        *s++ = '\0';
        cnt++;
    }
    return ans;
}

char *myStrncat(char *s, char *ct, int n) {
    char *ans = s;
    int cnt = 0;
    while (*s) { // s移动到s表示的字符串末尾'\0'位置
        s++;
    }
    while (cnt < n && *ct) { //*ct 等价于 *ct!='\0', 0就是'\0'
        *s++ = *ct++;
        cnt++;
    }
    *s = '\0';
    return ans;
}

int myStrncmp(char *cs, char *ct, int n) {
    int cnt = 0;
    while (cnt < n && *cs && *ct) {
        if (*cs != *ct) {
            return *cs - *ct;
        }
        cs++;
        ct++;
        cnt++;
    }
    // cnt==n时表示n个字符都比较完毕
    // 否则cs 和 ct其中一个字符串提前结束
    return cnt == n ? 0 : *cs - *ct;
}

#define MAX_SIZE 100
int main(void) {

    // 在实际测试的时候,保证cs为char数组,且足够大
    // 避免溢出
    char cs1[MAX_SIZE];
    int bigSize = 50;
    int smallSize = 4;
    printf("%s\n", myStrncpy(cs1, "how are you?", bigSize)); // 打印"how are you?"
    myStrncpy(cs1, "i'm fine ?", smallSize);
    printf("%s\n", cs1); // 打印"i'm are you?"
    // 这里特别注意strncpy的行为,如果没有下面这行代码,cs1为 i'm are you?
    cs1[smallSize] = '\0';
    printf("%s\n", cs1); // 打印"i'm "

    char cs2[MAX_SIZE] = "hello";
    printf("%s\n", myStrncat(cs2, ",how", bigSize));           // 打印"hello,how"
    printf("%s\n", myStrncat(cs2, " are you ok?", smallSize)); // 打印"hello,how are"

    printf("%d\n", myStrncmp("he", "hellq", 3));     //"he"提前结束,此处返回 '\0'-'l'=-108
    printf("%d\n", myStrncmp("hellq", "he", 3));     //"he"提前结束,此处返回 'l'-'\0'=108
    printf("%d\n", myStrncmp("hello", "hellq", 4));  // 0
    printf("%d\n", myStrncmp("hello", "hellq", 5));  // o<q,此处打印负数,值为 'o'-'q'=-2
    printf("%d\n", myStrncmp("hello", "hellm", 5));  // o>m,此处打印正数,值为 'o'-'m'=2
    printf("%d\n", myStrncmp("hello", "hellq", 10)); //-2
    printf("%d\n", myStrncmp("hello", "hellm", 10)); // 2

    return 0;
}