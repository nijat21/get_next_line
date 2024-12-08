#include "get_next_line.h"

int count_line_chars(char *str)
{
    int count;

    count = 0;
    while (str[count] && str[count] != '\n')
        count++;
    return count;
}

// int file_end_check(char *str)
// {
//     char temp[BUFFER_SIZE];
//     int temp_count;
// }

char *single_line(char *buffer, int is_end)
{
    char *line;
    int count;
    // int size;
    int i;

    count = count_line_chars(buffer);
    // if (is_end == 1)
    //     size = count;
    // else
    //     size = count + 1;
    line = (char *)malloc((count + 1) * sizeof(char));
    if (!line)
        return NULL;
    i = 0;
    while (i < count)
    {
        line[i] = buffer[i];
        i++;
    }
    if ((buffer[i] = '\n' && is_end) || !is_end)
        line[i] = '\n';
    else if (is_end)
        line[i] = '\0';
    return line;
}