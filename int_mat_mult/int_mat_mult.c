#include "int_mat_mult.h"

void mat_mult(int **mat1, int **mat2, size_t *matrices_size, int **out)
{
    size_t a = matrices_size[0];
    size_t b = matrices_size[1];
    size_t c = matrices_size[2];

    size_t i = 0;

    while (i < a)
    {
        size_t j = 0;

        while (j < c)
        {
            int sum = 0;
            size_t k = 0;

            while (k < b)
            {
                sum += mat1[i][k] * mat2[k][j];
                k++;
            }
            out[i][j] = sum;
            j++;
        }
        i++;
    }
}
