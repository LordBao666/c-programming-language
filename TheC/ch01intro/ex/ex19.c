#include<stdio.h>
#define MAXLINE 1000               /* maximum input line length     */

int getline_(char line [],int lim);
void reverse(char s[]);
/**
 * Exercise 1-19. Write a function reverse(s) that reverses the character string s. Use it to
 * write a program that reverses its input a line at a time.
 *
 *
**/
int main(){
    int len=0;                     /* The current line's length     */
    char line[MAXLINE];            /* The current line              */

    while(getline_(line,MAXLINE)>0){
         reverse(line);
         printf("%s",line);
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

/* reverse a string*/
void reverse(char s[]){
    int i=0;
    while(s[i]!='\0'){
        i++;
    }
    i--;
    if(s[i]=='\n'){
        i--;
    }
    int j=0;
    while(j<i){
        char t = s[j];
        s[j]=s[i];
        s[i]=t;
        j++;
        i--;
    }
}

