#include "getch.h"
#include <stdio.h>

#define BUFFER_SIZE 100

/*
 * 属性均设置为static,不向外暴露
 */
static int front = 0;
static int rear = 0;
static int size = 0;
static int buffer[BUFFER_SIZE];

// 注意,本函数设置为static(私有)
// 避免连接阶段可能的冲突问题
// isFull()同样是static
static int isEmpty() {
    return size == 0;
}
static int isFull() {
    return size == BUFFER_SIZE;
}

int getch(void) {
    if (isEmpty()) {
        return getchar();
    }

    int ans = buffer[front];
    front = (front + 1) % BUFFER_SIZE;
    size--;
    return ans;
}
void ungetch(int c) {
    if (isFull()) {
        printf("缓冲已满\n");
        return;
    }

    buffer[rear] = c;
    rear = (rear + 1) % BUFFER_SIZE;
    size++;
}