#include "../get_next_line.h"

int main()
{
    int fd = open("texts/text.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Error opening the file");
        return (0);
    }

    printf("First: %s", get_next_line(fd));
    printf("Second: %s", get_next_line(fd));
    printf("Third: %s", get_next_line(fd));
    printf("Fourth: %s", get_next_line(fd));
    printf("Fifth: %s", get_next_line(fd));
}
