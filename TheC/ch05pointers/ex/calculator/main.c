#include <stdio.h>
#include <stdlib.h> //借用atof函数
#include "getop.h"
#include "stack.h"

/*测试案例中的数据答案均为100*/
// 本案例用于计算 expr 2 3 4 + x的后缀表达式
// 支持+ - x d %运算,其中x表示乘法, d表示除法。因为命令行中'*' 和 '/'很特殊,用单引号可能也不管用。
// 支持浮点。
// 请注意,对于正数,类似于带加号前缀的+3.12 是非法的,请用3.12替代
int main(int argc,char* argv[]) {
    if(argc==1){
        printf("后缀表达式非法!\n");
    }
    int argIndex=1;
    int type;         // getop返回类型
    while (argIndex<argc) {
        type = getop(argv[argIndex]);
        switch (type) {
        case NUMBER: {
            pushStack(atof(argv[argIndex]));
            break;
        }
        case '+': {
            pushStack(popStack() + popStack());
            break;
        }
        case 'x': {
            pushStack(popStack() * popStack());
            break;
        }
        case '-': {
            double op2 = popStack();
            pushStack(popStack() - op2);
            break;
        }
        case 'd': {
            double op2 = popStack();
            if (op2 == 0.0) {
                printf("除数不能为0\n");
                printf("程序非法退出...\n");
                return -1;
            }
            pushStack(popStack() / op2);
            break;
        }
        case '%': { 
            int op2 = (int)popStack();
            if (op2 == 0) {
                printf("模不能为0\n");
                printf("程序非法退出...\n");
                return -1;
            }
            pushStack(((int)popStack()) % op2);
            break;
        }
        default: {
            printf("后缀表达式非法!\n");
            return -1;
        }
        }
        argIndex++;
    }
    if(stackSize()==1){
        printf("\t%.8g\n", popStack());
        return 0;
    }else{
        printf("后缀表达式非法!\n");
        return -1;
    }
}