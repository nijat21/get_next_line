#include "get_next_line.h"

char *single_line(char *buffer, int count)
{
    char *line;
    int i;

    line = (char *)malloc(count * sizeof(char) + 1);
    if (!line)
        return NULL;
    i = 0;
    while (i < count)
    {
        line[i] = buffer[i];
        i++;
    }
    line[i] = '\n';
    return line;
}

// Reads one line at a call and returns that read line
char *get_next_line(int fd)
{
    static char buf[BUFFER_SIZE];
    static int end;
    ssize_t bytes_read;
    char *line;
    int count;

    // Allocate memory for buf with max count that will be derived from compile flag -D BUFFER_SIZE or default
    end = 0;
    count = count_line_chars(buf);
    if (!count)
    {
        bytes_read = read(fd, &buf, BUFFER_SIZE);
        if (bytes_read <= 0)
            return NULL;
        line = single_line(buf, count);
        if (!line)
            return NULL;
        end = count;
    }
    else
    {
        count = count_line_chars(&buf[end]);
        line = single_line(&buf[end], count);
        if (!line)
            return NULL;
        end = count;
    }
    return line;
}

// ssize_t read(int fd, void *buf, size_t count);

int main()
{
    int fd = open("text.txt", O_RDONLY);
    if (fd == -1)
        return (0);

    printf("First: %s\n", get_next_line(fd));
    for (int i = 0; i < 5; i++)
        printf("%s\n", get_next_line(fd));
}

// RETURN VALUES
// 1. Buffer is longer than the line? Returns a line and delays the next read until the leftover is finished
// 2. Buffer is shorter than the line?
// If nothing to read or error, return NULL
// Undefined behaviour reading binary
