#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

long getdelim(char **lineptr, size_t *n, int delim, FILE *stream);
int main(int argc, char **argv)
{
    FILE *file;
    char *line;
    size_t cap;
    long len;

    if (argc != 2)
        return 1;

    file = fopen(argv[1], "r");
    if (file == NULL)
        return 1;

    line = NULL;
    cap = 0;

    len = getdelim(&line, &cap, ';', file);
    while (len != -1)
    {
        if (len >= 4)
            putchar(line[3]);
        len = getdelim(&line, &cap, ';', file);
    }

    free(line);

    if (fclose(file) != 0)
        return 1;

    putchar('\n');
    return 0;
}
