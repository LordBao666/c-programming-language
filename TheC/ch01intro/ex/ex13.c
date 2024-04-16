#include <stdio.h>

#define MAXHIST 15 /*max length of histogram   */
#define MAXWORD 11 /*max length of a    word   */

/**
 * Exerciese 1-13 Write a program to print a histogram of the lengths of words in its input. It is
 * easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.
 **/
int main()
{
    int prev = ' ';             /*previous character    */
    int curr;                   /*current character     */
    int len = 0;                /*current word's length */
    int overflow=0;             /*the number of words whose length >MAXWORD*/
    int wordCounter[MAXWORD];   /*wordCounter[i] means number of length i-1*/
    int maxValue=0;             /*the maximum in wordCounter*/
    for(int i=0;i<MAXWORD;i++){
        wordCounter[i]=0;
    }

    while ((curr = getchar()) != EOF){
        if (curr == ' ' || curr == '\t' || curr == '\n'){
            if (prev != ' ' || prev != '\t' || prev != '\n'){ /* finish a word */
                if(len>MAXWORD){ /*overflow*/
                    overflow++;
                }else{
                    wordCounter[len - 1]++;
                }
                len = 0;
            }
        }
        else{
            len++;
        }
    }

    if (prev != ' ' || prev != '\t' || prev != '\n'){/*Now curr is EOF,and we still have to deal with prev*/
        if(len>MAXWORD){ /*overflow*/
            overflow++;
        }else{
            wordCounter[len - 1]++;
        }
    }

    for(int i=0;i<MAXWORD;i++){
        if(maxValue < wordCounter[i]){
            maxValue = wordCounter[i];
        }
    }

    for(int i=0;i<MAXWORD;i++){

       printf("%5d  %5d  ",i+1,wordCounter[i]);
       /*Due to integer truncation, it CANNOT be wordCounter[i] * maxvalue / MAXHIST
        *which always get either 0 or maxValue. The math expression just for nice looking.
        */
       int temp = wordCounter[i] * MAXHIST / maxValue;
       if(temp==0 && wordCounter[i]>0){
          temp=1;
       }
       for(int i=0;i<temp;i++){
          printf("*");
       }
       printf("\n");
    }
    if(overflow>0){
        printf("the overflow word's number is %d\n",overflow);
    }
    return 0;
}

