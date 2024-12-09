#include "get_next_line.h"

int count_line_chars(char *str)
{
    int count;

    count = 0;
    while (str[count] && str[count] != '\n')
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
    if (is_end)
        line[i] = '\0';
    else if ((buffer[i] == '\n' && is_end) || !is_end)
        line[i] = '\n';
    return line;
}

// buffer[2] != '\n'