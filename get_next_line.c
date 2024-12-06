#include "get_next_line.h"

// Reads one line at a call and returns that read line
char *get_next_line(int fd)
{
    static char buf[BUFFER_SIZE];
    static int curr = 0;
    ssize_t bytes_read;
    char *line;

    // Allocate memory for buf with max count that will be derived from compile flag -D BUFFER_SIZE or default;
    if (!buf[curr])
    {
        bytes_read = read(fd, buf, BUFFER_SIZE);
        if (bytes_read <= 0)
            return NULL;
        buf[bytes_read] = '\0';
        curr = 0;
    }
    line = single_line(&buf[curr]);
    curr += count_line_chars(&buf[curr]);
    if (buf[curr] == '\n')
        curr++;
    return line;
}

int main()
{
    int fd = open("text.txt", O_RDONLY);
    if (fd == -1)
        return (0);

    // get_next_line(fd);
    // get_next_line(fd);
    // get_next_line(fd);
    // get_next_line(fd);
    printf("First: %s", get_next_line(fd));
    printf("Second: %s", get_next_line(fd));
    printf("Third: %s", get_next_line(fd));
    printf("Fourth: %s", get_next_line(fd));
    printf("Fifth: %s", get_next_line(fd));
}

// RETURN VALUES
// 1. Buffer is longer than the line? Returns a line and delays the next read until the leftover is finished
// 2. Buffer is shorter than the line?
// If nothing to read or error, return NULL
// Undefined behaviour reading binary
