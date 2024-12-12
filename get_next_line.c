#include "get_next_line.h"

static void free_line(char *some_line)
{
    if (some_line)
        free(some_line);
    return;
}

char *get_next_line(int fd)
{
    static char buf[BUFFER_SIZE + 1];
    static int curr = 0;
    static int bytes_read = 0;
    static char *final_line;
    char *line;
    char *temp_line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    final_line = NULL;
    while (bytes_read != -1)
    {
        if (!buf[curr])
        {
            bytes_read = read(fd, buf, BUFFER_SIZE);
            if (bytes_read < 0)
            {
                free_line(final_line);
                buf[0] = '\0';
                return NULL;
            }
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
        free_line(final_line);
        free(line);
        final_line = ft_strdup(temp_line);
        if (!final_line)
            return NULL;
        free(temp_line);
        curr += count_line_chars(&buf[curr]) - 1;
        if (curr < bytes_read && buf[curr] == '\n')
        {
            curr++;
            return final_line;
        }
        curr++;
    }
    return final_line;
}