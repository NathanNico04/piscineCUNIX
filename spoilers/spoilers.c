#include <fcntl.h>
#include <stddef.h>
#include <unistd.h>

static int is_whitespace(char c)
{
    return c == ' ' || c == '\f' || c == '\r' || c == '\n' || c == '\t'
        || c == '\v';
}

static size_t my_strlen(const char *s)
{
    size_t len = 0;
    while (s[len] != '\0')
        len++;
    return len;
}

static void print_error(const char *msg)
{
    write(STDERR_FILENO, msg, my_strlen(msg));
}

static int get_last_two(int fd, char *out)
{
    off_t pos = lseek(fd, 0, SEEK_END);
    if (pos < 0)
        return -1;
    int found = 0;
    char c;
    while (pos > 0 && found < 2)
    {
        pos--;
        if (lseek(fd, pos, SEEK_SET) < 0)
            return -1;
        if (read(fd, &c, 1) != 1)
            return -1;
        if (!is_whitespace(c))
        {
            out[found] = c;
            found++;
        }
    }
    return found;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        print_error("Invalid number of arguments\n");
        return 1;
    }
    int fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        print_error("Could not open file\n");
        return 1;
    }
    char result[2];
    int found = get_last_two(fd, result);
    close(fd);
    if (found < 0)
    {
        print_error("Could not open file\n");
        return 1;
    }
    if (found < 2)
    {
        print_error("File is not long enough\n");
        return 1;
    }
    char output[3] = { result[1], result[0], '\n' };
    write(STDOUT_FILENO, output, 3);
    return 0;
}
