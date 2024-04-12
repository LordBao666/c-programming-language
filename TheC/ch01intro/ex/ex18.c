#include<stdio.h>
#define MAXLINE 1000               /* maximum input line length     */

int getline_(char line [],int lim);
int removeLine(char line[],int len);
/**
 * Ex1-18 Write a program to remove trailing blanks and tabs from each line of input,
 * and to delete entirely blank lines.
 *
 * Thought:We can scan each line from the end of it.
 * In general,When we encounter a non-blank charater, just insert  '\0' after it.
 * However,much attention has to be paid to the LAST CHARACTER(just name it lastCh) of each line.
 * case 1:If lastCh is '\n',we should keep it and scan the second character to last.
 * case 2:If lastCh is not '\n', just scan from the last one.This case happens at the end of a file.
 * For more details,please refer to function————int removeLine(char line[],int len);
**/
int main(){
    int len=0;                     /* The current line's length     */
    char line[MAXLINE];            /* The current line              */

    while((len=getline_(line,MAXLINE))>0){
        if(removeLine(line,len)>0){
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

/**
 * removeLine:     remove trailing blanks and tabs from a line whose length is len,and return new line's length
**/
int removeLine(char line[],int len){
    int i;
    int lastCh=line[len-1]; /* The current line's last character */
    if(lastCh=='\n'){
        i=len-2;
    }else{
        i=len-1;
    }
    for(;i>=0;i--){
        if(line[i]!='\t' && line[i]!=' '){
           break;
        }
    }

    if(i>=0){     /*this line is not an entirely balnk line*/
        if(lastCh=='\n'){
            line[++i]='\n';
        }
        line[++i]='\0';
        return i;
    }else{       /*this is an entirely balnk line*/
        return 0;
    }
}


