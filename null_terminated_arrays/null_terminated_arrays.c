#include <stddef.h>

size_t array_length(const char **arr)
{
    size_t len = 0;
    while (arr[len] != NULL)
        len++;
    return len;
}

void reverse_array(const char **arr)
{
    size_t i = 0;
    size_t len = array_length(arr);

    while (i < len / 2)
    {
        const char *tmp = arr[i];
        arr[i] = arr[len - i - 1];
        arr[len - i - 1] = tmp;
        i++;
    }
}

size_t matrix_length(const char ***matrix)
{
    size_t len = 0;
    while (matrix[len] != NULL)
        len++;
    return len;
}

void reverse_rows(const char ***matrix)
{
    size_t i = 0;
    size_t len = matrix_length(matrix);

    while (i < len / 2)
    {
        const char **tmp = matrix[i];
        matrix[i] = matrix[len - i - 1];
        matrix[len - i - 1] = tmp;
        i++;
    }
}

void reverse_matrix(const char ***matrix)
{
    size_t i = 0;
    size_t len = matrix_length(matrix);

    reverse_rows(matrix);

    while (i < len)
    {
        reverse_array(matrix[i]);
        i++;
    }
}
