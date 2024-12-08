#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char buf[BUFFER_SIZE];
    static int curr = 0;
    static int bytes_read = 0;
    char *line;
    int is_end = 0;
    static int temp_end = 0;
    // static char temp[BUFFER_SIZE];
    // static int bytes_read = 0;

    // Allocate memory for buf with max count that will be derived from compile flag -D BUFFER_SIZE or default;
    if (temp_end)
        return NULL;
    is_end = 0;
    if (!buf[curr])
    {
        bytes_read = read(fd, buf, BUFFER_SIZE);
        if (bytes_read < 0)
            return NULL;
        else if (bytes_read == 0)
            is_end = 1;
        else
            is_end = 0;
        if (!is_end)
        {
            buf[bytes_read] = '\0';
            curr = 0;
        }
    }
    if (bytes_read < BUFFER_SIZE)
        is_end = 1;
    line = single_line(&buf[curr], is_end);
    // if (!is_end)
    curr += count_line_chars(&buf[curr]);
    if (curr < bytes_read && buf[curr] == '\n')
        curr++;
    temp_end = is_end;
    return line;
}

// RETURN VALUES
// 1. Buffer is longer than the line? Returns a line and delays the next read until the leftover is finished
// 2. Buffer is shorter than the line?
// If nothing to read or error, return NULL
// Undefined behaviour reading binary
