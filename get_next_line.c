#include "get_next_line.h"

// char *next_buff(int fd)
// {
//     static char next_buf[BUFFER_SIZE];
//     int bytes_read;
//     bytes_read = read(fd, next_buf, BUFFER_SIZE);
//     if(bytes_read < )
// }

char *get_next_line(int fd)
{
    static char buf[BUFFER_SIZE];
    static int curr = 0;
    static int bytes_read = 0;
    char *line;
    int is_end = 0;
    // static int temp_end = 0;

    is_end = 0;
    if (!buf[curr])
    {
        bytes_read = read(fd, buf, BUFFER_SIZE);
        if (bytes_read <= 0)
            return NULL;
        else
            is_end = 0;
        buf[bytes_read] = '\0';
        curr = 0;
    }
    if (bytes_read < BUFFER_SIZE)
        is_end = 1;
    line = single_line(&buf[curr], is_end); // "a\n" or "a\0"

    curr += count_line_chars(&buf[curr]);
    if (curr < bytes_read && buf[curr] == '\n') // if buf[curr] = '\0', it's either end of the buffer or the file
        curr++;
    printf("Curr %i bytes_read %i\n", curr, bytes_read);
    // temp_end = is_end;
    return line;
}

// EOF scenarios
// 1. Last buffer is shorter than the BUFFER_SIZE
// 2. Last buffer is exactly the same length as BUFFER_SIZE but read returns 0
