#include "../binSearchTree.h"
#include "../getword.h"
#include <ctype.h>
#include <stdio.h>

#define MAX_WORD 100 // 一个单词最长100

// gcc -o main ../{getword.c,getch.c,binSearchTree.c} countwords.c
int main() {
    char word[MAX_WORD + 1]; // 预留'\0'
    struct binSearchTree *root = NULL;
    while ((getword(word, MAX_WORD)) > 0) {
        if (isalpha(word[0])) { // 确实是以字母为开始的单词,而不是特殊字符?.等
            root = addTree(root, word);
        }
    }
    //注意这里并没有考虑空间不足的处理
    printTree(root);
    return 0;
}