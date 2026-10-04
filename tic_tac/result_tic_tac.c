#include "tic_tac.h"

static int check_win(char buf[3][3], char p)
{
    for (int i = 0; i < 3; i++)
    {
        if (buf[i][0] == p && buf[i][1] == p && buf[i][2] == p)
            return 1;
        if (buf[0][i] == p && buf[1][i] == p && buf[2][i] == p)
            return 1;
    }
    if (buf[0][0] == p && buf[1][1] == p && buf[2][2] == p)
        return 1;
    if (buf[0][2] == p && buf[1][1] == p && buf[2][0] == p)
        return 1;
    return 0;
}

static int count_char(char buf[3][3], char p)
{
    int cnt = 0;
    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            if (buf[r][c] == p)
                cnt++;
        }
    }
    return cnt;
}

int result_tic_tac(const char *file)
{
    if (!file)
        return -1;
    FILE *f = fopen(file, "r");
    if (!f)
        return -1;
    char buf[3][3];
    if (read_tic_tac(buf, f) != 0)
    {
        fclose(f);
        return -1;
    }
    fclose(f);
    int nx = count_char(buf, 'X');
    int no = count_char(buf, 'O');
    if (nx < no || nx > no + 1)
        return -1;
    int wx = check_win(buf, 'X');
    int wo = check_win(buf, 'O');
    if ((wx && nx != no + 1) || (wo && nx != no) || (wx && wo))
        return -1;
    if (wx)
        fputs("Winner: X\n", stdout);
    else if (wo)
        fputs("Winner: O\n", stdout);
    else
        fputs("Winner: none\n", stdout);
    return 0;
}
