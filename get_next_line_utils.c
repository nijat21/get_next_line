#include "get_next_line.h"

int count_line_chars(char *str)
{
    int count;

    count = 0;
    while (str[count] && str[count] != '\n')
        count++;
    return count;
}

char *single_line(char *buffer)
{
    char *line;
    int count;
    int i;

    count = count_line_chars(buffer);
    line = (char *)malloc(count * sizeof(char) + 1);
    if (!line)
        return NULL;
    i = 0;
    while (buffer[i] && buffer[i] != '\n')
    {
        line[i] = buffer[i];
        i++;
    }
    if (buffer[i] == '\0')
        line[i] = '\0';
    line[i] = '\n';
    return line;
}