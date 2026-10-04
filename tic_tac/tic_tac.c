#include "tic_tac.h"

int read_tic_tac(char buffer[3][3], FILE *stream)
{
    if (!stream || !buffer)
        return -1;
    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            int ch = fgetc(stream);
            if (ch != 'X' && ch != 'O' && ch != ' ')
                return -1;
            buffer[r][c] = ch;
            if (c < 2 && fgetc(stream) != '|')
                return -1;
        }
        if (fgetc(stream) != '\n')
            return -1;
    }
    if (fgetc(stream) != EOF)
        return -1;
    return 0;
}

int write_tic_tac(char buffer[3][3], FILE *stream)
{
    if (!stream || !buffer)
        return -1;
    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            if (fputc(buffer[r][c], stream) == EOF)
                return -1;
            if (c < 2 && fputc('|', stream) == EOF)
                return -1;
        }
        if (fputc('\n', stream) == EOF)
            return -1;
    }
    return 0;
}

int init_tic_tac(const char *file)
{
    if (!file)
        return -1;
    FILE *f = fopen(file, "w");
    if (!f)
        return -1;
    char buf[3][3] = { { ' ', ' ', ' ' },
                       { ' ', ' ', ' ' },
                       { ' ', ' ', ' ' } };
    int res = write_tic_tac(buf, f);
    fclose(f);
    return res;
}

int fill_tic_tac(const char *file, size_t line, size_t col, char value)
{
    if (!file || line >= 3 || col >= 3 || (value != 'X' && value != 'O'))
        return -1;
    FILE *f = fopen(file, "r");
    if (!f)
        return -1;
    char buf[3][3];
    if (read_tic_tac(buf, f) != 0)
    {
        fclose(f);
        return -2;
    }
    fclose(f);
    if (buf[line][col] != ' ')
        return -3;
    buf[line][col] = value;
    f = fopen(file, "w");
    if (!f)
        return -1;
    int res = write_tic_tac(buf, f);
    fclose(f);
    return res;
}
