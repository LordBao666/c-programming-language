#ifndef QUICK_SORT_H
#define QUICK_SORT_H
//对数组 v[left...right]进行快速排序,comp是用于比较的函数指针
void myQsort(void *v[], int left, int right, int (*comp)(void *, void *));
#endif
