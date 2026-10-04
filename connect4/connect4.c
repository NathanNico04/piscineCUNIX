#include "connect4.h"

static int check_line(const char *game[], size_t r, size_t c, char p)
{
    if (game[r][c] == p && game[r][c + 1] == p && game[r][c + 2] == p
        && game[r][c + 3] == p)
        return 1;
    return 0;
}

static int check_col(const char *game[], size_t r, size_t c, char p)
{
    if (game[r][c] == p && game[r + 1][c] == p && game[r + 2][c] == p
        && game[r + 3][c] == p)
        return 1;
    return 0;
}

static int check_diag1(const char *game[], size_t r, size_t c, char p)
{
    if (game[r][c] == p && game[r + 1][c + 1] == p && game[r + 2][c + 2] == p
        && game[r + 3][c + 3] == p)
        return 1;
    return 0;
}

static int check_diag2(const char *game[], size_t r, size_t c, char p)
{
    if (game[r][c + 3] == p && game[r + 1][c + 2] == p
        && game[r + 2][c + 1] == p && game[r + 3][c] == p)
        return 1;
    return 0;
}

static int check_player(const char *game[], size_t lines, size_t columns,
                        char p)
{
    for (size_t r = 0; r < lines; r++)
    {
        for (size_t c = 0; c < columns; c++)
        {
            if (c + 3 < columns && check_line(game, r, c, p))
                return 1;
            if (r + 3 < lines && check_col(game, r, c, p))
                return 1;
            if (r + 3 < lines && c + 3 < columns && check_diag1(game, r, c, p))
                return 1;
            if (r + 3 < lines && c >= 3 && check_diag2(game, r, c - 3, p))
                return 1;
        }
    }
    return 0;
}

int connect4(const char *game[], size_t columns, size_t lines)
{
    if (!game || columns < 4 || lines < 4)
        return 0;

    int p1 = check_player(game, lines, columns, '1');
    int p2 = check_player(game, lines, columns, '0');

    if (p1 && !p2)
        return 1;
    if (p2 && !p1)
        return 2;
    return 0;
}
