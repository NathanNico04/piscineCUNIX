#ifndef MACRO_VECTOR_H
#define MACRO_VECTOR_H

#include <stdbool.h>
#include <stddef.h>

void *realloc(void *ptr, size_t size);
void free(void *ptr);

#define DECL_VECTOR_STRUCT(Name, Type)                                         \
    struct Name                                                                \
    {                                                                          \
        Type *data;                                                            \
        size_t size;                                                           \
        size_t capacity;                                                       \
    };

#define DECL_VECTOR_INIT(Name, Type)                                           \
    static inline void Name##_init(struct Name *vector)                        \
    {                                                                          \
        vector->data = NULL;                                                   \
        vector->size = 0;                                                      \
        vector->capacity = 0;                                                  \
    }

#define DECL_VECTOR_FREE(Name, Type)                                           \
    static inline void Name##_free(struct Name *vector)                        \
    {                                                                          \
        free(vector->data);                                                    \
        vector->data = NULL;                                                   \
        vector->size = 0;                                                      \
        vector->capacity = 0;                                                  \
    }

#define DECL_VECTOR_SIZE(Name, Type)                                           \
    static inline size_t Name##_size(const struct Name *vector)                \
    {                                                                          \
        return vector->size;                                                   \
    }

#define DECL_VECTOR_INSERT(Name, Type)                                         \
    static inline bool Name##_insert(struct Name *vector, size_t pos,          \
                                     Type element)                             \
    {                                                                          \
        if (pos > vector->size)                                                \
        {                                                                      \
            return false;                                                      \
        }                                                                      \
                                                                               \
        if (vector->size == vector->capacity)                                  \
        {                                                                      \
            size_t new_capacity =                                              \
                vector->capacity == 0 ? 1 : vector->capacity * 2;              \
            Type *new_data =                                                   \
                realloc(vector->data, new_capacity * sizeof(Type));            \
                                                                               \
            if (new_data == NULL)                                              \
            {                                                                  \
                return false;                                                  \
            }                                                                  \
                                                                               \
            vector->data = new_data;                                           \
            vector->capacity = new_capacity;                                   \
        }                                                                      \
                                                                               \
        size_t i = vector->size;                                               \
        while (i > pos)                                                        \
        {                                                                      \
            vector->data[i] = vector->data[i - 1];                             \
            i--;                                                               \
        }                                                                      \
                                                                               \
        vector->data[pos] = element;                                           \
        vector->size++;                                                        \
        return true;                                                           \
    }

#define DECL_VECTOR_PUSH_BACK(Name, Type)                                      \
    static inline bool Name##_push_back(struct Name *vector, Type element)     \
    {                                                                          \
        if (vector->size == vector->capacity)                                  \
        {                                                                      \
            size_t new_capacity =                                              \
                vector->capacity == 0 ? 1 : vector->capacity * 2;              \
            Type *new_data =                                                   \
                realloc(vector->data, new_capacity * sizeof(Type));            \
                                                                               \
            if (new_data == NULL)                                              \
            {                                                                  \
                return false;                                                  \
            }                                                                  \
                                                                               \
            vector->data = new_data;                                           \
            vector->capacity = new_capacity;                                   \
        }                                                                      \
                                                                               \
        vector->data[vector->size] = element;                                  \
        vector->size++;                                                        \
        return true;                                                           \
    }

#define DECL_VECTOR_REMOVE(Name, Type)                                         \
    static inline bool Name##_remove(struct Name *vector, size_t pos)          \
    {                                                                          \
        if (pos >= vector->size)                                               \
        {                                                                      \
            return false;                                                      \
        }                                                                      \
                                                                               \
        size_t i = pos;                                                        \
        while (i + 1 < vector->size)                                           \
        {                                                                      \
            vector->data[i] = vector->data[i + 1];                             \
            i++;                                                               \
        }                                                                      \
                                                                               \
        vector->size--;                                                        \
        return true;                                                           \
    }

#define DECL_VECTOR_GET(Name, Type)                                            \
    static inline Type Name##_get(struct Name *vector, size_t pos)             \
    {                                                                          \
        return vector->data[pos];                                              \
    }

#define DECL_VECTOR(Name, Type)                                                \
    DECL_VECTOR_STRUCT(Name, Type)                                             \
    DECL_VECTOR_INIT(Name, Type)                                               \
    DECL_VECTOR_FREE(Name, Type)                                               \
    DECL_VECTOR_SIZE(Name, Type)                                               \
    DECL_VECTOR_INSERT(Name, Type)                                             \
    DECL_VECTOR_PUSH_BACK(Name, Type)                                          \
    DECL_VECTOR_REMOVE(Name, Type)                                             \
    DECL_VECTOR_GET(Name, Type)

#endif /* MACRO_VECTOR_H */
