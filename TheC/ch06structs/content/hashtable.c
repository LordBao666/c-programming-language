#include "hashtable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE 101
static struct nlist *hashtable[HASHSIZE];
/* hash: form hash value for string s */
static unsigned hash(char *s) {
    unsigned hashval;
    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

static char *myStrdup(char *s) {
    int len = strlen(s);
    char *dest = (char *)malloc(sizeof(char) * (len + 1)); // 预留'\0'
    if (dest) {
        strcpy(dest, s);
    }
    return dest;
}

/* lookup: look for s in hashtab */
struct nlist *lookup(char *s) {
    unsigned index = hash(s);
    struct nlist *p = hashtable[index];
    // p非空且s 和 p->name 不匹配
    while (p && strcmp(s, p->name)) {
        p = p->next;
    }
    // p非空,那么说明循环退出是因为s 和 p->name匹配,此时返回p
    // p空,则说明当前链表没有一个与s匹配,应该返回NULL(P本身)
    // 综上,返回p
    return p;
}

/** install: put (name, defn) in hashtab
 * 如果内存不足,则返回NULL
 */
struct nlist *install(char *name, char *defn) {
    struct nlist *p = lookup(name);
    // p为null.
    if (!p) {
        p = (struct nlist *)malloc(sizeof(struct nlist));
        char *newname = myStrdup(name);
        char *newdefn = myStrdup(defn);
        // 如果p和newname都成功分配
        if (p && newname && newdefn) {
            unsigned index = hash(name);
            p->next = hashtable[index];
            hashtable[index] = p;
            p->name = newname;
            p->defn = newdefn;
            return p;
        } else { // 但凡有一个分配失败
            free(p);
            free(newname);
            free(newdefn);
            return NULL;
        }
    } else { // p不为null
        char *newdefn = myStrdup(defn);
        if (newdefn) {     // 空间分配成功
            free(p->defn); // 回收旧的
            p->defn = newdefn;
            return p;
        } else {
            return NULL;
        }
    }
}

/*删除hash表中的name*/
void undef(char *name) {
    unsigned index = hash(name);
    struct nlist *p = hashtable[index];
    if (p == NULL) {
        return;
    }

    // 首节点匹配
    if (strcmp(p->name, name) == 0) {
        hashtable[index] = p->next;
        // 不要修改下列顺序
        free(p->name);
        free(p->defn);
        free(p);
        return;
    }

    struct nlist *q = p->next;
    while (q) {
        if (strcmp(q->name, name) == 0) {
            p->next = q->next;
            // 不要修改下列顺序
            free(q->name);
            free(q->defn);
            free(q);
            return;
        }
        p = q;
        q = q->next;
    }
}

// int main() {
//     char *key[] = {"hi", "hi", "ye", "ye"};
//     char *val[] = {"1", "2", "3", "4"};
//     for (int i = 0; i < (sizeof(key) / sizeof(char *)); i++) {
//         install(key[i], val[i]);
//     }
//     printf("%s->%s\n", key[0], lookup(key[0])->defn);
//     printf("%s->%s\n", key[2], lookup(key[2])->defn);
//     undef(key[0]);
//     if (lookup(key[0])) {
//         printf("见了鬼了...\n");
//     }

//     return 0;
// }