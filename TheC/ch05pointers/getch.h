#ifndef GETCH_H
#define GETCH_H

// 优先从缓冲区获取一个字符,缓冲区为空,则
// 从标准输入获取字符
int getch(void);
// 将字符放到缓冲区
void ungetch(int c);

#endif