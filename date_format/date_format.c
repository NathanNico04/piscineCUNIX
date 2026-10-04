#include "date_format.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *date_format(const char *format)
{
    if (!format)
        return NULL;

    time_t rawtime;
    if (time(&rawtime) == (time_t)-1)
        return NULL;

    struct tm *info = gmtime(&rawtime);
    if (!info)
        return NULL;

    char year_str[5];
    char month_str[3];
    char day_str[3];

    if (sprintf(year_str, "%04d", info->tm_year + 1900) < 0)
        return NULL;
    if (sprintf(month_str, "%02d", info->tm_mon + 1) < 0)
        return NULL;
    if (sprintf(day_str, "%02d", info->tm_mday) < 0)
        return NULL;

    char *copy = strdup(format);
    if (!copy)
        return NULL;

    char *tokens[3];
    int count = 0;
    char *saveptr = NULL;

    char *token = strtok_r(copy, ";:,_-", &saveptr);
    while (token && count < 3)
    {
        tokens[count++] = token;
        token = strtok_r(NULL, ";:,_-", &saveptr);
    }

    if (count != 3 || token != NULL)
    {
        free(copy);
        return NULL;
    }

    char *y_val = NULL;
    char *m_val = NULL;
    char *d_val = NULL;

    for (int i = 0; i < 3; i++)
    {
        if (strcmp(tokens[i], "Y") == 0)
        {
            if (y_val)
            {
                free(copy);
                return NULL;
            }
            y_val = year_str;
        }
        else if (strcmp(tokens[i], "M") == 0)
        {
            if (m_val)
            {
                free(copy);
                return NULL;
            }
            m_val = month_str;
        }
        else if (strcmp(tokens[i], "D") == 0)
        {
            if (d_val)
            {
                free(copy);
                return NULL;
            }
            d_val = day_str;
        }
        else
        {
            free(copy);
            return NULL;
        }
    }

    if (!y_val || !m_val || !d_val)
    {
        free(copy);
        return NULL;
    }

    char sep1 = 0;
    char sep2 = 0;
    size_t len = strlen(format);
    int sep_count = 0;

    for (size_t i = 0; i < len; i++)
    {
        char c = format[i];
        if (c == ';' || c == ':' || c == ',' || c == '_' || c == '-')
        {
            if (sep_count == 0)
                sep1 = c;
            else if (sep_count == 1)
                sep2 = c;
            sep_count++;
        }
    }

    if (sep_count != 2)
    {
        free(copy);
        return NULL;
    }

    char *res = malloc(64);
    if (!res)
    {
        free(copy);
        return NULL;
    }

    char *val1 = NULL;
    char *val2 = NULL;
    char *val3 = NULL;
    int idx = 0;
    char *p = (char *)format;

    while (*p)
    {
        if (*p == 'Y' || *p == 'M' || *p == 'D')
        {
            if (idx == 0)
            {
                if (*p == 'Y')
                    val1 = y_val;
                else if (*p == 'M')
                    val1 = m_val;
                else if (*p == 'D')
                    val1 = d_val;
            }
            else if (idx == 1)
            {
                if (*p == 'Y')
                    val2 = y_val;
                else if (*p == 'M')
                    val2 = m_val;
                else if (*p == 'D')
                    val2 = d_val;
            }
            else if (idx == 2)
            {
                if (*p == 'Y')
                    val3 = y_val;
                else if (*p == 'M')
                    val3 = m_val;
                else if (*p == 'D')
                    val3 = d_val;
            }
            idx++;
        }
        p++;
    }

    if (sprintf(res, "%s%c%s%c%s", val1, sep1, val2, sep2, val3) < 0)
    {
        free(res);
        free(copy);
        return NULL;
    }

    free(copy);
    return res;
}
