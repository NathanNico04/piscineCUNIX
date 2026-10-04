#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void process_line(char *line)
{
    int i = 0;
    while (line[i] != '\0')
    {
        if (line[i] == '\n' || line[i] == '\r')
        {
            line[i] = '\0';
            break;
        }
        i++;
    }
    if (line[0] == '\0')
        return;

    char *saveptr = NULL;
    char *token = strtok_r(line, ",", &saveptr);
    int has_val = 0;
    int max_val = 0;
    while (token)
    {
        if (token[0] != '\0')
        {
            int val = atoi(token);
            if (!has_val || val > max_val)
            {
                max_val = val;
                has_val = 1;
            }
        }
        token = strtok_r(NULL, ",", &saveptr);
    }
    if (has_val)
        printf("%d\n", max_val);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
        return 1;
    FILE *f = fopen(argv[1], "r");
    if (!f)
        return 1;
    char *line = NULL;
    size_t len = 0;
    while (getline(&line, &len, f) != -1)
        process_line(line);
    free(line);
    fclose(f);
    return 0;
}
