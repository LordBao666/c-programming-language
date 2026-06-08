#include <stdio.h>
#include <stdlib.h> /* for atof() */
#define MAXOP 100   /* 操作符或操作数的最大长度,但主要针对操作数而言,不能超过这个长度 */
#define NUMBER '0'  /* 表明是数字 */

// 本节的实验数据课查看cal.txt,答案均为100

// 下面均为声明的外部函数,不在本c文件实现

/**
 * 从代表逆波兰表达式的标准输入读取一个操作数 或是 操作符
 *
 *返回具体的类型,比如'0'代表是数字, '+','-','*','/'等代表是运算符
 */
int getop(char[]);

void push(double);
double pop(void);

/* 逆波兰表达式计算器*/
int main() {
    int type;
    double op2;
    char s[MAXOP];
    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}