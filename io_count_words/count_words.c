#include <stdio.h>

static int is_separator(int c)
{
    return (c == ' ' || c == '\t' || c == '\n');
}

int count_words(const char *file_in)
{
    FILE *cur_file;
    int c;
    int in_word;
    int compt;

    if (file_in == NULL)
        return -1;

    cur_file = fopen(file_in, "r");
    if (!cur_file)
        return -1;

    in_word = 0;
    compt = 0;
    c = fgetc(cur_file);
    while (c != EOF)
    {
        if (is_separator(c))
            in_word = 0;
        else if (in_word == 0)
        {
            in_word = 1;
            compt++;
        }
        c = fgetc(cur_file);
    }

    if (fclose(cur_file) != 0)
        return -1;

    return compt;
}
