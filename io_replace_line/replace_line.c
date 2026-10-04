#define _POSIX_C_SOURCE 200809L

#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int replace_line(const char *file_in, const char *file_out, const char *content,
                 int n)
{
    FILE *in = fopen(file_in, "r");
    if (in == NULL)
        return -1;

    FILE *out = fopen(file_out, "w");
    if (out == NULL)
    {
        fclose(in);
        return -1;
    }

    char *line = NULL;
    size_t len = 0;
    int index = 0;
    int found = 0;
    int error = 0;

    while (getline(&line, &len, in) != -1)
    {
        if (index == n)
        {
            found = 1;
            if (fputs(content, out) == EOF)
                error = 1;
        }
        else
        {
            if (fputs(line, out) == EOF)
                error = 1;
        }
        index++;
    }

    free(line);
    fclose(in);
    fclose(out);

    if (error == 1)
        return -1;
    if (found == 0)
        return 1;
    return 0;
}
