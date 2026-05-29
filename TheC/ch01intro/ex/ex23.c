#include <stdio.h>

/**
 * Exercise 1-23. Write a program to remove all comments from a C program. Don't forget to
handle quoted strings and character constants properly. C comments don't nest.
*/

// 思路: 优先考虑 单字符  和 字符串，因为存在特殊情况'/' 或 "/*"
// 也就是说 出现单引号和双引号时,要优先处理

// 假设C程序是合法的!
// 执行本代码会去除掉注释，但是会留下较多空白行,建议和ex18去除末尾空白行的程序一起使用
// 比如./ex23.exe < demo.c | ./ex18.exe
int main() {
    int c;
    while ((c = getchar()) != EOF) {
        if (c == '\'') { // 单引号
            putchar(c);
            c = getchar();
            putchar(c);

            // 转移字符可能是 \n这种常规转义序列 或是
            //\101 这种8进制转义(不用管具体含义) 或是
            //\x41 活这16进制转义(不用管具体含义)
            // 唯一要处理的特殊情况是 单引号转义本身：\',
            // 直接putchar(getchar()), 将那个可能存在的单引号打印就行
            if (c == '\\') {
                putchar(getchar());
            }
            while ((c = getchar()) != '\'') {
                putchar(c);
            }
            putchar(c);
        } else if (c == '\"') { // 双引号
            putchar(c);
            // 双引号要考虑的特殊情况是 "hi  \s  \" "，也就是出现转移序列 \"
            while ((c = getchar()) != '\"') {
                putchar(c);
                if (c == '\\') { // 出现转义序列,直接把下一个直接也打印,以解决\"的特殊情况
                    putchar(getchar());
                }
            }
            putchar(c);
        } else if (c == '/') {
            // 由于C程序是合法的,这里当碰到/时,下一个可能是/ 或 * 以表示注释
            // 也可以是除法,这种情况直接打印/
            c = getchar();
            if (c == '/') {
                while ((c = getchar()) != EOF && c != '\n')
                    ;
                if (c == '\n') {
                    putchar('\n');
                }
            } else if (c == '*') {
                char p1 = getchar();
                char p2 = getchar();
                while (!(p1 == '*' && p2 == '/')) {
                    p1 = p2;
                    p2 = getchar();
                }
            } else { // 除法
                putchar('/');
                putchar(c);
            }
        } else { // 正常情况
            putchar(c);
        }
    }

    return 0;
}