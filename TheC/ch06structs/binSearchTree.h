#ifndef BIN_SEARCH_TREE_H
#define BIN_SEARCH_TREE_H

/*二叉搜索树*/
struct binSearchTree {
    char *word;
    int count;
    struct binSearchTree *left;
    struct binSearchTree *right;
};

// 如果root是null,则返回存储word的二叉搜索树
// 如果root不为null,将word插入到指定的位置,返回root本身
//     1.如果word在以root为根节点的二叉搜索树,则将对应的节点count+1
//     2.反之,若不存在,则创建新节点,并插入word
struct binSearchTree *addTree(struct binSearchTree *root, char *word);

// 打印树形结构,按照中序打印,即由小开始往大打印
void printTree(struct binSearchTree *root);

void freeTree(struct binSearchTree *root);
#endif
