#include <stdio.h>

/**
 * Ex1-12: Write a program that prints its input one word per line.
 *
 * Thought: Here word means a string which does NOT contain a white space character.
 * When you encouter a character,just name it curr,if it is non-white space character,just print it.
 * However,if it is a white space character,you should take the previous character,just name it prev, into account.
 *
 * case1: If prev is white space character as well,just ignore curr.
 * case2：If prev is non-white space character,it reminds us the end of a word,and we need to move to next line.
 *
 * Since the first charcter may be a white space character, prev is initialized as ' ',meaning it is a white space character.
**/

int main(){
    int prev=' ';
    int curr;
    while((curr=getchar())!=EOF){
        if(curr==' ' || curr=='\t' || curr=='\n'){
            if(prev!=' ' && prev!='\t' && prev!='\n'){
                putchar('\n');//finish a word
            }
        }else{
            putchar(curr);
        }
        prev=curr;
    }
    return 0;
}

