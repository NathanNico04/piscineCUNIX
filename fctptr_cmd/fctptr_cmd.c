#include <stdio.h>
#include <string.h>

#include "commands.h"

static void parse_line(char *line, char **name, char **arg)
{
    char *nl = strchr(line, '\n');
    if (nl)
        *nl = '\0';
    char *space = strchr(line, ' ');
    if (space)
    {
        *space = '\0';
        *arg = space + 1;
        if (**arg == '\0')
            *arg = NULL;
    }
    else
        *arg = NULL;
    *name = line;
}

static void run_command(const char *name, const char *arg)
{
    for (int i = 0; commands[i].command_name; i++)
    {
        if (strcmp(commands[i].command_name, name) == 0)
        {
            commands[i].handle(arg);
            return;
        }
    }
    fprintf(stderr, "fctptr_cmd: unknown command\n");
}

int main(void)
{
    char line[1024];

    fputs("cmd$ ", stdout);
    fflush(stdout);
    while (fgets(line, sizeof(line), stdin))
    {
        char *name;
        char *arg;

        parse_line(line, &name, &arg);
        if (*name != '\0')
            run_command(name, arg);
        fputs("cmd$ ", stdout);
        fflush(stdout);
    }
    return 0;
}
