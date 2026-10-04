#include "lakes.h"

struct MapData
{
    char **map;
    int width;
    int height;
};

void remplissage(struct MapData *data, int x, int y)
{
    if (x < 0 || x >= data->width || y < 0 || y >= data->height)
        return;

    if (data->map[y][x] != '.')
        return;

    data->map[y][x] = '#';

    remplissage(data, x + 1, y);
    remplissage(data, x - 1, y);
    remplissage(data, x, y + 1);
    remplissage(data, x, y - 1);
}

int lakes(char **map, int width, int height)
{
    int count = 0;

    struct MapData data;
    data.map = map;
    data.width = width;
    data.height = height;

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            if (map[y][x] == '.')
            {
                count++;
                remplissage(&data, x, y);
            }
        }
    }

    return count;
}
