#include "get_next_line.h"

int count_line_chars(char *str)
{
    int count;
    if (!str)
        return (0);
    count = 0;
    while (str[count] && str[count] != '\n')
        count++;
    if (str[count] == '\n')
        count++;
    return count;
}

char *single_line(char *buffer)
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
        // printf("BUFF[i]: %c\n", buffer[i]);
        i++;
    }
    line[i] = '\0';
    return line;
}

char *ft_strjoin(char *s1, char *s2)
{
    size_t len;
    char *str;
    char *start;

    len = count_line_chars(s1) + count_line_chars(s2);
    str = malloc((len + 1) * sizeof(char));
    if (!str)
        return NULL;
    start = str;
    while (s1 && *s1)
        *str++ = *s1++;
    while (s2 && *s2)
    {
        // printf("S2: %c\n", *s2);
        *str++ = *s2++;
    }
    *str = '\0';
    return start;
}

char *ft_strdup(char *str)
{
    char *copy;
    int i;

    if (!str)
        str = "";
    copy = malloc(count_line_chars(str) + 1);
    if (!copy)
        return NULL;
    i = 0;
    while (str[i])
    {
        copy[i] = str[i];
        i++;
    }
    copy[i] = '\0';
    return copy;
}

void *ft_memset(void *b, int c, size_t len)
{
    size_t i;
    char *str;

    str = (char *)b;
    i = 0;
    while (i < len)
    {
        str[i] = (unsigned char)c;
        i++;
    }
    return str;
}