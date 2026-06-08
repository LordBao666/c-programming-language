#include <stdio.h>

#define BUF_CAPACITY 100  // 缓冲区大小
int buffer[BUF_CAPACITY]; // 缓冲区,存储来自标准输入的内容
int front = 0;            // 缓冲区队首
int rear = 0;             // 缓冲区队尾
// 可以牺牲一个空间,用于区分满或空
// 比如front==rear表示空,但(front-rear+BUF_CAPACITY)%BUF_CAPACITY==1表示满
// 但这里我设置一个bufferSize来表示是否为满,逻辑更简单
int bufferSize = 0;

int isBufferEmpty(void);
int isBufferFull(void);
int getch(void);
void ungetch(int c);
void traverseBuffer(void);

int isBufferEmpty(void) {
    return bufferSize == 0;
}
int isBufferFull(void) {
    return bufferSize == BUF_CAPACITY;
}

int getch(void) {
    if (isBufferEmpty()) {
        return getchar();
    } else {
        int ch = buffer[front];
        front = (front + 1) % BUF_CAPACITY;
        bufferSize--;
        return ch;
    }
}

void ungetch(int c) {
    if (isBufferFull()) {
        printf("缓冲区已满\n");
    } else {
        buffer[rear] = c;
        rear = (rear + 1) % BUF_CAPACITY;
        bufferSize++;
    }
}

void traverseBuffer(void) {
    if (isBufferEmpty()) {
        printf("缓冲区已空\n");
    }
    int head = front;
    int cnt = 0;
    printf("buffer:");
    while (cnt < bufferSize) {
        printf("%c ", buffer[head]);
        head = (head + 1) % BUF_CAPACITY;
        cnt++;
    }
    printf("\n");
}

// 测试代码,请将BUF_CAPACITY 设置为3
//  int main() {
//      ungetch('h');
//      ungetch('e');
//      ungetch('l');
//      traverseBuffer();//buffer:hel
//      ungetch('l');//已满
//      traverseBuffer();//buffer:hel
//      getch();
//      traverseBuffer();//buffer:el
//      getch();
//      getch();

//     int c = getch();//这个getch必须从控制台输入
//     printf("%c\n",c);
//     return 0;
// }