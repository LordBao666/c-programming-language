#include<stdio.h>
#define NONBLANK 'a'

/**
 * Exercise 1-9. Write a program to copy its input to its output, replacing each string of one or
 * more blanks by a single blank.
 *
**/

int main(){

    int ch;
    int preCh=NONBLANK;
    while((ch=getchar())!=EOF){
        if(ch!=' '){
            putchar(ch);
        }else{
            if(preCh!=' '){
               putchar(ch);
            }
        }
        preCh=ch;
    }

    return 0;
}

