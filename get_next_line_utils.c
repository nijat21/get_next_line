#include "get_next_line.h"

int count_line_chars(char *str)
{
    int count;

    count = 0;
    while (str[count] && str[count] != '\n')
        count++;
    if (str[count] == '\n')
        count++;
    return count;
}

char *single_line(char *buffer, int is_end)
{
    char *line;
    int count;
    int i;

    count = count_line_chars(buffer);
    line = (char *)malloc((count + 1) * sizeof(char));
    if (!line)
        return NULL;
    i = 0;
    while (i < count)
    {
        line[i] = buffer[i];
        i++;
    }
    if (is_end && buffer[i] != '\n')
        line[i] = '\0';
    else if (buffer[i] == '\n' && is_end)
    {
        line[i] = '\n';
        line[i + 1] = '\0';
    }
    return line;
}

void *ft_memcpy(void *dst, const void *src)
{
    size_t i;
    char *source;
    char *destination;

    source = (char *)src;
    destination = (char *)dst;
    i = 0;
    while (source[i])
    {
        destination[i] = source[i];
        i++;
    }
    return dst;
}

// buffer[2] != '\n'