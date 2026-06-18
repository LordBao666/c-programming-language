#include <stdio.h>

void filecopy(FILE *from, FILE *to);

int main(int argc, char *argv[]) {
    if (argc == 1) {
        filecopy(stdin, stdout);
    } else {
        for (int i = 1; i < argc; i++) {
            FILE *file = fopen(argv[i], "r");
            if (!file) {
                printf("%s doesn't exists!\n", argv[i]);
                return -1;
            } else {
                filecopy(file, stdout);
                fclose(file);
            }
        }
    }
    return 0;
}

void filecopy(FILE *from, FILE *to) {
    int c;
    while ((c = getc(from)) != EOF) {
        putc(c, to);
    }
}