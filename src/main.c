#include <stdio.h>

#include "boomeranguish.h"

int main(int argc, char **argv) {
    FILE *fp;
    if (argc == 1) {
        fp = stdin;
    } else if (argc == 2) {
        fp = fopen(argv[1], "r");
        if (!fp) {
            fprintf(stderr, "failed to open %s\n", argv[1]);
            return 1;
        }
    } else {
        fprintf(stderr, "usage:\n  %s [filename]\n  echo foo | %s\n", argv[0],
                argv[0]);
        return 1;
    }

    int ch;
    static BoomeranguishState bs;
    while ((ch = fgetc(fp)) != EOF) runChar(ch, &bs);

    fclose(fp);
    return 0;
}
