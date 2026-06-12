#include "getop.h"
#include <ctype.h>
#include <stdio.h>

// op必然是非空字符串,返回op代表的具体类型
// 如果是+ - x d %的运算符,返回它本身
// 上述x表示乘法, d表示除法。因为命令行中'*' 和 '/'很特殊,用单引号可能也不管用。
// 如果是3.14,-3的数字,返回'0'代表数字。
// 如果是非法字符串,返回-1
// 注意,我们认为后缀表达式 类似于带加号前缀的+3.12 是非法的,请用3.12替代
int getop(char *op) {
    int c = *op;

    // 如果c不是数字 且不是小数点
    // 也就说它可能是 + - x d % , 也有可能是 ?_等非法数字采取下面做法
    if (!isdigit(c) && c != '.') {
        int next = *++op;
        // 单个字符
        if (!next) {
            if (c != '+' && c != '-' && c != 'x' && c != 'd' && c != '%') {
                return BAD_TYPE;
            }
            return c;
        }

        // 多个字符
        if (c == '-') { //-号特殊处理
            c = next;
        } else {
            return BAD_TYPE; // 再次强调,我们认为类似于带加号前缀的+3.12 是非法的,请用3.12替代
        }
    }

    if (isdigit(c)) { // 数字
        while (isdigit(c = *++op))
            ; // 整数部分
    }
    if (c == '.') { // 如果是小数点
        while (isdigit(c = *++op))
            ; // 小数部分
    }
    // 字符串还未结束,非法！
    if (c) {
        return BAD_TYPE;
    }
    return NUMBER;
}

// int main() {
//     printf("%d\n", getop("?"));      // 打印-1,非法
//     printf("%d\n", getop("-"));      // 打印'-'的ASCII码
//     printf("%d\n", getop("3.14"));   // 打印'0'的ASCII码
//     printf("%d\n", getop("-3.14"));  // 打印'0'的ASCII码
//     printf("%d\n", getop("+3.14"));  // 打印-1,非法
//     printf("%d\n", getop("+1"));     // 打印-1,非法
//     printf("%d\n", getop("-3.14?")); // 打印-1,非法
//     return 0;
// }