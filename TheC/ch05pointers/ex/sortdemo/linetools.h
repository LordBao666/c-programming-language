#ifndef LINE_TOOLS_H
#define LINE_TOOLS_H

/**
 * 从标准输入读取一行到s中,返回实际读取的数目
 * 由于实际的一行可能很长, 当读取的字符数达到max-1时,
 * 就不再读取。
 * 读取的字符末尾会添加文本终止符'\0'
 * 
 * 如果换行符存在的话，数将保留换行符.
 * 特殊情况1：标准输入没有内容时,返回EOF
 *
 * 特殊情况2：max 至少为2，因为max-1表示希望从标准输入最多读取的字符数,显然max<=1时
 * 毫无意义,这种情况返回-2,表示参数错误
 *
 *
 */
int getline(char *s, int max);

/**
 * 
 * 读取最多maxlines-1行 放到指针数组中去,返回实际读到的行数
 * 特殊情况：
 * 1 如果输入文本太多(达到maxlines),,则返回-1
 * 2 如果没有足够的内存保存文本,返回-1
 * 如果每行末尾含换行符'\n',将'\n'替换为'\0'
 */
int readlines(char *lineptr[], int maxlines);

//打印指针数组的前n个字符串
void writelines(char *lineptr[], int nlines);

#endif