#ifndef GET_WORD_H
#define GET_WORD_H
/**
 * 跳过空白符,再从标准输入中获取一个单词,并存储到word中
 *  这个单词可以是
 *      1.普通单词，以字母开头的字母/数字串，比如hello,h123,
 *      2.普通字符,比如 + 1
 *  返回普通单词的首字符,比如hello返回h, 如果是普通字符,则返回它本身
 *
 *  特别地,如果文件碰到EOF,则返回EOF.
 *
 *  word长度不能超过lim,超过的部分将忽略不计
 *  比如lim=2,而word是hello, 那么只保留he,而llo仍保留在标准输入中
 *
 *  lim至少为1,否则没有意义
 */
int getword(char *word, int lim);
#endif