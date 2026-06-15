#ifndef HASHTABLE_H
#define HASHTABLE_H

struct nlist {          /* table entry: */
    struct nlist *next; /* next entry in chain */
    char *name;         /* defined name */
    char *defn;         /* replacement text */
};

/* lookup: look for s in hashtab */
struct nlist *lookup(char *s);

/** install: put (name, defn) in hashtab 
 * 如果内存不足,则返回NULL
 */
struct nlist *install(char *name, char *defn);

/*删除hash表中的name*/
void undef(char * name);
#endif