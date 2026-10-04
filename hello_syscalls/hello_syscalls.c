#include <stddef.h>
#include <unistd.h>

int main(void)
{
    const char msg[] = "Hello World!\n";
    size_t len = sizeof(msg) - 1;

    if (write(1, msg, len) == -1)
        return 1;
    return 0;
}
