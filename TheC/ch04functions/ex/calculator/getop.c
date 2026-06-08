#include <ctype.h>
#include <stdio.h>
#define NUMBER '0'

int getch(void);
void ungetch(int c);

//   假设op充分大,能存储任意的一个操作数 或 操作符
//   从标准输入读取操作数或操作符到op中,并返回具体类型
//   返回值'0'代表是操作数, 或是 +-*/等运算符, 或是EOF
//   或是非法值
int getop(char op[]) {
    int c;
    // 跳过空格 和 制表符
    while (((c = getch()) == ' ') || c == '\t')
        ;

    int i = 0;

    // 如果c不是数字 且不是小数点
    // 也就说它可能是 +-*/ , 也有可能是 ?_等非法数字,更有可能是
    // EOF,都采取下面做法
    if (!isdigit(c) && c != '.') {

        // ex4.3加入对负数的处理逻辑
        if (c == '-') { //-号特殊处理
            c = getch();
            // 不是数字且不是小数点,那么这里的负号代表是减法
            if (!isdigit(c) && c != '.') {
                ungetch(c); // 将c放回去
                op[0] = '-';
                op[1] = '\0';
                return '-';
            } else { // 说明是负数
                op[i++] = '-';
            }
        } else {
            op[0] = c;
            op[1] = '\0';
            return c;
        }
    }

    if (isdigit(c)) { // 数字
        op[i++] = c;
        while (isdigit(c = getch())) { // 整数部分
            op[i++] = c;
        }
    }
    if (c == '.') { // 如果是小数点
        op[i++] = '.';
        while (isdigit(c = getch())) { // 小数部分
            op[i++] = c;
        }
    }
    if (c != EOF) { // 将多余读的字符放回
        ungetch(c);
    }
    op[i] = '\0';
    return NUMBER;
}

// 通过gcc -o main getch.c getop.c来测试下面案例
//  int main(){
//    char op[100];
//    //假定标准行输入为?   + 1.1  - .23+ 12
//    //下面会打印
//    //?
//    //+
//    //1.1
//    //-
//    //.23
//    //+
//    //12

//   while(getop(op)!=EOF){
//     printf("%s\n",op);
//   }

//   return 0;
// }