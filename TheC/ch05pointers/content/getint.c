#include "../getch.h"
#include <ctype.h>
#include <stdio.h>
#define NUM 0

/**从标准输入读取数据，跳过连续的white spaces。
1. 如果是EOF，则返回EOF
2. 如果没EOF
  1. 如果是整数，则将结果保存到pn中，并返回0。
  2. 如果不是整数，则返回一个正整数，这个正整数是读取到的那个字符。比如标准输入正好是`a`，那么就返回a。
对于不是整数的情况,要将读到的字符放到缓冲区去
*/
int getint(int *pn) {
    int c;
    while (isspace(c = getch()))
        ;
    if (c == EOF) {
        return EOF;
    }

    // c并非数字,或+-
    if (!isdigit(c) && c != '+' && c != '-') {
        ungetch(c);
        return c;
    }

    int sign = 1;
    if (c == '+' || c == '-') {
        int next = getch();
        if (!isdigit(next)) { // 这表明是 +? 这种并不是表示数字的非法情况
            // 重新放回缓冲区,注意缓冲区是队列,先放c,再放next
            ungetch(c);
            if(c!=EOF){
                ungetch(next);
            }
            return c;
        } else {
            if (c == '-') {
                sign = -1;
            }
            c = next;
        }
    }

    *pn = c - '0';
    // 如果最开始的c 是 数字,那么根本不会进入if(c=='+' || c=='-')
    // 如果最开始的c 是 表示数字+ 或 -号,此时c指向的符号后面的第一个数字
    while (isdigit(c = getch())) {
        *pn = *pn * 10;
        *pn = *pn + c - '0';
    }
    *pn = *pn * sign;

    if (c != EOF) {
        ungetch(c);
    }
    return NUM; // NUM定义为0,即数字
}

int main() {
    // 假设标准输入是 +12 -2 -3 -? +? 2
    // 下面代码会打印12 -2,-3 和 2
    int type, x;
    while ((type = getint(&x)) != EOF) {
        if (type == NUM) {
            printf("%d ", x);
        } else {
            getch(); // 跳过这个字符
        }
    }
    return 0;
}