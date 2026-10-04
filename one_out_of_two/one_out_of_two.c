#include <fcntl.h>
#include <stddef.h>
#include <unistd.h>

static int print_every_other(int fd)
{
    char c;
    size_t index = 0;
    ssize_t n = read(fd, &c, 1);

    while (n > 0)
    {
        if (index % 2 == 0)
        {
            if (write(STDOUT_FILENO, &c, 1) != 1)
                return 1;
        }
        index++;
        n = read(fd, &c, 1);
    }
    if (n < 0)
        return 1;
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
        return 1;
    int fd = open(argv[1], O_RDONLY);
    if (fd < 0)
        return 1;
    int result = print_every_other(fd);
    close(fd);
    return result;
}
