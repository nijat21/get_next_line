#include "get_next_line.h"

// char *single_line(char *buffer)
// {
//     char *line;
//     int count;
//     int i;
//     static int curr = 0;
//     if (buffer[curr] == '\0')
//         curr = 0;
//     count = count_line_chars(&buffer[curr]);
//     line = (char *)malloc((count + 1) * sizeof(char));
//     if (!line)
//         return NULL;
//     i = 0;
//     while (i < count)
//     {
//         line[i] = buffer[i];
//         // printf("BUFF[i]: %c\n", buffer[i]);
//         i++;
//     }
//     line[i] = '\0';
//     curr = count - 1;
//     return line;
// }

static void free_line(char *some_line)
{
    if (some_line)
        free(some_line);
    return;
}

char *get_next_line(int fd)
{
    static char buf[BUFFER_SIZE + 1];
    static int index = 0;
    int stop;
    int bytes_read;
    char *new_line;
    char *check_line;
    char *final_line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    final_line = NULL;
    stop = 0;
    bytes_read = 0;
    while (stop != 1)
    {
        if (!buf[index])
        {
            bytes_read = read(fd, buf, BUFFER_SIZE);
            if (bytes_read == 0)
                break;
            if (bytes_read == -1)
            {
                free_line(final_line);
                return NULL;
            }
            buf[bytes_read] = '\0';
            index = 0;
        }
        else
        {
            new_line = single_line(&buf[index]);
            if (!new_line)
            {
                free_line(final_line);
                break;
            }
            check_line = ft_strjoin(final_line, new_line);
            free_line(final_line);
            free_line(new_line);
            if (!check_line)
                break;
            final_line = ft_strdup(check_line);
            free_line(check_line);
            if (!final_line)
                break;
            index += count_line_chars(&buf[index]) - 1;
            if (buf[index] == '\n')
            {
                index++;
                break;
            }
            index++;
        }
    }
    return final_line;
}