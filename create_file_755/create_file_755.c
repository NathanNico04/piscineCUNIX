#include <fcntl.h>
#include <stddef.h>
#include <unistd.h>

int create_file_755(const char *path)
{
    int fd;

    fd = open(path, O_WRONLY | O_CREAT, 0755);
    if (fd == -1)
        return 1;
    if (close(fd) == -1)
        return 1;
    return 0;
}
