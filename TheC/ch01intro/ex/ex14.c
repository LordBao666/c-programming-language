#include <stdio.h>
#include <ctype.h>

#define MAXHIST 15            /* max length of histogram    */
#define MAXCHAR 128           /* max different characters   */

/**
 * Ex1-14: Write a program to print a histogram of the frequencies of different characters
 * in its input.
 * Here different characters mean the first 128 characters of an ASCII table.
**/

int main(){
    int c,i;
    int len;
    int maxvalue;    /*maximum in cc*/
    int cc[MAXCHAR]; /* cc[i] means the ASCII i's freq,e.g cc[65]=11 means freq of  'A'(whose ASCII is 65) is 11*/

    for(i=0;i<MAXCHAR;i++){
         cc[i]=0;
    }

    while((c=getchar())!=EOF){
        if(c<MAXCHAR){
            ++cc[c];
        }
    }

    maxvalue=0;
    for(i=0;i<MAXCHAR;i++){
        if(maxvalue<cc[i]){
            maxvalue=cc[i];
        }
    }

    for(i=0;i<MAXCHAR;i++){
        if(isprint(i)){/*isprint is a function in ctype.h which checks whether a character can be printed.*/
            printf("%5d  - %c - %5d : ",i,i,cc[i]);
        }else{
            printf("%5d  -   - %5d : ",i,cc[i]);
        }
        if(cc[i]>0){
            if((len = cc[i] * MAXHIST / maxvalue)<=0){
                len=1;
            }
        }else{
            len=0;
        }
        while(len>0){
            printf("*");
            len--;
        }
        printf("\n");
    }
    return 0;
}

