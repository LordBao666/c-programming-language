#include "qsort.h"
#include <stdio.h>
#include <string.h>

static void swap(char *v[], int i, int j) {
    char *p = v[i];
    v[i] = v[j];
    v[j] = p;
}

void myQsort(char *v[], int left, int right) {
    if (left >= right) {
        return;
    }
    // 挑选中间元素作为基准,并将它和最左侧元素互换
    swap(v, left, left + ((right - left) >> 1));

    // 代码进行中,检查v[i]时,保持这样的不变性,left+1...last 指向
    // 的元素小于基准, last+1...i-1 大于等于基准
    int last = left, i = left + 1;
    while (i <= right) {
        // v[i]比基准v[left]小
        if (strcmp(v[i], v[left]) < 0) {
            swap(v, ++last, i);
        }
        i++;
    }
    // 将基准放到正确的位置
    swap(v, last, left);
    myQsort(v, left, last - 1);
    myQsort(v, last + 1, right);
}

// int main() {
//     char *strS[] = {
//         "hello",
//         "amp",
//         "joker",
//     };
//     const int size = 3;
//     myQsort(strS, 0, size - 1);
//     for (int i = 0; i < size; i++) {
//         printf("%s\n", strS[i]);
//     }
//     return 0;
// }