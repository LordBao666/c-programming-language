#include "stack.h"
#include <stdio.h>

#define MAX_LEN 100 // 栈最大深度

// 不对外暴露stack 和 sp
static double stack[MAX_LEN];
static int sp = 0; // 栈顶指针,指向下一个要插入的位置
double popStack(void) {
    if (isStackEmpty()) {
        printf("栈已空,pop为非法操作!\n");
        return 0.0;
    } else {
        return stack[--sp];
    }
}

void pushStack(double val) {
    if (isStackFull()) {
        printf("栈已满,push为非法操作!\n");
    } else {
        stack[sp++] = val;
    }
}
int isStackEmpty(void) { // 1表示空,0表示非空
    return 0 == sp ? 1 : 0;
}
int isStackFull(void) { // 1表示满,0表示非满
    return MAX_LEN == sp ? 1 : 0;
}
int stackSize(void) {
    return sp;
}

// 测试代码,打印栈
static void traverseStack() {
    if (isStackEmpty()) {
        printf("栈空\n");
        return;
    }

    int p = sp;
    printf("stack:\n");
    while (p > 0) {
        --p;
        printf("%d:%.8g\n", p, stack[p]);
    }
}

// stack.c 测试代码,单独编译此文件
// int main() {
//     // 手动将MAX_LEN 调制为2,以检验满的操作
//     pushStack(1.1);
//     pushStack(2.2);
//     traverseStack(); // 栈底开始为1.1,2.2
//     pushStack(3.3);       // 此处已满,应该为非法操作
//     traverseStack(); // 栈底开始为1.1,2.2
//     popStack();
//     popStack();
//     popStack();           // 此处已空,应该为非法操作
//     traverseStack(); // 空
// }