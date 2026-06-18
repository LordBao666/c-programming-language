#include <stdio.h>
#include <stdlib.h>

void filecopy(FILE *from, FILE *to);

int main(int argc, char *argv[]) {
    if (argc == 1) {
        filecopy(stdin, stdout);
    } else {
        for (int i = 1; i < argc; i++) {
            FILE *file = fopen(argv[i], "r");
            if (!file) {
                fprintf(stderr, "%s can not open %s\n", argv[0], argv[i]);
                exit(1);
            } else {
                filecopy(file, stdout);
                fclose(file);
            }
        }
    }
    exit(0);
}

void filecopy(FILE *from, FILE *to) {
    int c;
    while ((c = getc(from)) != EOF) {
        putc(c, to);
    }
}