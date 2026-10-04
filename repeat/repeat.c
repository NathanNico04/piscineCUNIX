#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        return 1;
    }
    else
    {
        char *str = argv[1];
        int nb_repeat = *argv[2] - '0';
        for (int i = 0; i < nb_repeat; i++)
        {
            puts(str);
        }
    }
    return 0;
}
