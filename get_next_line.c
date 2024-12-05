#include "get_next_line.h"

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
    while (i < count)
    {
        line[i] = buffer[i];
        i++;
    }
    return line;
}

// Reads one line at a call and returns that read line
char *get_next_line(int fd)
{
    static char buf[BUFFER_SIZE];
    ssize_t bytes_read;
    char *line;
    int i;
    static char *end;

    // Allocate memory for buf with max count that will be derived from compile flag -D BUFFER_SIZE or default
    bytes_read = read(fd, &buf, BUFFER_SIZE);
    if (bytes_read <= 0)
        return NULL;

    i = 0;
    while (i < bytes_read && buf[i] != '\n')
    {
        line[i] = buf[i];
        i++;
    }
    line[i] = '\n';
    end = &buf[i];
    return line;
}

// ssize_t read(int fd, void *buf, size_t count);

int main()
{
    int fd = open("text.txt", O_RDONLY);
    if (fd == -1)
        return (0);

    printf("%i\n", fd);

    for (int i = 0; i < 5; i++)
        printf("%s\n", get_next_line(fd));
}