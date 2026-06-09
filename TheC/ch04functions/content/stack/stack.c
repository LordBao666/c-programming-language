#include "stack.h"
#include <stdio.h>

// #define STACK_CAPACITY 100 //stack.h已经写了这行代码
int sp = 0;
int stack[STACK_CAPACITY];

// 注意isEmpty作为本地函数,建议用static修饰，isFull是类似的
static int isEmpty() {
    return sp == 0;
}
static int isFull() {
    return sp == STACK_CAPACITY;
}

void stackPush(int val) {
    if (isFull()) {
        printf("栈已经满\n");
        return;
    }
    stack[sp++] = val;
}

int stackPop(void) {
    if (isEmpty()) {
        printf("栈已经空\n");
        return -1;
    }
    return stack[--sp];
}
