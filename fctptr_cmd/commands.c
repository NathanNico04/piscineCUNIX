#include "commands.h"

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int cmd_help(const char *arg1)
{
    if (arg1)
    {
        fprintf(stderr, "fctptr_cmd: help takes no argument\n");
        return 1;
    }
    printf("The available commands are:\n");
    printf("help\n");
    printf("hello\n");
    printf("print string\n");
    printf("exit\n");
    printf("cat file\n");
    return 0;
}

int cmd_hello(const char *arg1)
{
    if (arg1)
    {
        fprintf(stderr, "fctptr_cmd: hello takes no argument\n");
        return 1;
    }
    printf("hello\n");
    return 0;
}

int cmd_print(const char *arg1)
{
    if (!arg1 || strchr(arg1, ' '))
    {
        fprintf(stderr, "fctptr_cmd: print can take only one argument\n");
        return 1;
    }
    printf("%s\n", arg1);
    return 0;
}

int cmd_exit(const char *arg1)
{
    if (arg1)
    {
        fprintf(stderr, "fctptr_cmd: exit takes no argument\n");
        return 1;
    }
    exit(0);
}

int cmd_cat(const char *arg1)
{
    if (!arg1 || strchr(arg1, ' '))
    {
        fprintf(stderr, "fctptr_cmd: cat can take only one argument\n");
        return 1;
    }
    int fd = open(arg1, O_RDONLY);
    if (fd < 0)
    {
        fprintf(stderr, "fctptr_cmd: cannot read %s\n", arg1);
        return 1;
    }
    char buf[512];
    ssize_t n = read(fd, buf, sizeof(buf));
    while (n > 0)
    {
        write(STDOUT_FILENO, buf, n);
        n = read(fd, buf, sizeof(buf));
    }
    if (n < 0)
    {
        fprintf(stderr, "fctptr_cmd: cannot read %s\n", arg1);
        close(fd);
        return 1;
    }
    close(fd);
    return 0;
}

const struct cmd commands[] = {
    { cmd_help, "help" }, { cmd_hello, "hello" }, { cmd_print, "print" },
    { cmd_exit, "exit" }, { cmd_cat, "cat" },     { NULL, NULL },
};
