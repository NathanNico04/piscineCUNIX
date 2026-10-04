#include <stddef.h>
#include <stdio.h>

struct complex
{
    float real;
    float img;
};

void print_complex(struct complex a)
{
    if (a.img < 0)
        printf("complex(%.2f - %.2fi)\n", a.real, -a.img);
    else
        printf("complex(%.2f + %.2fi)\n", a.real, a.img);
}

struct complex neg_complex(struct complex a)
{
    struct complex res;
    res.real = -1 * a.real;
    res.img = -1 * a.img;
    return res;
}

struct complex add_complex(struct complex a, struct complex b)
{
    struct complex res;
    res.real = a.real + b.real;
    res.img = a.img + b.img;
    return res;
}

struct complex sub_complex(struct complex a, struct complex b)
{
    struct complex res;
    res.real = a.real - b.real;
    res.img = a.img - b.img;
    return res;
}

struct complex mul_complex(struct complex a, struct complex b)
{
    struct complex res;
    res.real = a.real * b.real - a.img * b.img;
    res.img = a.real * b.img + a.img * b.real;
    return res;
}

struct complex div_complex(struct complex a, struct complex b)
{
    struct complex res;
    float den = b.real * b.real + b.img * b.img;
    res.real = (a.real * b.real + a.img * b.img) / den;
    res.img = (a.img * b.real - a.real * b.img) / den;
    return res;
}
