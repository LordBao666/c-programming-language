#ifndef GETCH_H
#define GETCH_H
/* get a (possibly pushed-back) character */
int getch(void);
/* push character back on input */
void ungetch(int c);
#endif