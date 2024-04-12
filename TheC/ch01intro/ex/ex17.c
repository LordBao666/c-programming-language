#include<stdio.h>
#define MAXLINE 1000               /* maximum input line length     */
#define LINELIMIT 80               /* The line to be printed must be longer than LINELIMIT */
int getline_(char line [],int lim);

/**
 * Ex1-17 Write a program to print all input lines that are longer than 80 characters.
**/
int main(){
    int value=0;                   /* The current line's length     */
    char line[MAXLINE];            /* The current line              */

    while((value=getline_(line,MAXLINE))>0){
        if(value>LINELIMIT){
            printf("%s",line);
        }
    }

    return 0;
}

/**
 * getline_:     read a line into s,return length
 * Note that this funcion CANNOT be named getline,for it will have conflicts with the original function.
 *
**/
int getline_(char line [],int lim){
    int ch;
    int i=0;
    while(i <lim-1 && (ch=getchar())!=EOF &&  ch!='\n'){
        line[i]=ch;
        i++;
    }
    if(ch=='\n'){    /*According to the book,a newline character should also count as length 1.*/
        line[i]=ch;
        i++;
    }
    line[i]='\0';    /* i is lim -1 at most,so the array won't be overflow.*/
                     /* When while stops,there are two cases: 1. i=lim-1 and ch!='\n',2. i<lim-1 and ch=='\n'. */
                     /* Both cases are safe.*/
    return i;
}


