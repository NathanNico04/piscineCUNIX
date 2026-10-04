#include "traffic_lights.h"

void init(unsigned char *lights)
{
    *lights ^= *lights;
}

void turn_on(unsigned char *lights, unsigned char light_num)
{
    unsigned char one = sizeof(*lights);

    *lights |= one << (light_num - one);
}

void turn_off(unsigned char *lights, unsigned char light_num)
{
    unsigned char one = sizeof(*lights);

    *lights &= ~(one << (light_num - one));
}

void next_step(unsigned char *lights)
{
    unsigned char one = sizeof(*lights);
    unsigned char two = one + one;
    unsigned char four = two + two;
    unsigned char mask = (one << four) - one;
    unsigned char last = (*lights >> (four - one)) & one;

    *lights = (*lights & ~mask) | ((*lights << one) & mask) | last;
}

void reverse(unsigned char *lights)
{
    unsigned char one = sizeof(*lights);
    unsigned char two = one + one;
    unsigned char four = two + two;
    unsigned char mask = (one << four) - one;

    *lights ^= mask;
}

void swap(unsigned char *lights_1, unsigned char *lights_2)
{
    if (lights_1 == lights_2)
        return;

    *lights_1 ^= *lights_2;
    *lights_2 ^= *lights_1;
    *lights_1 ^= *lights_2;
}
