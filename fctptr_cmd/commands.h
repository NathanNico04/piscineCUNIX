#ifndef COMMANDS_H
#define COMMANDS_H

typedef int (*handler)(const char *arg1);

struct cmd
{
    handler handle;
    const char *command_name;
};

int cmd_help(const char *arg1);
int cmd_hello(const char *arg1);
int cmd_print(const char *arg1);
int cmd_exit(const char *arg1);
int cmd_cat(const char *arg1);

extern const struct cmd commands[];

#endif /* ! COMMANDS_H */
