#include <stdio.h>

struct mapping
{
    char cipher;
    int freq;
    char original;
};

static void count_freqs(const char text[], int freqs[])
{
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] >= 'A' && text[i] <= 'Z')
            freqs[text[i] - 'A']++;
    }
}

static int collect_chars(int freqs[], struct mapping map[])
{
    int count = 0;
    for (int i = 0; i < 26; i++)
    {
        if (freqs[i] > 0)
        {
            map[count].cipher = 'A' + i;
            map[count].freq = freqs[i];
            count++;
        }
    }
    return count;
}

static void sort_by_freq(struct mapping map[], int count)
{
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (map[j].freq < map[j + 1].freq
                || (map[j].freq == map[j + 1].freq
                    && map[j].cipher > map[j + 1].cipher))
            {
                struct mapping tmp = map[j];
                map[j] = map[j + 1];
                map[j + 1] = tmp;
            }
        }
    }
}

static void assign_originals(struct mapping map[], int count,
                             const char table[])
{
    for (int i = 0; i < count; i++)
    {
        map[i].original = table[i];
    }
}

static void sort_by_cipher(struct mapping map[], int count)
{
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (map[j].cipher > map[j + 1].cipher)
            {
                struct mapping tmp = map[j];
                map[j] = map[j + 1];
                map[j + 1] = tmp;
            }
        }
    }
}

void freq_analysis(const char text[], const char table[])
{
    int freqs[26] = { 0 };
    struct mapping map[26];

    count_freqs(text, freqs);
    int count = collect_chars(freqs, map);
    sort_by_freq(map, count);
    assign_originals(map, count, table);
    sort_by_cipher(map, count);

    for (int i = 0; i < count; i++)
    {
        printf("%c %c\n", map[i].cipher, map[i].original);
    }
}
