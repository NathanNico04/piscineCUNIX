#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    if (argc < 2)
        return 0;

    int x = atoi(argv[1]);
    char buffer[4096];
    ssize_t bytes_read;

    while ((bytes_read = read(STDIN_FILENO, buffer, sizeof(buffer))) > 0)
    {
        for (ssize_t i = 0; i < bytes_read; i++)
        {
            char c = buffer[i];

            if (c >= 'a' && c <= 'z')
            {
                c = ((c - 'a' + x) % 26 + 26) % 26 + 'a';
            }
            else if (c >= 'A' && c <= 'Z')
            {
                c = ((c - 'A' + x) % 26 + 26) % 26 + 'A';
            }
            else if (c >= '0' && c <= '9')
            {
                c = ((c - '0' + x) % 10 + 10) % 10 + '0';
            }

            if (write(STDOUT_FILENO, &c, 1) != 1)
                return 1;
        }
    }

    if (bytes_read < 0)
        return 1;

    return 0;
}
