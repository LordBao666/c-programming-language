#include "stack.h"
#include <stdio.h>

// 由于stack暴露了int sp,int stack[],因此可以对它操作
void traverStack(void) {
    int i = 0;
    printf("stack [ ");
    while (i < sp) {
        printf("%d ", stack[i]);
        i++;
    }
    printf("]\n");
}

int main() {
  stackPush(1);
  stackPush(2);
  stackPush(3);
  traverStack();//stack [1 2 3];
  stackPop();
  stackPop();
  stackPop();
  traverStack(); // stack [];
  stackPop();//此处会提醒你栈空
  traverStack();// stack [];
}