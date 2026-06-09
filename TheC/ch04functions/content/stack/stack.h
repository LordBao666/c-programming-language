#ifndef STACK_H
#define STACK_H

// 暴露所有变量和函数的stack.h 写法
#define STACK_CAPACITY 100
extern int sp;
extern int stack[STACK_CAPACITY];
void stackPush(int val);
int stackPop(void);

#endif