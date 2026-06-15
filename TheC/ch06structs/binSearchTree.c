#include "binSearchTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 对字符串s进行复制
static char *myStrdup(char *s);

// 如果root是null,则返回存储word的二叉搜索树
// 如果root不为null,将word插入到指定的位置,返回root本身
//     1.如果word在以root为根节点的二叉搜索树,则将对应的节点count+1
//     2.反之,若不存在,则创建新节点,并插入word
struct binSearchTree *addTree(struct binSearchTree *root, char *word) {
    if (root == NULL) {
        root = (struct binSearchTree *)malloc(sizeof(struct binSearchTree));
        // 空间分配成功
        if (root) {
            char *newword = myStrdup(word);
            if (newword) {
                root->word = newword;
                root->count = 1;
                root->left = root->right = NULL;
            } else { // newword分配失败,则将root的空间一并回收
                free(root);
                root = NULL;
            }
        }
        // root可能为null,表示空间不足,交由调用者处理
        return root;
    }

    int cond = strcmp(word, root->word);
    if (cond == 0) {
        root->count++;
    } else if (cond < 0) {
        root->left = addTree(root->left, word);
    } else {
        root->right = addTree(root->right, word);
    }
    return root;
}

// 打印树形结构,按照中序打印,即由小开始往大打印
void printTree(struct binSearchTree *root) {
    if (root) {
        printTree(root->left);
        printf("%s\t: %d\n", root->word, root->count);
        printTree(root->right);
    }
}

static char *myStrdup(char *s) {
    int len = strlen(s);
    char *dest = (char *)malloc(sizeof(char) * (len + 1)); // 预留'\0'
    if (dest) {
        strcpy(dest, s);
    }
    return dest;
}

void freeTree(struct binSearchTree *root) {
    if (root) {
        free(root->word);
        struct binSearchTree *left = root->left;
        struct binSearchTree *right = root->right;
        free(root);
        freeTree(left);
        freeTree(right);
    }
}

// int main() {
//     char *s[] = {"hello", "hello", "word", "hello", "word", "point", "point"};
//     int len = sizeof(s) / sizeof(char *);
//     struct binSearchTree *root = NULL;
//     for (int i = 0; i < len; i++) {
//         root = addTree(root, s[i]);
//     }
//     printTree(root);
// }