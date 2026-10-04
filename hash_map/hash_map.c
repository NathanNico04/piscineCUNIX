#include "hash_map.h"

void *malloc(size_t size);
void *calloc(size_t nmemb, size_t size);
void free(void *ptr);
int printf(const char *format, ...);
int strcmp(const char *s1, const char *s2);

struct hash_map *hash_map_init(size_t size)
{
    struct hash_map *map = malloc(sizeof(*map));

    if (map == NULL)
        return NULL;

    map->data = calloc(size, sizeof(*map->data));
    if (map->data == NULL && size != 0)
    {
        free(map);
        return NULL;
    }

    map->size = size;
    return map;
}

bool hash_map_insert(struct hash_map *hash_map, const char *key, char *value,
                     bool *updated)
{
    if (hash_map == NULL || key == NULL || hash_map->size == 0)
        return false;

    size_t index = hash(key) % hash_map->size;
    struct pair_list *current = hash_map->data[index];

    while (current != NULL)
    {
        if (strcmp(current->key, key) == 0)
        {
            current->value = value;

            if (updated != NULL)
                *updated = true;

            return true;
        }

        current = current->next;
    }

    struct pair_list *new_pair = malloc(sizeof(*new_pair));

    if (new_pair == NULL)
        return false;

    new_pair->key = key;
    new_pair->value = value;
    new_pair->next = hash_map->data[index];

    hash_map->data[index] = new_pair;

    if (updated != NULL)
        *updated = false;

    return true;
}

void hash_map_free(struct hash_map *hash_map)
{
    if (hash_map == NULL)
        return;

    for (size_t i = 0; i < hash_map->size; i++)
    {
        struct pair_list *current = hash_map->data[i];

        while (current != NULL)
        {
            struct pair_list *next = current->next;

            free(current);
            current = next;
        }
    }

    free(hash_map->data);
    free(hash_map);
}

void hash_map_dump(struct hash_map *hash_map)
{
    if (hash_map == NULL)
        return;

    for (size_t i = 0; i < hash_map->size; i++)
    {
        struct pair_list *current = hash_map->data[i];

        if (current == NULL)
            continue;

        while (current != NULL)
        {
            printf("%s: %s", current->key, current->value);

            if (current->next != NULL)
                printf(", ");

            current = current->next;
        }

        printf("\n");
    }
}

const char *hash_map_get(const struct hash_map *hash_map, const char *key)
{
    if (hash_map == NULL || key == NULL || hash_map->size == 0)
        return NULL;

    size_t index = hash(key) % hash_map->size;
    struct pair_list *current = hash_map->data[index];

    while (current != NULL)
    {
        if (strcmp(current->key, key) == 0)
            return current->value;

        current = current->next;
    }

    return NULL;
}

bool hash_map_remove(struct hash_map *hash_map, const char *key)
{
    if (hash_map == NULL || key == NULL || hash_map->size == 0)
        return false;

    size_t index = hash(key) % hash_map->size;
    struct pair_list *current = hash_map->data[index];
    struct pair_list *previous = NULL;

    while (current != NULL)
    {
        if (strcmp(current->key, key) == 0)
        {
            if (previous == NULL)
                hash_map->data[index] = current->next;
            else
                previous->next = current->next;

            free(current);
            return true;
        }

        previous = current;
        current = current->next;
    }

    return false;
}
