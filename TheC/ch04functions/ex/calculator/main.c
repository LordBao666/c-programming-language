#include <stdio.h>
#include <stdlib.h> //借用atof函数
// 操作数或操作符的最大长度.但确切来说指的是操作数,因为操作数一般都长些
#define MAX_LEN 100
#define NUMBER '0' // 表示类型是数字

/*测试案例中的数据答案均为100*/

// 下面函数是外部函数

// 来自getop.c
//   从标准输入读取操作数或操作符到op中,并返回具体类型
//   返回值'0'代表是操作数, 或是 +-*/等运算符, 或是EOF
//   或是非法值
int getop(char op[]);

// 来自stack.c
double popStack(void);
void pushStack(double val);
int isStackEmpty(void); // 1表示空,0表示非空

int main() {
    int type;         // getop返回类型
    char op[MAX_LEN]; // 读取操作数或操作符
    while (1) {
        type = getop(op);
        switch (type) {
        case NUMBER: {
            pushStack(atof(op));
            break;
        }
        case '+': {
            pushStack(popStack() + popStack());
            break;
        }
        case '*': {
            pushStack(popStack() * popStack());
            break;
        }
        case '-': {
            double op2 = popStack();
            pushStack(popStack() - op2);
            break;
        }
        case '/': {
            double op2 = popStack();
            if (op2 == 0.0) {
                printf("除数不能为0\n");
                printf("程序非法退出...\n");
                return -1;
            }
            pushStack(popStack() / op2);
            break;
        }
        case '%': { // ex4.3对取模的扩展
            int op2 = (int)popStack();
            if (op2 == 0) {
                printf("模不能为0\n");
                printf("程序非法退出...\n");
                return -1;
            }
            pushStack(((int)popStack()) % op2);
            break;
        }
        case '\n': {
            printf("\t%.8g\n", popStack());
            break;
        }
        case EOF: {
            if (!isStackEmpty()) {
                printf("\t%.8g\n", popStack());
            }
            printf("程序结束...\n");
            return 0;
        }
        default: {
            printf("非法输入...程序终止...");
            return -1;
        }
        }
    }
    return 0;
}