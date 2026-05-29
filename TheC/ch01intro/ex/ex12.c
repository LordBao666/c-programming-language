#include <stdio.h>

/**
 * Ex1-12: Write a program that prints its input one word per line.
 * e.g
 * 假设输入为
 *    hi   i'm jack
 *    how are you?
 * 输出为
 *    hi
 *    i'm
 *    jack
 *    how
 *    are
 *    you?
 **/
#define IN 1  // 表示上一次是有效字符(字母数字,下划线)
#define OUT 0 // 表示上一次是空白符

int main() {
    int state = OUT;
    int curChar;
    while ((curChar = getchar()) != EOF) {
        if (curChar == '\n' || curChar == '\t' || curChar == ' ') {
            // 上一次是有效字符
            if (state == IN) {
                putchar('\n'); // 换行
                state = OUT;
            }
            // else 上一次是空白符,什么都不做
        } else {
            state = IN;
            putchar(curChar);
        }
    }

    return 0;
}

