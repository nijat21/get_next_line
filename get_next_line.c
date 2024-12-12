#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char buf[BUFFER_SIZE + 1];
    static int curr = 0;
    static int bytes_read = 0;
    char *line;
    char *temp_line;
    char *final_line;

    final_line = NULL;
    while (bytes_read != -1)
    {
        if (!buf[curr])
        {
            bytes_read = read(fd, buf, BUFFER_SIZE);
            if (bytes_read < 0)
                return NULL;
            else if (bytes_read == 0)
                return final_line;
            buf[bytes_read] = '\0';
            curr = 0;
        }
        line = single_line(&buf[curr]);
        if (!line)
            return NULL;
        temp_line = ft_strjoin(final_line, line);
        if (!temp_line)
            return NULL;
        if (final_line)
            free(final_line);
        free(line);
        final_line = ft_strdup(temp_line);
        if (!final_line)
            return NULL;
        free(temp_line);
        if ((curr < bytes_read && buf[curr] == '\n'))
        {
            curr++;
            return final_line;
        }
        curr += count_line_chars(&buf[curr]);
    }
    return final_line;
}